/*
 * EXI Testing Task Force Measurement Suite: http://www.w3.org/XML/EXI/
 *
 * Copyright © [2006] World Wide Web Consortium, (Massachusetts Institute of
 * Technology, European Research Consortium for Informatics and Mathematics,
 * Keio University). All Rights Reserved. This work is distributed under the
 * W3C® Software License [1] in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * [1] http://www.w3.org/Consortium/Legal/2002/copyright-software-20021231
 */

package org.w3c.exi.ttf.candidate.fastinfoset;

import com.sun.japex.TestCase;
import com.sun.xml.analysis.types.SchemaProcessor;
import com.sun.xml.fastinfoset.streambuffer.TypedSAXBufferCreator;
import com.sun.xml.stream.buffer.MutableXMLStreamBuffer;
import com.sun.xml.stream.buffer.XMLStreamBuffer;
import java.io.File;
import java.io.InputStream;
import java.io.OutputStream;
import javax.xml.parsers.SAXParserFactory;
import org.w3c.exi.ttf.BaseDriver;
import org.w3c.exi.ttf.fragments.FragmentsInputStream;
import org.w3c.exi.ttf.parameters.MeasureParam;
import org.xml.sax.XMLReader;

public abstract class XMLStreamBufferCustomDriver extends BaseDriver {
    private XMLStreamBuffer sourceBuffer;
    private MutableXMLStreamBuffer sinkBuffer;
    
    protected abstract void encode(XMLStreamBuffer source, OutputStream outputStream)
            throws Exception;
    
    protected abstract void decode(InputStream inputStream, MutableXMLStreamBuffer sink)
            throws Exception;
    
    
    protected final void transcodeTestCase(InputStream xmlInput,
            OutputStream encodedOutput) throws Exception {
    	if (_testCaseParams.fragments) {
            xmlInput = new FragmentsInputStream(xmlInput);
    	}
        
        XMLStreamBuffer source = createBufferFromXMLTestCase(xmlInput);
        encode(source, encodedOutput);
    }

    private XMLStreamBuffer createBufferFromXMLTestCase(InputStream xmlInput) 
            throws Exception {
        SAXParserFactory spf = SAXParserFactory.newInstance();
        spf.setNamespaceAware(true);
        XMLReader reader = spf.newSAXParser().getXMLReader();

        if (_testCaseParams.schemaLocation != null) {
            SchemaProcessor sp = new SchemaProcessor(new File(_testCaseParams.schemaLocation).toURL());
            sp.process();

            // Create buffer from XML document, convert lexical space to
            // value space
            return TypedSAXBufferCreator.createNewBufferFromXMLReader(
                    sp.getElementToXSDataTypeMap(),
                    sp.getAttributeToXSDataTypeMap(),
                    reader,
                    xmlInput,
                    _testCaseParams.xmlSystemId);
        } else {
            return XMLStreamBuffer.createNewBufferFromXMLReader(
                    reader,
                    xmlInput);
        }
    }
    
    protected final void validateStream(InputStream encodedInput,
            InputStream originalInput) throws Exception {
        decode(encodedInput, sinkBuffer);
    }
    
    public final void initializeDriver() {
        // noop
    }
    
    public final void prepare(TestCase testCase) {
        sinkBuffer = new MutableXMLStreamBuffer();
        
        super.prepare(testCase);
        
        try {
            switch(_driverParams.measure) {
                case encode:
                    sourceBuffer = createBufferFromXMLTestCase(_testCaseParams.getXmlInputStream());
                    break;
                case decode:
                    break;
                default:
            }
        } catch (Exception e) {
            System.err.println("Error preparing test: " + testCase.getName());
            e.printStackTrace();
            throw new RuntimeException(e);
        }
    }
    
    public final void run(TestCase testCase) {
        try {
            if (_driverParams.measure == MeasureParam.decode) {
                decode(_dataSource.getInputStream(), sinkBuffer);
                _dataSource.finish();
            } else if (_driverParams.measure == MeasureParam.encode) {
                encode(sourceBuffer, _dataSink.getOutputStream());
                _dataSink.finish();
            }
        } catch (Exception e) {
            System.err.println("Error during test run: " + testCase.getName());
            e.printStackTrace();
            throw new RuntimeException(e);
        }
    }
}
