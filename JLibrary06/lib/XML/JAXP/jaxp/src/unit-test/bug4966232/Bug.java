/*
 * @(#)$Id: Bug.java,v 1.1 2005/06/10 04:24:18 jeffsuttor Exp $
 *
 * Copyright 2001 Sun Microsystems, Inc. All Rights Reserved.
 * 
 * This software is the proprietary information of Sun Microsystems, Inc.  
 * Use is subject to license terms.
 * 
 */
package bug4966232;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.sax.SAXSource;
import javax.xml.validation.Schema;
import javax.xml.validation.SchemaFactory;

import junit.framework.TestCase;
import junit.textui.TestRunner;

import org.w3c.dom.Document;
import org.xml.sax.InputSource;

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

    
// test for W3C XML Schema 1.0 - newSchema(Source schema)
// supports and return a valid Schema instance
// SAXSource - valid schema

    public void testSchemaFactory01() throws Exception {   
        SchemaFactory sf = SchemaFactory.newInstance("http://www.w3.org/2001/XMLSchema");
        InputSource is = new InputSource(Bug.class.getResourceAsStream("test.xsd")); 
        SAXSource ss = new SAXSource (is);
        Schema s = sf.newSchema(ss);
        assertNotNull(s);
    } 


// test for W3C XML Schema 1.0 - newSchema(Source schema)
// supports and return a valid Schema instance
// DOMSource - valid schema

    public void testSchemaFactory02() throws Exception {   
        Document doc = null;
        SchemaFactory sf = SchemaFactory.newInstance("http://www.w3.org/2001/XMLSchema");
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        dbf.setNamespaceAware(true);
        doc = dbf.newDocumentBuilder().parse(
                Bug.class.getResource("test.xsd").toExternalForm() );
        DOMSource ds = new DOMSource(doc);
        Schema s = sf.newSchema(ds);
        assertNotNull(s);
    }
}