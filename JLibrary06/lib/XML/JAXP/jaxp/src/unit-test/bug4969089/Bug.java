/*
 * @(#)$Id: Bug.java,v 1.1 2005/06/10 04:24:11 jeffsuttor Exp $
 *
 * Copyright 2001 Sun Microsystems, Inc. All Rights Reserved.
 * 
 * This software is the proprietary information of Sun Microsystems, Inc.  
 * Use is subject to license terms.
 * 
 */
package bug4969089;

import java.io.StringReader;

import javax.xml.transform.Source;
import javax.xml.transform.stream.StreamSource;
import javax.xml.validation.SchemaFactory;

import junit.framework.TestCase;
import junit.textui.TestRunner;

import org.xml.sax.SAXException;
import org.xml.sax.SAXParseException;
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
    
    public void test1() {
        String xsd1 = "<?xml version='1.0'?>\n"
        + "<schema xmlns='http://www.w3.org/2001/XMLSchema'\n"
        + "        xmlns:test='jaxp13_test1'\n"
        + "        targetNamespace='jaxp13_test1'\n"
        + "        elementFormDefault='qualified'>\n"
        + "    <element name='test'>\n"
        + "</schema>\n";

        final SAXException EUREKA = new SAXException("NewSchema007");
        SchemaFactory schemaFactory =
        SchemaFactory.newInstance("http://www.w3.org/2001/XMLSchema");
        StringReader reader = new StringReader(xsd1);
        StreamSource source = new StreamSource(reader);
        DefaultHandler errorHandler = new DefaultHandler() {
            public void fatalError(SAXParseException _) throws SAXException {
                throw EUREKA;
            }

            public void error(SAXParseException _) throws SAXException {
                throw EUREKA;
            }
        };
        schemaFactory.setErrorHandler(errorHandler);

        try {
            schemaFactory.newSchema(new Source[] {source});
            fail("SAXException was not thrown.");
        } catch (SAXException e) {
            assertSame(e,EUREKA);
        }
    }
}