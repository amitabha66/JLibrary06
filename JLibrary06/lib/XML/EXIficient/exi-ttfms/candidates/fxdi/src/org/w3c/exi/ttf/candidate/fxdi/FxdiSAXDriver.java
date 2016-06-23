/*
 * EXI Testing Task Force Measurement Suite: http://www.w3.org/XML/EXI/
 *
 * Copyright © [2006] World Wide Web Consortium, (Massachusetts Institute of
 * Technology, European Research Consortium for Informatics and Mathematics,
 * Keio University). All Rights Reserved. This work is distributed under the
 * W3C® Software License [1] in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * [1] http://www.w3.org/Consortium/Legal/2002/copyright-software-20021231
 */

package org.w3c.exi.ttf.candidate.fxdi;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.IOException;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.URI;

import org.xml.sax.SAXException;

import javax.xml.parsers.SAXParserFactory;

import org.w3c.exi.ttf.SAXDriver;

import org.w3c.exi.ttf.parameters.DriverParameters;
import org.w3c.exi.ttf.parameters.PreserveParam;
import org.w3c.exi.ttf.parameters.TestCaseParameters;
import org.w3c.exi.ttf.fragments.FragmentsInputStream;
import org.xml.sax.ContentHandler;
import org.xml.sax.InputSource;
import org.xml.sax.XMLReader;

import com.fujitsu.xml.common.URIHelper;
import com.fujitsu.xml.xsc.XdiFidelityOptions;
import com.fujitsu.xml.xsc.SchemaCompiler;
import com.fujitsu.xml.xsc.SchemaCorpus;
import com.fujitsu.xml.xsc.SchemaCompilerErrorHandler;
import com.fujitsu.xml.xsc.SchemaCompilerException;
import com.fujitsu.xml.xsc.VanillaSchema;
import com.fujitsu.xml.xsc.Version;
import com.fujitsu.xml.xsc.XdiProcessorErrorHandler;
import com.fujitsu.xml.xsc.XdiProcessorException;
import com.fujitsu.xml.xsc.XdiStreamSimpleEncoder;
import com.fujitsu.xml.xsc.xdidecoder.XdiDecoder;
import com.sun.japex.TestCase;

/**
 * @author Takuki Kamiya (Fujitsu Computer Systems)
 */
abstract class FxdiSAXDriver extends SAXDriver
{
  private final SchemaCompiler m_schemaCompiler;
  private final SchemaCompilerErrorMonitor m_schemaCompilerErrorMonitor;
  private final XdiProcessorErrorMonitor m_xdiProcessorErrorMonitor;

  private static final byte[] m_vanillaSchema; 

  private boolean m_debug;
  private SchemaCorpus m_corpus;
  private byte[] m_xdiSchema; 
  private URI m_xmlURI; 
  private boolean m_useSchema;
  private XdiFidelityOptions m_fidelityOptions;

  private boolean m_fragmentSupport;
  private boolean m_schemaDeviations;
  
  private PrintStream m_printStream; 
 
  private static final String DEBUG_FXDI = "org.w3c.exi.ttf.candidate.fxdi.debug";

  private static final String FXDI_LOGS = "org.w3c.exi.ttf.candidate.fxdi.logs";

  private XdiStreamSimpleEncoder m_streamEncoder;
  private XdiStreamSimpleEncoder.XdiEncoderSaxHandler m_saxEncoder;
  private XdiDecoder m_decoder;
  
  static {
    ByteArrayOutputStream baos = new ByteArrayOutputStream();
    try {
    VanillaSchema.getSchemaCorpus().writeXDISchema(baos);
    baos.close();
    }
    catch (IOException ioe) {
      throw new RuntimeException(ioe);
    }
    m_vanillaSchema = baos.toByteArray();
  }

  protected void initializeParserFactory(SAXParserFactory spf) throws Exception  {
    super.initializeParserFactory(spf);
//    spf.setFeature("http://xml.org/sax/features/namespace-prefixes", true);
  }

