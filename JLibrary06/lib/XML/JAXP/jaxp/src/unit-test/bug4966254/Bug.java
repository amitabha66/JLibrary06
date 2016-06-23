/*
 * @(#)$Id: Bug.java,v 1.1 2005/06/10 04:23:45 jeffsuttor Exp $
 *
 * Copyright 2001 Sun Microsystems, Inc. All Rights Reserved.
 * 
 * This software is the proprietary information of Sun Microsystems, Inc.  
 * Use is subject to license terms.
 * 
 */
package bug4966254;

import javax.xml.transform.stream.StreamSource;
import javax.xml.validation.Schema;
import javax.xml.validation.SchemaFactory;
import javax.xml.validation.Validator;

import junit.framework.TestCase;
import junit.textui.TestRunner;

import org.xml.sax.SAXException;

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
    
    static final String SCHEMA_LANGUAGE = "http://java.sun.com/xml/jaxp/properties/schemaLanguage";
    static final String SCHEMA_SOURCE =  "http://java.sun.com/xml/jaxp/properties/schemaSource";

    

    public void testValidator01() throws Exception {
        getValidator().validate( getInstance() );
    } 

    public void testValidator02() throws Exception {
        getValidator().validate( getInstance(), null );
    }
    
    
    
    private StreamSource getInstance() {
        return new StreamSource(Bug.class.getResource(("test.xml")).toExternalForm());
    }

    private Validator getValidator() throws SAXException {
        Schema s = getSchema();
        Validator v = s.newValidator();
        assertNotNull(v);
        v.setErrorHandler(new DraconianErrorHandler());
        return v;
    }

    private Schema getSchema() throws SAXException {
        SchemaFactory sf = SchemaFactory.newInstance("http://www.w3.org/2001/XMLSchema");
        Schema s = sf.newSchema(Bug.class.getResource("test.xsd"));
        assertNotNull(s);
        return s;
    }
}