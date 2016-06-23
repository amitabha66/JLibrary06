/*
 * EXI Testing Task Force Measurement Suite: http://www.w3.org/XML/EXI/
 *
 * Copyright � [2006] World Wide Web Consortium, (Massachusetts Institute of
 * Technology, European Research Consortium for Informatics and Mathematics,
 * Keio University). All Rights Reserved. This work is distributed under the
 * W3C� Software License [1] in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * [1] http://www.w3.org/Consortium/Legal/2002/copyright-software-20021231
 */

package org.w3c.exi.ttf.candidate.esxml;

import java.io.*;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import javax.xml.transform.sax.SAXTransformerFactory;
import javax.xml.transform.sax.TransformerHandler;
import javax.xml.transform.stream.StreamResult;
import org.w3c.exi.ttf.SAXDriver;

import org.w3c.exi.ttf.parameters.ApplicationClassParam;
import org.w3c.exi.ttf.parameters.DataSourceSinkParam;
import org.w3c.exi.ttf.parameters.DriverParameters;
import org.w3c.exi.ttf.parameters.MeasureParam;
import org.w3c.exi.ttf.parameters.PreserveParam;
import org.w3c.exi.ttf.parameters.TestCaseParameters;
import org.xml.sax.ContentHandler;
import org.xml.sax.XMLReader;

import java.net.*;
import java.util.Set;

import org.esxml.*;
import org.esxml.borrowed.jboss.*;

import com.sun.japex.Params;
import java.nio.Buffer;
import java.nio.ByteBuffer;
import javolution.io.*;

import org.xml.sax.Attributes;
import org.xml.sax.ContentHandler;
import org.xml.sax.DTDHandler;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.XMLReader;
import org.xml.sax.ErrorHandler;
import org.xml.sax.SAXParseException;
import org.xml.sax.ext.DeclHandler;
import org.xml.sax.ext.LexicalHandler;
import org.xml.sax.helpers.DefaultHandler;
import org.w3c.dom.Document;


/**
 * @author Stephen Williams, HPTi / OptimaLogic
 *
 */
public class EsxmlSAXDriver extends SAXDriver {
    org.esxml.SAXReader reader;

    SAXParser _parser;
    SAXTransformerFactory _stf;
//    private TableManager tableManager;
    DriverParameters driverParams;
    private TestCaseParameters params;


    /* (non-Javadoc)
     * @see org.w3c.exi.ttf.EXISAXDriverBase#getXMLReader()
     */
    @Override
	protected XMLReader getXMLReader() throws Exception {
	// System.out.println("Getting esXML reader");
        return reader;
    }

    @Override
	protected ContentHandler getSAXEncoder(OutputStream outputStream) throws Exception {
	// System.out.println("Getting esXML contentHandler");
        return reader.getContentHandler(outputStream);
    }
    Config conf;
    @Override
    protected void prepareTestCase(DriverParameters driverParams_,
				   TestCaseParameters testCaseParams)
	throws Exception {
	driverParams = driverParams_;
        params = testCaseParams;

        reader = new org.esxml.SAXReader();
        /* 
        driverParams.isDocumentAnalysing;
        driverParams.isSchemaOptimizing;
        driverParams.isStringInterning;
        testCaseParams.fragments;
        testCaseParams.preserves;
        testCaseParams.schemaDeviations;
        */
        conf = new Config();
        conf.inputFile = testCaseParams.xmlFile;
        conf.preserve = TestCaseParameters.PRESERVE; // "comments"
        conf.schemaLocation = testCaseParams.schemaLocation;
        conf.isDocumentAnalysing = driverParams.isDocumentAnalysing;
        conf.isSchemaOptimizing = driverParams.isSchemaOptimizing;
        conf.isStringInterning = driverParams.isStringInterning;
        conf.fragments = testCaseParams.fragments;
        conf.fidelity = testCaseParams.preserves;
        if (EsXML.debug) {
            System.out.printf("xmlFile: %s\n", testCaseParams.xmlFile);
        }
        
        if (driverParams.isSchemaOptimizing) {
            String schemaLocation = testCaseParams.schemaLocation;

            if (schemaLocation != null) {
        	if (EsXML.debug) {
        	    System.out.println("Found schema: " + schemaLocation);
        	}
        	conf.dir = System.getProperty("user.dir");
		 // tableManager = new TableManager(new URL("file:///"+dir+"/"+
			//				 schemaLocation));
            } else if (EsXML.debug) {
                System.out.println("Schema optimizing but not found");
            }
        }

	// driverParams:
        // APPLICATION_CLASS
	// APPLICATION_CLASS_DOCUMENT_ANALYSING_GZIP
	// MEASURE
	// DRIVER_IS_XML_PROCESSOR
	// STRING_INTERNING 
	// DATA_SOURCE_SINK_URI 
	// params
	// applicationClass
	// measure
	// isDocumentAnalysing
	// isDocumentAnalysingUsingGZIP
	// isSchemaOptimizing
	// isXmlProcessor
	// isStringInterning
	// dataSourceSinkURI
	// dataSourceSink

	// testCaseParams:
        // INPUT_FILE
        // PARAM_RECORDDECODEDEVENTS 
        // PRESERVE
        // IGNORE_FIDELITY_SETTINGS
        // SCHEMA_LOCATION
        // USE_CASES
        // SCHEMA_DEVIATIONS
        // FRAGMENTS
        // preserves
        // ignoreFidelitySettings
        // schemaLocation
        // xmlFile
        // xmlSystemId
        // traceRead
        // schemaDeviations
        // fragments

    }

    @Override
    protected void transcodeTestCase (InputStream xmlInput,
				      OutputStream encodedOutput)
	throws Exception {
	if (EsXML.debug) {
	    System.out.println("transcode: " + params.xmlFile);
	}
        try {
            // if (tableManager == null) {
                //System.out.println("No schema, not encoding");
               // return;
            // }
            Encoder enc = new Encoder(xmlInput, conf);
            enc.setCompressionMethod(EsXML.comp_smallest);
            DataOutputStream dos = new DataOutputStream(encodedOutput);
            enc.encode(dos);
            // System.out.printf("hi\n");
	    // DocumentWriter dw = new DocumentWriter(tableManager, xmlInput);
            // dw.setCompressionMethod(CompType.SMALLEST);
            // DataOutputStream dos = new DataOutputStream(encodedOutput);
            // dw.serialize(dos);
        } catch(Exception e) {
            e.printStackTrace();
            return;
        }

        // _parser.setContentHandler(getSAXEncoder(encodedOutput));
        // _parser.parse(new InputSource(xmlInput));
    }

 
}