  protected FxdiSAXDriver() {
    super();
    m_debug = false;
    m_schemaCompiler = new SchemaCompiler();
    m_schemaCompilerErrorMonitor = new SchemaCompilerErrorMonitor(false);
    m_xdiProcessorErrorMonitor = new XdiProcessorErrorMonitor(false);
    
    final String cname = getClass().getName();
    final String expectedVersion = cname.substring(cname.indexOf('_') + 1).replace('_', '.');
    if (!Version.getVersion().equals(expectedVersion)) {
      throw new RuntimeException(
        "The FXDI version in use is '" + Version.getVersion() + "'.\n" +
        "Please make sure to use FXDI implementation of version '" + expectedVersion + "'.");
    }
  }

  @Override
  protected final void prepareTestCase(DriverParameters driverParams,
                                       TestCaseParameters testCaseParams)
    throws Exception {
    
    m_debug = driverParams.params.getBooleanParam(DEBUG_FXDI);

    boolean includeDTDWords = false;
    m_fidelityOptions = new XdiFidelityOptions(XdiFidelityOptions.FIDELITY_MIMIMUM);
    for (PreserveParam param : testCaseParams.preserves) {
      switch (param) {
        case comments:
          m_fidelityOptions.setPreserveComments(true);
          break;
        case notations:
          m_fidelityOptions.setPreserveNotations(true);
          break;
        case pis:
          m_fidelityOptions.setPreservePIs(true);
          break;
        case prefixes:
          m_fidelityOptions.setPreserveNSDecls(true);
          break;
        case whitespace:
          m_fidelityOptions.setPreserveWhitespaces(true);
          break;
        case dtds:
          m_fidelityOptions.setPreserveDTD(true);
          includeDTDWords = true;
          break;
        // REVISIT: add support, entityreferences and lexicalvalues
      }
    }
    m_fidelityOptions.setPreserveSchemaLocations(true);

    m_fragmentSupport = testCaseParams.fragments;
    
    if (m_printStream != null) {
      // supposed to be closed in finish(), but just in case here as well. 
      m_printStream.close();
      m_printStream = null;
    }
    if (m_debug) {
      final OutputStream outputStream;
      outputStream = new FileOutputStream(driverParams.params.getParam(FXDI_LOGS), true);
      m_printStream = new PrintStream(outputStream);
      m_printStream.println("***** Test Case: " + testCaseParams.xmlFile + " *****");
    }

    URI baseURI = new File(System.getProperty("user.dir")).toURI().resolve("whatever");
    m_xmlURI = URIHelper.resolveURI(URIHelper.escapeURI(testCaseParams.xmlFile), baseURI);

    SchemaCorpus corpus = null;
    try {
      if (m_useSchema = driverParams.isSchemaOptimizing) {
        String schemaLocation = testCaseParams.schemaLocation;
        if (schemaLocation != null) {
          URI schemaURI = URIHelper.resolveURI(schemaLocation, baseURI);
          assert schemaURI != null;
          if (m_debug) {
            m_printStream.println("[prepareTestCase] schemaURI=" + schemaURI.toString());
          }
          if (schemaURI.toString().endsWith("autoschema.xsd")) {
            // fake schema, which is not worth processing.
            m_useSchema = false;
          }
          else {
            if (m_corpus != null && m_corpus.getFragmentSupport() == m_fragmentSupport) {
              int schema = m_corpus.getSchema(0);
              String targetNamespace = m_corpus.getTargetNamespaceOfSchema(schema);
              int tns = m_corpus.getNamespaceOfSchema(schema, targetNamespace);
              int i, len;
              for (i = 0, len = m_corpus.getSystemIdCountOfNamespace(tns); i < len; i++) {
                String ith = m_corpus.getSystemIdOfNamespace(tns, i);
                if (schemaURI.toString().equals(ith)) {
                  if (m_debug) {
                    m_printStream.println("[prepareTestCase] reusing the currently loaded schema.");
                  }
                  corpus = m_corpus;
                  break;
                }
              }
            }
            if (corpus == null) {
              int lastPos = schemaURI.toString().lastIndexOf('/');
              String schemaName = schemaURI.toString().substring(lastPos + 1);
              String baseName;
              baseName = schemaName;
              URI xscURI;
              URI xdiURI;
              if ((lastPos = schemaName.lastIndexOf('.')) > 0) {
                baseName = schemaName.substring(0, lastPos);
              }
              xscURI = schemaURI.resolve(baseName + ".fxdiSchema");
              xdiURI = schemaURI.resolve(baseName + ".fxdi");
              File xscFile, xdiFile;
              xdiFile = new File(xdiURI);
              if ((xscFile = new File(xscURI)).exists()) {
                InputStream is = xscFile.toURL().openStream();
                ObjectInputStream ois = null;
                corpus = null;
                try {
                  ois = new ObjectInputStream(is);
                  corpus = (SchemaCorpus)ois.readObject();
                }
                finally {
                  if (ois != null) ois.close();
                  if (is != null) is.close();
                }
                if (corpus.getFragmentSupport() == m_fragmentSupport) {
                  m_xdiSchema = new byte[(int)xdiFile.length()];
                  try {
                    is = xdiFile.toURL().openStream();
                    for (int pos = 0; pos < m_xdiSchema.length;) {
                      int count;
                      if ((count = is.read(m_xdiSchema, pos, m_xdiSchema.length - pos)) < 0) {
                        throw new IOException("Failed to read FXDI Schema '" + xdiFile.getName() + "'.");
                      }
                      pos += count;
                    }
                  }
                  finally {
                    if (is != null) is.close();
                  }
                }
                else
                  corpus = null;
                if (m_debug) {
                  m_printStream.println("[prepareTestCase] loading compiled schema: " + xscURI.toString());
                }
              }
              if (corpus == null) {
                InputSource inputSource = new InputSource(schemaURI.toString());
                if (m_debug) {
                  m_printStream.println("[prepareTestCase] compiling schema: " + schemaURI.toString());
                  m_schemaCompiler.setCompilerErrorHandler(m_schemaCompilerErrorMonitor);
                }
                else {
                  m_schemaCompiler.setCompilerErrorHandler(null);
                }
                corpus = m_schemaCompiler.compile(inputSource, m_fragmentSupport);
                FileOutputStream fos = new FileOutputStream(xscFile);
                ObjectOutputStream oos = new ObjectOutputStream(fos);
                oos.writeObject(corpus);
                oos.flush();
                fos.flush();
                oos.close();
                fos.close();
                fos = new FileOutputStream(xdiFile);
                corpus.writeXDISchema(fos);
                fos.close();
                m_xdiSchema = new byte[(int)xdiFile.length()];
                InputStream is = null;
                try {
                  is = xdiFile.toURL().openStream();
                  for (int pos = 0; pos < m_xdiSchema.length;) {
                    int count;
                    if ((count = is.read(m_xdiSchema, pos, m_xdiSchema.length - pos)) < 0) {
                      throw new IOException("Failed to read FXDI Schema '" + xdiFile.getName() + "'.");
                    }
                    pos += count;
                  }
                }
                finally {
                  if (is != null) is.close();
                }
              }
            }
          }
        }
        else {
          // No schema in "schema" or "both" mode.
          if (m_debug) {
            m_printStream.println("[prepareTestCase] schema is missing: " + testCaseParams.xmlFile);
          }
          switch (driverParams.applicationClass) {
            case schema:
              System.err.println(
                  "Schema *must* be specified for '" +
                  testCaseParams.xmlFile +
                  "' when running in \"schema\" application mode.");
              break;
            case both:
              System.err.println(
                  "Schema *must* be specified for '" +
                  testCaseParams.xmlFile + "'" +
                  "when running in \"both\" application mode.");
              break;
          }
          m_useSchema = false;
        }
      }
    }
    finally {
      boolean schemaDeviations = testCaseParams.schemaDeviations;
      m_corpus = corpus;
      if (m_corpus != null) {
        int schema = m_corpus.getSchema(0);
        String targetNamespace = m_corpus.getTargetNamespaceOfSchema(schema);
        if (schemaDeviations) {
          /**
           * NOTE: Only those kind of deviations found in the following test cases
           * are deviations that need to be treated to be as such by FXDI. 
           * - OpenOffice, XAL, deviations
           * Other types of deviations are not really deviations for FXDI.
           */
          if (!"urn:oasis:names:tc:opendocument:xmlns:office:1.0".equals(targetNamespace) &&
              !testCaseParams.schemaLocation.endsWith("xdxf.xsd") &&
              !testCaseParams.schemaLocation.contains("deviations")) {
            schemaDeviations = false;
          }
        }
      }
      m_schemaDeviations = schemaDeviations;
    }
    m_streamEncoder = getXdiEncoder();
    m_streamEncoder.setIncludeDTDWords(includeDTDWords);
    m_streamEncoder.setSchemaDeviations(m_schemaDeviations);
    m_saxEncoder = m_streamEncoder.getSAXEncoder(false, m_fidelityOptions, m_fragmentSupport);
    m_decoder = getXdiDecoder();
    m_decoder.setIncludeDTDWords(includeDTDWords);
    m_decoder.setPreserveNSDecls(m_fidelityOptions.isPreserveNSDecls());
    m_decoder.setSchemaDeviations(m_schemaDeviations);
  }

