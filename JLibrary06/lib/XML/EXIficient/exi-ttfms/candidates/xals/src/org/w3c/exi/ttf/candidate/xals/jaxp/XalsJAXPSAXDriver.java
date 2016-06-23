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

package org.w3c.exi.ttf.candidate.xals.jaxp;

import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.sax.SAXTransformerFactory;
import javax.xml.transform.sax.TransformerHandler;
import javax.xml.transform.stream.StreamResult;

import org.w3c.exi.ttf.SAXDriver;
import org.w3c.exi.ttf.fragments.FragmentsInputStream;
import org.w3c.exi.ttf.parameters.DriverParameters;
import org.w3c.exi.ttf.parameters.PreserveParam;
import org.w3c.exi.ttf.parameters.TestCaseParameters;
import org.xml.sax.ContentHandler;
import org.xml.sax.DTDHandler;
import org.xml.sax.EntityResolver;
import org.xml.sax.ErrorHandler;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.SAXNotRecognizedException;
import org.xml.sax.SAXNotSupportedException;
import org.xml.sax.XMLReader;

import com.fujitsu.xml.xals.sax.SAXParserFactoryImpl;
import com.fujitsu.xml.xals.sax.SAXParserImpl;

/**
 * @author Takuki Kamiya (Fujitsu Computer Systems)
 */
public final class XalsJAXPSAXDriver extends SAXDriver
{
  private final SAXTransformerFactory _stf;
  private XMLReader _reader;

  private final byte[] m_buffer;
  
  public XalsJAXPSAXDriver() {
    super();
    // init writer factory
    _stf = (SAXTransformerFactory)SAXTransformerFactory.newInstance();
    m_buffer = new byte[4096];
  }

  @Override
  protected void prepareTestCase(DriverParameters driverParams, 
          TestCaseParameters testCaseParams)
    throws SAXException, ParserConfigurationException {
    SAXParserFactory parserFactory = new SAXParserFactoryImpl();
    parserFactory.setNamespaceAware(true);
    SAXParser _parser = parserFactory.newSAXParser();
    assert _parser instanceof SAXParserImpl;
    _reader = _parser.getXMLReader();
    if (!testCaseParams.preserves.contains(PreserveParam.dtds)) {
      // Switch of DTD processing
      _reader.setFeature("http://xml.org/sax/features/external-parameter-entities", false);
    }
    // XML processor by itself does not know how to deal with fragments.
    // Using a reader wrapper that will add the FragmentsInputStream wrapper
    if (testCaseParams.fragments)
      _reader = new FragmentsReader(_reader);
  }
  
  /**
   * Override default transcode implementation to preserve exact bytes and size.
   */
  @Override
  public void transcodeTestCase(InputStream xmlInput, OutputStream encodedOutput) 
    throws IOException {
    final byte[] bbuf = m_buffer;
    int bytes;
    while (0 < (bytes = xmlInput.read(bbuf))) {
      encodedOutput.write(bbuf, 0, bytes);
    }
  }
  
  /* (non-Javadoc)
   * @see org.w3c.exi.ttf.EXISAXDriverBase#getXMLReader()
   */
  @Override
  protected final XMLReader getXMLReader()
    throws SAXException {
    return _reader;
  }

  @Override
  protected final ContentHandler getSAXEncoder(OutputStream outputStream)
    throws TransformerConfigurationException {
    TransformerHandler handler = _stf.newTransformerHandler();
    handler.setResult(new StreamResult(outputStream));
    return handler;
  }
  
  ///////////////////////////////////////////////////////////////////////////
  // FragmentsReader for fragment support
  ///////////////////////////////////////////////////////////////////////////
  
  private final static class FragmentsReader implements XMLReader
  {
    private final XMLReader reader;
    
    FragmentsReader(XMLReader reader) {
      this.reader = reader;
    }
    
    public void parse(InputSource input) throws IOException, SAXException {
      InputStream is = input.getByteStream();
      // Only using byte streams in framework.  Check just in case.
      if (is == null)
        throw new SAXException("A byte stream must be supplied");

      is = new FragmentsInputStream(is);
      input.setByteStream(is);
      reader.parse(input);
    }

    public void parse(String systemId) throws IOException, SAXException {
      // TODO: does not add FragmentInputStream wrapper.  This method is not used at this time.
      throw new SAXException("Not implemented");
    }

    public ContentHandler getContentHandler() {
      return reader.getContentHandler();
    }

    public DTDHandler getDTDHandler() {
      return reader.getDTDHandler();
    }

    public EntityResolver getEntityResolver() {
      return reader.getEntityResolver();
    }

    public ErrorHandler getErrorHandler() {
      return reader.getErrorHandler();
    }

    public boolean getFeature(String name) throws SAXNotRecognizedException, SAXNotSupportedException {
      return reader.getFeature(name);
    }

    public Object getProperty(String name) throws SAXNotRecognizedException, SAXNotSupportedException {
      return reader.getProperty(name);
    }

    public void setContentHandler(ContentHandler handler) {
      reader.setContentHandler(handler);
    }

    public void setDTDHandler(DTDHandler handler) {
      reader.setDTDHandler(handler);
    }

    public void setEntityResolver(EntityResolver resolver) {
      reader.setEntityResolver(resolver);
    }

    public void setErrorHandler(ErrorHandler handler) {
      reader.setErrorHandler(handler);
    }

    public void setFeature(String name, boolean value) throws SAXNotRecognizedException, SAXNotSupportedException {
      reader.setFeature(name, value);
    }

    public void setProperty(String name, Object value) throws SAXNotRecognizedException, SAXNotSupportedException {
      reader.setProperty(name, value);
    }
  }
  
}
