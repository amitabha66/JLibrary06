/*
 * @(#)$Id: Bug.java,v 1.1 2005/06/10 04:24:46 jeffsuttor Exp $
 *
 * Copyright 2001 Sun Microsystems, Inc. All Rights Reserved.
 * 
 * This software is the proprietary information of Sun Microsystems, Inc.  
 * Use is subject to license terms.
 * 
 */
package bug4969689;

import javax.xml.validation.SchemaFactory;

import junit.framework.TestCase;
import junit.textui.TestRunner;

import org.xml.sax.SAXNotRecognizedException;
import org.xml.sax.SAXNotSupportedException;

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

    SchemaFactory schemaFactory = SchemaFactory.newInstance("http://www.w3.org/2001/XMLSchema");
    
    public void test01() throws SAXNotRecognizedException, SAXNotSupportedException {
        try {
            schemaFactory.getFeature(null);
            fail("exception expected");
        } catch (NullPointerException e) {
            ; // expected
        }
    }

    public void test() throws SAXNotRecognizedException, SAXNotSupportedException {
        try {
            schemaFactory.setFeature(null, false);
            fail("exception expected");
        } catch (NullPointerException e) {
            ; // as expected
        }
    }
}