  @Override
  public final void finish(TestCase testCase) {
    super.finish(testCase);
    if (m_printStream != null) {
      m_printStream.close();
      m_printStream = null;
    }
  }
    
  /**
   * Override default transcode implementation to preserve exact bytes and size.
   * Round-tripping through JAXP writer seems to expand empty element tags,
   * among other things which change the size.
   */
  @Override
  public final void transcodeTestCase(InputStream xmlInput, OutputStream encodedOutput) 
    throws Exception {
    if (m_debug) {
      m_printStream.println("[transcodeTestCase] m_useSchema=" + m_useSchema);
    }
    
    if (m_fragmentSupport) {
      xmlInput = new FragmentsInputStream(xmlInput);
    }
    
    if (m_corpus != null || !m_useSchema) {
      // REVISIT: add support for fragments in XdiStreamEncoder.
      XdiStreamSimpleEncoder streamEncoder = new XdiStreamSimpleEncoder(m_useSchema);
      if (m_useSchema) {
        streamEncoder.setSchemaCorpus(m_corpus);
      }
      assert m_fidelityOptions != null;
      if (m_debug) {
        streamEncoder.setErrorHandler(m_xdiProcessorErrorMonitor);
        // REVISIT: add support for fragments in XdiStreamEncoder.
//        streamEncoder.setValidatingStructure(true);
//        streamEncoder.setValidatingValues(true);
      }
      else {
        streamEncoder.setErrorHandler((XdiProcessorErrorHandler)null);
      }
      InputSource inputSource = new InputSource(xmlInput);
      inputSource.setSystemId(m_xmlURI.toString());
      streamEncoder.setOutputStream(encodedOutput);
      if (m_fidelityOptions.isPreserveDTD())
        streamEncoder.setIncludeDTDWords(true);
      streamEncoder.setSchemaDeviations(m_schemaDeviations);
      if (m_fragmentSupport)
        streamEncoder.setVirtualRootSupport(true);
      streamEncoder.encode(inputSource, false, m_fidelityOptions, m_fragmentSupport);
    }
    else {
      // REVISIT: no schema for "schema" or "both" category.
    }
  }
    
