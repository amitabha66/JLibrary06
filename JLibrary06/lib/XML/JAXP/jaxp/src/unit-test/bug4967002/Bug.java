/*
 * @(#)$Id: Bug.java,v 1.1 2005/06/10 04:24:46 jeffsuttor Exp $
 * 
 * Copyright 2001 Sun Microsystems, Inc. All Rights Reserved.
 * 
 * This software is the proprietary information of Sun Microsystems, Inc. Use
 * is subject to license terms.
 *  
 */
package bug4967002;

import java.io.StringReader;

import javax.xml.XMLConstants;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.stream.StreamSource;
import javax.xml.validation.Schema;
import javax.xml.validation.SchemaFactory;

import junit.framework.TestCase;
import junit.textui.TestRunner;

import org.xml.sax.InputSource;

/**
 * @author Kohsuke Kawaguchi (kohsuke.kawaguchi@sun.com)
 */
public class Bug extends TestCase {
    public Bug(String name) {
        super(name);
    }

    public static void main(String[] args) {
        TestRunner.run(Bug.class);
    }

    String schemaSource =
        "<?xml version='1.0'?>\n"
            + "<xsd:schema xmlns:xsd='http://www.w3.org/2001/XMLSchema'>\n"
            + "  <xsd:element name='test101'>\n"
            + "    <xsd:complexType>\n"
            + "      <xsd:attribute name='attr'/>\n"
            + "      <xsd:attribute name='attr2' default='DEF'/>\n"
            + "    </xsd:complexType>\n"
            + "  </xsd:element>\n"
            + "</xsd:schema>\n";

    Schema createSchema() {
        SchemaFactory schFactory = SchemaFactory.newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI);
        try {
            Schema sch = schFactory.newSchema(new StreamSource(new StringReader(schemaSource)));
            return sch;
        } catch (Exception se) {
            throw new IllegalStateException("No Schema : " + se);
        }
    }
    
    public void test1() {
        setAttr(true);
    }

    public void test2() {
        setAttr(false);
    }

    void setAttr(boolean setSrc) {
        DocumentBuilderFactory docBFactory = DocumentBuilderFactory.newInstance();
        Schema sch = createSchema();
        docBFactory.setSchema(sch);
        docBFactory.setNamespaceAware(true);
        docBFactory.setValidating(true);

        final String aSchemaLanguage = "http://java.sun.com/xml/jaxp/properties/schemaLanguage";
        final String aSchemaSource = "http://java.sun.com/xml/jaxp/properties/schemaSource";

        docBFactory.setAttribute(aSchemaLanguage, "http://www.w3.org/2001/XMLSchema");
//        System.out.println("---- Set schemaLanguage: " + docBFactory.getAttribute(aSchemaLanguage));
        if (setSrc) {
            docBFactory.setAttribute(aSchemaSource, new InputSource(new StringReader(schemaSource)));
//            System.out.println("---- Set schemaSource: " + docBFactory.getAttribute(aSchemaSource));
        }

        try {
            docBFactory.newDocumentBuilder();
            fail("ParserConfigurationException expected");
        } catch (ParserConfigurationException pce) {
            return; // success
        }
    }
}