/*
 * EXI Testing Task Force Measurement Suite: http://www.w3.org/XML/EXI/
 *
 * Copyright ? [2006] World Wide Web Consortium, (Massachusetts Institute of
 * Technology, European Research Consortium for Informatics and Mathematics,
 * Keio University). All Rights Reserved. This work is distributed under the
 * W3C? Software License [1] in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * [1] http://www.w3.org/Consortium/Legal/2002/copyright-software-20021231
 */

package org.w3c.exi.ttf.candidate.xebu;

import java.io.File;
import java.io.FileReader;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.FileOutputStream;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.xml.sax.ContentHandler;
import org.xml.sax.XMLReader;
import org.xml.sax.InputSource;
import org.xml.sax.helpers.XMLReaderFactory;
import org.xml.sax.helpers.DefaultHandler;
import org.w3c.dom.Document;

import org.w3c.exi.ttf.SAXDriver;
import org.w3c.exi.ttf.fragments.FragmentsInputStream;
import org.w3c.exi.ttf.fragments.FragmentsSAXHandler;
import org.w3c.exi.ttf.parameters.DriverParameters;
import org.w3c.exi.ttf.parameters.TestCaseParameters;

import fi.hiit.fuegocore.util.xas.SaxWriter;
import fi.hiit.fuegocore.util.xas.EventSequence;
import fi.hiit.fuegocore.util.xas.XasUtil;
import fi.hiit.fuegocore.util.xas.XasExtUtil;
import fi.hiit.fuegocore.message.encoding.XebuParser;
import fi.hiit.fuegocore.message.encoding.XebuSaxReader;
import fi.hiit.fuegocore.message.encoding.XebuSerializer;
import fi.hiit.fuegocore.message.encoding.CachePair;
import fi.hiit.fuegocore.message.encoding.DoaMachine;
import fi.hiit.fuegocore.message.encoding.EoaMachine;
import fi.hiit.fuegocore.message.encoding.XebuConstants;
import fi.hiit.fuegocore.message.encoding.coa.ReaderCoaMachine;

/**
 * @author Jaakko Kangasharju (Helsinki Institute for Information
 * Technology)
 */
public class XebuSAXDriver extends SAXDriver {

    private static int count = 0;

    private static final String JAXP_SCHEMA_LANGUAGE
	= "http://java.sun.com/xml/jaxp/properties/schemaLanguage";
    private static final String JAXP_SCHEMA_SOURCE
	= "http://java.sun.com/xml/jaxp/properties/schemaSource";
    private static final String XML_SCHEMA
	= "http://www.w3.org/2001/XMLSchema";

    private ReaderCoaMachine rcm = null;
    private boolean hasSchema = false;
    private boolean hasFragments = false;
    private DocumentBuilderFactory dbf = null;
    private String schema = null;
    private String systemId = null;
    private FidelityFilter filter = null;
    
    private XebuSerializer getXebuSerializer (OutputStream output) {
	XebuSerializer ser = new XebuSerializer();
	ser.setOutput(output, "UTF-8");
	if (rcm != null) {
	    CachePair pair = rcm.createNewPair();
	    ser.setProperty(XebuConstants.PROPERTY_INITIAL_CACHES,
			    pair.getOutCache());
	    EoaMachine eoa = rcm.createNewEoa();
	    if (!eoa.isIdentity()) {
		ser.setProperty(XebuConstants.PROPERTY_COA_MACHINE, eoa);
	    }
	}
	return ser;
    }

    private XebuParser getXebuParser () {
	XebuParser par = new XebuParser();
	if (rcm != null) {
	    CachePair pair = rcm.createNewPair();
	    par.setProperty(XebuConstants.PROPERTY_INITIAL_CACHES,
			    pair.getInCache());
	    DoaMachine doa = rcm.createNewDoa();
	    if (!doa.isIdentity()) {
		par.setProperty(XebuConstants.PROPERTY_COA_MACHINE, doa);
	    }
	}
	return par;
    }

    @Override
    protected void prepareTestCase (DriverParameters driverParameters,
				    TestCaseParameters testCaseParameters)
	throws Exception {
	if (driverParameters.isSchemaOptimizing) {
	    schema = testCaseParameters.schemaLocation;
	    if (schema != null) {
		hasSchema = true;
		dbf = DocumentBuilderFactory.newInstance();
		dbf.setNamespaceAware(true);
		dbf.setValidating(true);
		if (schema.endsWith(".xsd")) {
		    dbf.setAttribute(JAXP_SCHEMA_LANGUAGE, XML_SCHEMA);
		    dbf.setAttribute(JAXP_SCHEMA_SOURCE, new File(schema));
		    File tokFile = new File(schema.replaceAll("xsd$", "tok"));
		    if (tokFile.exists()) {
			rcm = new ReaderCoaMachine(new FileReader(tokFile));
		    }
		}
	    }
	}
	hasFragments = testCaseParameters.fragments;
	systemId = testCaseParameters.xmlSystemId;
	filter = new FidelityFilter(testCaseParameters.preserves);
    }

    @Override
    protected void transcodeTestCase (InputStream xmlInput,
				      OutputStream encodedOutput)
	throws Exception {
	if (hasFragments) {
	    xmlInput = new FragmentsInputStream(xmlInput);
	}
	/*
	if (hasSchema) {
	    DocumentBuilder builder = dbf.newDocumentBuilder();
	    builder.setErrorHandler(new DefaultHandler());
	    Document document = systemId != null
		? builder.parse(xmlInput, systemId)
		: builder.parse(xmlInput);
	    EventSequence es = XasExtUtil.domToSequence(document);
	    XasUtil.outputSequence(es, getXebuSerializer(encodedOutput));
	} else {
	*/
	    XMLReader parser = XMLReaderFactory.createXMLReader();
	    parser.setFeature("http://apache.org/xml/features/nonvalidating/load-external-dtd", false);
	    SaxWriter writer = new SaxWriter(getXebuSerializer(encodedOutput));
	    if (hasFragments) {
		FragmentsSAXHandler handler = new FragmentsSAXHandler(writer);
		filter.setContentHandler(handler);
		filter.setLexicalHandler(handler);
	    } else {
		filter.setContentHandler(writer);
		filter.setLexicalHandler(writer);
	    }
	    filter.register(parser);
	    InputSource is = new InputSource(xmlInput);
	    if (systemId != null) {
		is.setSystemId(systemId);
	    }
	    parser.parse(is);
	    /*
	}
	    */
    }

    @Override
    protected ContentHandler getSAXEncoder (OutputStream output)
	throws Exception {
	XebuSerializer ser = getXebuSerializer(output);
	SaxWriter writer = new SaxWriter(ser);
	filter.setContentHandler(writer);
	filter.setLexicalHandler(writer);
	return filter;
    }

    @Override
    public XMLReader getXMLReader () {
	XebuParser par = getXebuParser();
	return new XebuSaxReader(par);
    }

}