  /* (non-Javadoc)
   * @see org.w3c.exi.ttf.EXISAXDriverBase#getXMLReader()
   */
  @Override
  protected final XMLReader getXMLReader() throws Exception {
    return m_decoder;
  }

  private final XdiDecoder getXdiDecoder() throws Exception {
    if (m_debug) {
      m_printStream.println("[getXdiDecoder] m_useSchema=" + m_useSchema);
    }
    XdiDecoder decoder = new XdiDecoder();
    if (m_corpus != null || !m_useSchema) {
      if (m_useSchema) {
        decoder.loadXDISchema(new ByteArrayInputStream(m_xdiSchema));
      }
      else {
        decoder.loadXDISchema(new ByteArrayInputStream(m_vanillaSchema));
      }
    }
    return decoder;
  }
  
  @Override
  protected final ContentHandler getSAXEncoder(OutputStream outputStream)
    throws Exception {
    m_streamEncoder.setOutputStream(outputStream);
    return m_saxEncoder;
  }

  private final XdiStreamSimpleEncoder getXdiEncoder()
    throws Exception {
    if (m_debug) {
      m_printStream.println("[getXdiEncoder] m_useSchema=" + m_useSchema);
    }
    // REVISIT: any possibility to reuse the encoder?
    XdiStreamSimpleEncoder streamEncoder;
    if (m_corpus != null || !m_useSchema) {
      streamEncoder = new XdiStreamSimpleEncoder(m_useSchema);
      if (m_useSchema) {
        streamEncoder.setSchemaCorpus(m_corpus);
      }
    }
    else { // no schema for "schema" or "both" category.
      streamEncoder = new XdiStreamSimpleEncoder(false);
    }
  
    assert m_fidelityOptions != null;
    if (m_debug) {
      streamEncoder.setErrorHandler(m_xdiProcessorErrorMonitor);
    }
    else {
      streamEncoder.setErrorHandler((XdiProcessorErrorHandler)null);
    }
    return streamEncoder;
  }

