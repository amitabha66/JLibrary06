/*
 * @(#)$Id: Bug.java,v 1.1 2005/06/10 04:24:55 jeffsuttor Exp $
 *
 * Copyright 2001 Sun Microsystems, Inc. All Rights Reserved.
 * 
 * This software is the proprietary information of Sun Microsystems, Inc.  
 * Use is subject to license terms.
 * 
 */
package bug4966082;

import java.io.StringReader;

import java.io.*;
import java.net.*;
import javax.xml.parsers.*;
import org.w3c.dom.*;
import junit.framework.TestCase;
import junit.textui.TestRunner;

public class Bug extends TestCase {
    
    public Bug(String name) {
        super(name);
    }
    
    public static void main(String[] args) {
        TestRunner.run(Bug.class);
    }

	public void testOne(){
		try{
	 		Document document = DocumentBuilderFactory.newInstance().newDocumentBuilder().parse(Bug.class.getResource("test.xml").toExternalForm()); 
	 		if(document.getDocumentElement().getSchemaTypeInfo() == null) {
	 			fail("getSchemaTypeInfo returns null");
			}
		}catch(Exception ex){ 
	 		fail("Unexpected  error"+ex);
		}
	}
}
