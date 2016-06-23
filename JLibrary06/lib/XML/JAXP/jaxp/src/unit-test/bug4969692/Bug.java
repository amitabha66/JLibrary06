/*
 * @(#)$Id: Bug.java,v 1.1 2005/06/10 04:24:56 jeffsuttor Exp $
 *
 * Copyright 2001 Sun Microsystems, Inc. All Rights Reserved.
 * 
 * This software is the proprietary information of Sun Microsystems, Inc.  
 * Use is subject to license terms.
 * 
 */
package bug4969692;

import javax.xml.validation.SchemaFactory;
import javax.xml.validation.Validator;

import junit.framework.TestCase;
import junit.textui.TestRunner;

import org.xml.sax.SAXException;

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
    
    public void test01() throws SAXException {
        Validator validator = schemaFactory.newSchema().newValidator();
        try {
            validator.getFeature(null);
            fail("exception expected");
        } catch (NullPointerException e) {
            ;
        }
    }

    public void test02() throws SAXException {
        Validator validator = schemaFactory.newSchema().newValidator();
        try {
            validator.setFeature(null, false);
            fail("exception expected");
        } catch (NullPointerException e) {
            ;
        }
    }
   }