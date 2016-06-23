/*
 * @(#)$Id: Bug.java,v 1.1 2005/06/10 04:24:40 jeffsuttor Exp $
 *
 * Copyright 2001 Sun Microsystems, Inc. All Rights Reserved.
 * 
 * This software is the proprietary information of Sun Microsystems, Inc.  
 * Use is subject to license terms.
 * 
 */
package bug4969732;

import java.io.StringReader;

import javax.xml.parsers.SAXParserFactory;
import javax.xml.transform.stream.StreamSource;
import javax.xml.validation.Schema;
import javax.xml.validation.SchemaFactory;
import javax.xml.validation.TypeInfoProvider;
import javax.xml.validation.ValidatorHandler;

import junit.framework.TestCase;
import junit.textui.TestRunner;

import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.XMLReader;
import org.xml.sax.helpers.DefaultHandler;

/**
 * 
 * 
 * @author
 *     Kohsuke Kawaguchi (kohsuke.kawaguchi@sun.com)
 */
public class Bug extends TestCase {
    public Bug(String name) {
        super(name);
    }
    
    public static void main(String[] args) {
        TestRunner.run(Bug.class);
    }

    public static final String XSD = "<?xml version='1.0'?>\n"
    + "<schema xmlns='http://www.w3.org/2001/XMLSchema'\n"
    + "        xmlns:test='jaxp13_test'\n"
    + "        targetNamespace='jaxp13_test'\n"
    + "        elementFormDefault='qualified'>\n"
    + "    <element name='test' type='string'/>\n"
    + "</schema>\n";

    public static final String XML = "<?xml version='1.0'?>\n"
    + "<ns:test xmlns:ns='jaxp13_test'>1234abc</ns:test>\n";

    private ValidatorHandler createValidatorHandler(String xsd) throws SAXException {
        SchemaFactory schemaFactory =
        SchemaFactory.newInstance("http://www.w3.org/2001/XMLSchema");

        StringReader reader = new StringReader(xsd);
        StreamSource xsdSource = new StreamSource(reader);

        Schema schema = schemaFactory.newSchema(xsdSource);
        return schema.newValidatorHandler();
    }

    private XMLReader createXMLReader() throws Exception {
        SAXParserFactory parserFactory = SAXParserFactory.newInstance();
        parserFactory.setNamespaceAware(true);

        return parserFactory.newSAXParser().getXMLReader();
    }

    private void parse(XMLReader xmlReader, String xml) throws Exception {
        StringReader reader = new StringReader(xml);
        InputSource inSource = new InputSource(reader);

        xmlReader.parse(inSource);
    }

    public void test1() throws Exception {
        XMLReader xmlReader = createXMLReader();
        final ValidatorHandler validatorHandler = createValidatorHandler(XSD);
        xmlReader.setContentHandler(validatorHandler);

        DefaultHandler handler = new DefaultHandler() {
            public void characters(char[] ch, int start, int length)
            throws SAXException {
                TypeInfoProvider infoProvider = null;
                synchronized (validatorHandler) {
                    infoProvider = validatorHandler.getTypeInfoProvider();
                }
                if (infoProvider == null) {
                    fail("Can't obtain TypeInfo object.");
                }

                try {
                    infoProvider.getElementTypeInfo();
                    fail("IllegalStateException was not thrown.");
                } catch (IllegalStateException e) {
                    // as expected
                    System.out.println("OK");
                }
            }
        };
        validatorHandler.setContentHandler(handler);

        parse(xmlReader, XML);
    }
   }