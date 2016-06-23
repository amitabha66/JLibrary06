/*
 * @(#)$Id: Bug.java,v 1.1 2005/06/10 04:24:45 jeffsuttor Exp $
 *
 * Copyright 2001 Sun Microsystems, Inc. All Rights Reserved.
 * 
 * This software is the proprietary information of Sun Microsystems, Inc.  
 * Use is subject to license terms.
 * 
 */
package bug4969110;

import javax.xml.validation.SchemaFactory;
import javax.xml.validation.ValidatorHandler;

import junit.framework.TestCase;
import junit.textui.TestRunner;

import org.xml.sax.SAXException;
import org.xml.sax.SAXNotRecognizedException;

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
    
    SchemaFactory schemaFactory =
    SchemaFactory.newInstance("http://www.w3.org/2001/XMLSchema");

    public void test1() throws SAXException {
        try {
            ValidatorHandler validatorHandler =
            schemaFactory.newSchema().newValidatorHandler();
            validatorHandler.getProperty("unknown1234");
            fail("SAXNotRecognizedException was not thrown.");
        } catch (SAXNotRecognizedException e) {
            ;
        }
    }
    
    public void test2() throws SAXException {
        try {
            doTest(null);
            fail("NullPointerException was not thrown.");
        } catch (NullPointerException e) {
            ;
        }
    }
    
    public void test3() throws SAXException {
        try {
            doTest("unknown1234");
            fail("SAXNotRecognizedException was not thrown.");
        } catch (SAXNotRecognizedException e) {
            ;
        }
    }

    public void doTest(String name) throws SAXException {
        ValidatorHandler validatorHandler =
        schemaFactory.newSchema().newValidatorHandler();
        validatorHandler.setProperty(name, "123");
    }
}