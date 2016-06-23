/*
 * W3C EXI Driver software v0.1 ("Software")
 * 
 * Copyright, 2005-2006 AgileDelta, Inc. All Rights Reserved.
 * 
 * This Software is distributed under the following terms:
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, is permitted provided that the following conditions are met:
 * 
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 
 * Redistribution in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * The neither the name of AgileDelta, Inc. nor the names of contributors 
 * may be used to endorse or promote products derived from this Software 
 * without specific prior written permission.
 * 
 * THE SOFTWARE IS PROVIDED TO "AS IS" WITHOUT WARRANTY OF ANY KIND. ALL 
 * EXPRESS OR IMPLIED CONDITIONS, REPRESENTATIONS, AND WARRANTIES, INCLUDING 
 * ANY IMPLIED WARRANTY OF MERCHANTABILITY, SATISFACTORY QUALITY, FITNESS FOR 
 * A PARTICULAR PURPOSE, OR NON-INFRINGEMENT, ARE DISCLAIMED, EXCEPT TO THE 
 * EXTENT THAT SUCH DISCLAIMERS ARE HELD TO BE LEGALLY INVALID. AGILEDELTA 
 * SHALL NOT BE LIABLE FOR ANY DAMAGES OR LIABILITIES SUFFERED BY LICENSEE 
 * OR TO ANY THIRD PARTY AS A RESULT OF OR RELATED TO USE, MODIFICATION OR
 * DISTRIBUTION OF THE SOFTWARE OR ITS DERIVATIVES. IN NO EVENT WILL AGILEDELTA
 * BE LIABLE FOR ANY INDIRECT, PUNITIVE, SPECIAL, INCIDENTAL OR CONSEQUENTIAL 
 * DAMAGE IN CONNECTION WITH OR ARISING OUT OF THIS AGREEMENT (INCLUDING LOSS 
 * OF BUSINESS, REVENUE, PROFITS, USE, DATA OR OTHER ECONOMIC ADVANTAGE), 
 * HOWEVER IT ARISES, WHETHER FOR BREACH OR IN TORT, EVEN IF AGILEDELTA HAS 
 * BEEN PREVIOUSLY ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. LIABILITY FOR 
 * DAMAGES WILL BE LIMITED AND EXCLUDED, EVEN IF ANY EXCLUSIVE REMEDY PROVIDED
 * FOR IN THIS AGREEMENT FAILS OF ITS ESSENTIAL PURPOSE. 
 *
 * SOFTWARE IS NOT DESIGNED OR INTENDED FOR USE IN ON-LINE CONTROL OF AIRCRAFT, 
 * AIR TRAFFIC, AIRCRAFT NAVIGATION OR AIRCRAFT COMMUNICATIONS; OR IN THE DESIGN,
 * CONSTRUCTION, OPERATION OR MAINTENANCE OF ANY NUCLEAR FACILITY. AGILEDELTA
 * DISCLAIMS ANY EXPRESS OR IMPLIED WARRANTY OF FITNESS FOR SUCH USES. LICENSEE 
 * REPRESENTS AND WARRANTS THAT IT WILL NOT USE THE SOFTWARE FOR SUCH PURPOSES.
 */
package org.w3c.exi.ttf.candidate.efx;

import java.io.InputStream;
import java.io.OutputStream;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import org.w3c.exi.ttf.SAXDriver;

import org.w3c.exi.ttf.fragments.FragmentsInputStream;
import org.w3c.exi.ttf.fragments.FragmentsSAXHandler;
import org.w3c.exi.ttf.parameters.DriverParameters;
import org.w3c.exi.ttf.parameters.TestCaseParameters;
import org.xml.sax.ContentHandler;
import org.xml.sax.InputSource;
import org.xml.sax.XMLReader;
import org.xml.sax.helpers.DefaultHandler;

import com.agiledelta.efx.EFXFactory;
import com.agiledelta.efx.sax.SAXHandler;

/**
 * @author AgileDelta
 *
 */
public class EFXSAXDriver extends SAXDriver
{
    EFXFactory _efxFactory;
    String _inputFilename;

    @Override
    protected void prepareTestCase(DriverParameters driverParams, TestCaseParameters testCaseParams) throws Exception
    {
        _efxFactory = EFXUtil.initFactory(driverParams, testCaseParams);
        _inputFilename = testCaseParams.xmlFile;
    }

    @Override
    public void transcodeTestCase(InputStream xmlInput, OutputStream encodedOutput) 
    throws Exception
    {
    	if (_testCaseParams.fragments)
    	{
    		xmlInput = new FragmentsInputStream(xmlInput);
    	}

    	SAXParserFactory spf = SAXParserFactory.newInstance();
        spf.setNamespaceAware(true);
        SAXParser parser = spf.newSAXParser();

        ContentHandler writer = _efxFactory.createSAXWriter(encodedOutput);
        InputSource xmlInSrc = new InputSource(xmlInput);
        xmlInSrc.setSystemId(_inputFilename);
        parser.setProperty("http://xml.org/sax/properties/lexical-handler",  writer);
        DefaultHandler contentHandler = _testCaseParams.fragments ? new FragmentsSAXHandler(writer) : new SAXHandler(writer);
        parser.parse(xmlInSrc, contentHandler);
    }
    
    @Override
    protected XMLReader getXMLReader() throws Exception
    {
        return _efxFactory.createXMLReader();
    }

    @Override
    protected ContentHandler getSAXEncoder(OutputStream outputStream) throws Exception
    {
        return _efxFactory.createSAXWriter(outputStream);
    }

}
