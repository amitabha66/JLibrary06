/*
 * The contents of this file are subject to the terms
 * of the Common Development and Distribution License
 * (the License).  You may not use this file except in
 * compliance with the License.
 *
 * You can obtain a copy of the license at
 * https://glassfish.dev.java.net/public/CDDLv1.0.html.
 * See the License for the specific language governing
 * permissions and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL
 * Header Notice in each file and include the License file
 * at https://glassfish.dev.java.net/public/CDDLv1.0.html.
 * If applicable, add the following below the CDDL Header,
 * with the fields enclosed by brackets [] replaced by
 * you own identifying information:
 * "Portions Copyrighted [year] [name of copyright owner]"
 *
 * [Name of File] [ver.__] [Date]
 *
 * Copyright 2007 Sun Microsystems Inc. All Rights Reserved
 */

package IssueTracker35;

import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamConstants;
import junit.framework.TestCase;
import junit.textui.TestRunner;
import javax.xml.stream.XMLStreamReader;

/**
 * Unit Test for SJSXP Issue 35
 * https://sjsxp.dev.java.net/issues/show_bug.cgi?id=28
 *
 * @author Santiago.PericasGeertsen@sun.com
 */
public class Test extends TestCase {
    
    public static void main(String [] args){
        TestRunner.run(Test.class);
    }
    
    public void testSkippingExternalDTD() throws Exception {
        XMLInputFactory xif = XMLInputFactory.newInstance();
        XMLStreamReader reader = xif.createXMLStreamReader(
                getClass().getResource("XMLSchema.xsd").getFile(),
                getClass().getResourceAsStream("XMLSchema.xsd"));
   
        int e;
        while ((e = reader.next()) == XMLStreamConstants.COMMENT);
        assertTrue(e == XMLStreamConstants.DTD);
        reader.nextTag();
        assertTrue(reader.getLocalName().equals("schema"));
    }
}
