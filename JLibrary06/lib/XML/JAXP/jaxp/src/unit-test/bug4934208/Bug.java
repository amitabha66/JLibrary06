/*
 * @(#)$Id: Bug.java,v 1.1 2005/06/10 04:24:34 jeffsuttor Exp $
 *
 * Copyright 2001 Sun Microsystems, Inc. All Rights Reserved.
 * 
 * This software is the proprietary information of Sun Microsystems, Inc.  
 * Use is subject to license terms.
 * 
 */
package bug4934208;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import junit.framework.TestCase;
import junit.textui.TestRunner;

import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.XMLReader;

import util.DraconianErrorHandler;

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

    public void test1() throws Exception {
        parse(new InputSource(Bug.class.getResourceAsStream("test1.xml")));
    }
    
    public void test2() throws Exception {
        try {
            parse(new InputSource(Bug.class.getResourceAsStream("test2.xml")));
        } catch( SAXException e ) {
            assertTrue(e.getMessage().startsWith("cvc-complex-type.2.4.a"));
        }
    }
    
    private void parse(InputSource is) throws Exception {
        SAXParserFactory spf = SAXParserFactory.newInstance();
        spf.setNamespaceAware(true);
        spf.setValidating(true);
        SAXParser parser = spf.newSAXParser();

        parser.setProperty(
            "http://java.sun.com/xml/jaxp/properties/schemaLanguage",
            "http://www.w3.org/2001/XMLSchema");
        parser.setProperty(
            "http://java.sun.com/xml/jaxp/properties/schemaSource",
            Bug.class.getResourceAsStream("test.xsd"));
        
        XMLReader r = parser.getXMLReader();
        
        r.setErrorHandler(new DraconianErrorHandler());
        r.parse(is);
    }
}