/*
 * @(#)$Id: Bug.java,v 1.1 2005/06/10 04:25:02 jeffsuttor Exp $
 *
 * Copyright 2001 Sun Microsystems, Inc. All Rights Reserved.
 * 
 * This software is the proprietary information of Sun Microsystems, Inc.  
 * Use is subject to license terms.
 * 
 */
package bug4969042;

import java.io.IOException;
import java.io.StringReader;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParserFactory;
import javax.xml.transform.stream.StreamSource;
import javax.xml.validation.Schema;
import javax.xml.validation.SchemaFactory;
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
    + "    <element name='test'>\n"
    + "        <complexType>\n"
    + "            <sequence>\n"
    + "                <element name='child' type='string'/>\n"
    + "            </sequence>\n"
    + "        </complexType>\n"
    + "    </element>\n"
    + "</schema>\n";

    public static final String XML = "<?xml version='1.0'?>\n"
    + "<ns:test xmlns:ns='jaxp13_test'>\n"
    + "  <ns:child>\n"
    + "      123abc\n"
    + "  </ns:child>\n"
    + "</ns:test>\n";


    private ValidatorHandler createValidatorHandler(String xsd) throws SAXException {
        SchemaFactory schemaFactory =
        SchemaFactory.newInstance("http://www.w3.org/2001/XMLSchema");

        StringReader reader = new StringReader(xsd);
        StreamSource xsdSource = new StreamSource(reader);

        Schema schema = schemaFactory.newSchema(xsdSource);
        return schema.newValidatorHandler();
    }

    private XMLReader createXMLReader() throws ParserConfigurationException, SAXException {
        SAXParserFactory parserFactory = SAXParserFactory.newInstance();
        if (!parserFactory.isNamespaceAware()) {
            parserFactory.setNamespaceAware(true);
        }

        return parserFactory.newSAXParser().getXMLReader();
    }

    private void parse(XMLReader xmlReader, String xml) throws SAXException, IOException {
        StringReader reader = new StringReader(xml);
        InputSource inSource = new InputSource(reader);

        xmlReader.parse(inSource);
    }

    public void test() throws SAXException, ParserConfigurationException, IOException {
        XMLReader xmlReader = createXMLReader();
        ValidatorHandler validatorHandler = createValidatorHandler(XSD);
        xmlReader.setContentHandler(validatorHandler);

        final boolean[] invoked  = {false,false};
        DefaultHandler contentHandler = new DefaultHandler() {
            public void ignorableWhitespace(char[] ch, int start, int length) throws SAXException {
                invoked[0] = true;
            }
            public void characters(char[] ch, int start, int length) throws SAXException {
                invoked[1] = true;
            }
           };
        validatorHandler.setContentHandler(contentHandler);

        parse(xmlReader, XML);

        assertTrue( "Method ignorableWhitespace() was not invoked.", invoked[0] );
        assertTrue( "Method characters() was not invoked.", invoked[1] );
       }
}