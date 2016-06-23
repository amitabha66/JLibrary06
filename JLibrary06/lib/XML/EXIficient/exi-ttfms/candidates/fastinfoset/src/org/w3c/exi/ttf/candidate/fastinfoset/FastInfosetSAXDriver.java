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

import com.sun.xml.analysis.frequency.FrequencyHandler;
import com.sun.xml.fastinfoset.sax.SAXDocumentParser;
import com.sun.xml.fastinfoset.sax.SAXDocumentSerializer;
import com.sun.xml.fastinfoset.sax.SAXDocumentSerializerWithPrefixMapping;
import com.sun.xml.fastinfoset.vocab.ParserVocabulary;
import com.sun.xml.fastinfoset.vocab.SerializerVocabulary;
import com.sun.xml.fastinfoset.vocab.frequency.VocabularyGenerator;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.HashMap;
import java.util.Map;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import org.w3c.exi.ttf.SAXDriver;
import org.w3c.exi.ttf.fragments.FragmentsInputStream;
import org.w3c.exi.ttf.fragments.FragmentsSAXHandler;
import org.w3c.exi.ttf.parameters.DriverParameters;
import org.w3c.exi.ttf.parameters.PreserveParam;
import org.w3c.exi.ttf.parameters.TestCaseParameters;
import org.xml.sax.ContentHandler;
import org.xml.sax.XMLReader;
import org.xml.sax.helpers.DefaultHandler;

/**
 *
 * @author Paul.Sandoz@Sun.Com
 */
public class FastInfosetSAXDriver extends SAXDriver {
    protected SAXParserFactory _spf;
        
    protected ParserVocabulary _externalParserVocabulary;
    protected SerializerVocabulary _externalSerializeVocabulary;
    protected String _externalVocabularyURI;
    protected SerializerVocabulary _initialVocabulary;
    protected SAXDocumentSerializer _saxSerializer;
    protected Map<String, String> _namespaceURIToPrefix;
    
    protected boolean _isStringInterning;
    protected String _xmlSystemId;
    
    public FastInfosetSAXDriver() {
        _spf = SAXParserFactory.newInstance();
        _spf.setNamespaceAware(true);
    }
    
    protected void prepareTestCase(DriverParameters driverParameters, 
            TestCaseParameters testCaseParams) throws Exception {
        boolean preservePrefixes = testCaseParams.preserves.contains(PreserveParam.prefixes);
        
        _isStringInterning = driverParameters.params.getBooleanParam(
                DriverParameters.STRING_INTERNING);
	_xmlSystemId = testCaseParams.xmlSystemId;

        if (driverParameters.isSchemaOptimizing && 
                testCaseParams.schemaLocation != null &&
                !testCaseParams.schemaLocation.endsWith("autoschema.xsd")) {
            if (!testCaseParams.schemaLocation.equals(_externalVocabularyURI)) {
                FrequencyHandler fh = Util.createFrequencyHandler(
                        driverParameters, testCaseParams, _spf.newSAXParser());
                
                if (!preservePrefixes) {
                    _namespaceURIToPrefix = fh.getNamespaceURIToPrefixMap();
                }
                
                VocabularyGenerator.XmlApi a = (preservePrefixes)
                    ? VocabularyGenerator.XmlApi.SAX : VocabularyGenerator.XmlApi.StAX;
                VocabularyGenerator vg = new VocabularyGenerator(fh.getLists(), 
                        a);
                
                _externalSerializeVocabulary = vg.getSerializerVocabulary();
                _externalParserVocabulary = vg.getParserVocabulary();
                _externalVocabularyURI = "/";
            }

            _initialVocabulary = new SerializerVocabulary();
            _initialVocabulary.setExternalVocabulary(_externalVocabularyURI,
                    _externalSerializeVocabulary, false);
            
            if (preservePrefixes)
                _saxSerializer = new SAXDocumentSerializer();
            else
                _saxSerializer = new SAXDocumentSerializerWithPrefixMapping(_namespaceURIToPrefix);
            _saxSerializer.setVocabulary(_initialVocabulary);
        } else {
            _externalParserVocabulary = null;
            _externalSerializeVocabulary = null;
            _initialVocabulary = null;
            _externalVocabularyURI = null;
            _saxSerializer = new SAXDocumentSerializer();
        }
        
        Util.setSerializerIndexing(driverParameters, testCaseParams, _saxSerializer);
        
        _saxSerializer.setIgnoreComments(
                !testCaseParams.preserves.contains(PreserveParam.comments));
        _saxSerializer.setIgnoreProcesingInstructions(
                !testCaseParams.preserves.contains(PreserveParam.pis));
//        _saxSerializer.setIgnoreWhiteSpaceTextContent(
//                !testCaseParams.preserves.contains(PreserveParam.whitespace));
    }

    protected void transcodeTestCase(InputStream xmlInput, 
            OutputStream encodedOutput) throws Exception {
    	if (_testCaseParams.fragments) {
            xmlInput = new FragmentsInputStream(xmlInput);
    	}
        
        SAXParser parser = _spf.newSAXParser();
        
        _saxSerializer.setOutputStream(encodedOutput);
        parser.setProperty("http://xml.org/sax/properties/lexical-handler", _saxSerializer);
        
        final DefaultHandler saxSerializer = _testCaseParams.fragments ? 
            new FragmentsSAXHandler(_saxSerializer) : _saxSerializer;
        
	if (_xmlSystemId != null) {
	    parser.parse(xmlInput, saxSerializer, _xmlSystemId);
	} else {
	    parser.parse(xmlInput, saxSerializer);
	}
    }
    
    protected ContentHandler getSAXEncoder(OutputStream outputStream) throws Exception {
        if (_initialVocabulary != null) _initialVocabulary.clear();
        _saxSerializer.setOutputStream(outputStream);
        return _saxSerializer;
    }

    protected XMLReader getXMLReader() throws Exception {
        SAXDocumentParser sdp = new SAXDocumentParser();
        sdp.setStringInterning(_isStringInterning);
        sdp.setParseFragments(_testCaseParams.fragments);
        
        if (_externalVocabularyURI != null) {
            HashMap externalVocabularyMap = new HashMap();
            externalVocabularyMap.put(_externalVocabularyURI, 
                    _externalParserVocabulary);
            sdp.setExternalVocabularies(externalVocabularyMap);
        }
        
        return sdp;
    }
}