  private final class SchemaCompilerErrorMonitor implements SchemaCompilerErrorHandler {

    private final boolean m_dothrow;

    SchemaCompilerErrorMonitor(boolean doThrow) {
      m_dothrow = doThrow;
    }
    
    public void warning(SchemaCompilerException exc)
      throws SchemaCompilerException {
      if (m_printStream != null) {
        m_printStream.println("[SchemaCompiler:W] " + exc.getMessage());
      }
    }

    public void error(SchemaCompilerException exc)
      throws SchemaCompilerException {
      if (m_printStream != null) {
        m_printStream.println("[SchemaCompiler:E] " + exc.getMessage());
      }
      if (m_dothrow)
        throw exc;
    }

    public void fatalError(SchemaCompilerException exc)
      throws SchemaCompilerException {
      if (m_printStream != null) {
        m_printStream.println("[SchemaCompiler:F] " + exc.getMessage());
      }
      if (m_dothrow)
        throw exc;
    }
  }

  private final class XdiProcessorErrorMonitor implements XdiProcessorErrorHandler {

    private final boolean m_dothrow;

    XdiProcessorErrorMonitor(boolean doThrow) {
      m_dothrow = doThrow;
    }
    
    public void warning(XdiProcessorException exc)
      throws XdiProcessorException {
      if (m_printStream != null) {
        m_printStream.println("[XdiProcessor:W] " + exc.getMessage());
      }
    }

    public void error(XdiProcessorException exc)
      throws XdiProcessorException {
      if (m_printStream != null) {
        m_printStream.println("[XdiProcessor:E] " + exc.getMessage());
      }
      if (m_dothrow)
        throw exc;
    }

    public void fatalError(XdiProcessorException exc)
      throws XdiProcessorException {
      if (m_printStream != null) {
        m_printStream.println("[XdiProcessor:F] " + exc.getMessage());
      }
      if (m_dothrow)
        throw exc;
    }
  }
  
}
