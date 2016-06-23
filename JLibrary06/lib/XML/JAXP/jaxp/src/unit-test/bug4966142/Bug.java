/*
 * @(#)$Id: Bug.java,v 1.1 2005/06/10 04:23:51 jeffsuttor Exp $
 *
 * Copyright 2001 Sun Microsystems, Inc. All Rights Reserved.
 * 
 * This software is the proprietary information of Sun Microsystems, Inc.  
 * Use is subject to license terms.
 * 
 */
package bug4966142;

import javax.xml.XMLConstants;
import javax.xml.parsers.DocumentBuilderFactory;

import junit.framework.TestCase;
import junit.textui.TestRunner;

import org.w3c.dom.Document;
import org.w3c.dom.TypeInfo;

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
    
    static final String SCHEMA_LANGUAGE = "http://java.sun.com/xml/jaxp/properties/schemaLanguage";
    static final String SCHEMA_SOURCE =  "http://java.sun.com/xml/jaxp/properties/schemaSource";

    

    public void test1() throws Exception {
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        dbf.setNamespaceAware(true);
        dbf.setValidating(true);    
        dbf.setAttribute(SCHEMA_LANGUAGE, XMLConstants.W3C_XML_SCHEMA_NS_URI);
        dbf.setAttribute(SCHEMA_SOURCE, Bug.class.getResource("test.xsd").toExternalForm());

        Document document = dbf.newDocumentBuilder().parse(
            Bug.class.getResource("test.xml").toExternalForm());

        TypeInfo type = document.getDocumentElement().getSchemaTypeInfo();

        assertFalse(type.isDerivedFrom("testNS", "Test", TypeInfo.DERIVATION_UNION));
    }
}