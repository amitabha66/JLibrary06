/*
 * EXI Testing Task Force Measurement Suite: http://www.w3.org/XML/EXI/
 *
 * Copyright ? [2006] World Wide Web Consortium, (Massachusetts Institute of
 * Technology, European Research Consortium for Informatics and Mathematics,
 * Keio University). All Rights Reserved. This work is distributed under the
 * W3C? Software License [1] in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * [1] http://www.w3.org/Consortium/Legal/2002/copyright-software-20021231
 */

package org.w3c.exi.ttf;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.File;
import java.io.StringReader;
import java.util.ArrayList;

import javax.xml.XMLConstants;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.Source;
import javax.xml.transform.Result;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.sax.SAXTransformerFactory;
import javax.xml.transform.sax.TransformerHandler;
import javax.xml.transform.sax.SAXSource;
import javax.xml.transform.sax.SAXResult;
import javax.xml.transform.dom.DOMResult;
import javax.xml.transform.stream.StreamSource;
import javax.xml.transform.stream.StreamResult;
import javax.xml.validation.SchemaFactory;
import javax.xml.validation.Schema;
import javax.xml.validation.Validator;

// import org.apache.xml.serialize.OutputFormat;
// import org.apache.xml.serialize.XMLSerializer;
import org.w3c.exi.ttf.fragments.FragmentsInputStream;
import org.w3c.exi.ttf.fragments.FragmentsSAXHandler;
import org.w3c.exi.ttf.fragments.FragmentsXMLReader;
import org.w3c.exi.ttf.parameters.MeasureParam;
import org.w3c.exi.ttf.parameters.PreserveParam;
import org.w3c.exi.ttf.sax.EmptyHandler;
import org.w3c.exi.ttf.sax.SAXRecorder;
import org.w3c.exi.ttf.sax.FidelityFilter;
import org.w3c.exi.ttf.sax.QnameInserter;
import org.w3c.exi.ttf.sax.PrefixConverter;
import org.xml.sax.Attributes;
import org.xml.sax.ContentHandler;
import org.xml.sax.DTDHandler;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.XMLReader;
import org.xml.sax.ErrorHandler;
import org.xml.sax.SAXParseException;
import org.xml.sax.ext.DeclHandler;
import org.xml.sax.ext.LexicalHandler;
import org.xml.sax.helpers.DefaultHandler;
import org.w3c.dom.Document;

import com.sun.japex.TestCase;
import com.sun.org.apache.xml.internal.serialize.OutputFormat;
import com.sun.org.apache.xml.internal.serialize.XMLSerializer;
import com.sun.org.apache.xml.internal.utils.DOMBuilder;

import fc.fp.util.xas.EventSequence;
import fc.fp.util.xas.EventSerializer;
import fc.fp.util.xas.SaxWriter;
import fc.fp.util.xas.XasExtUtil;

/**
 * Base class for EXI compactness and SAX API read/write performance drivers.
 * The purpose of this class is to simplify the work needed to implement
 * such a driver.
 *
 * <p>A SubClass MUST implement:<pre>
 *      void prepareTestCase(DriverParameters driverParams, TestCaseParameters testCaseParams)
 *      ContentHandler getSAXEncoder(OutputStream output)
 *      XMLReader getXMLReader()
 * </pre></p>
 *
 * <p>A SubClass MAY implement:<pre>
 *      void transcodeTestCase(String xmlfile, OutputStream encodedOutput)
 *      boolean gzipStream()
 * </pre></p>
 *
 * @author AgileDelta
 * @author Sun
 *
 */
public abstract class SAXDriver extends BaseDriver {

    /**
     * The XMLReader to use for measuring processing decoding.
     */
    private XMLReader _xmlReader;

    private EmptyHandler _decodeHandler;

    private ContentHandler _encodeContentHandler;
    private LexicalHandler _encodeLexicalHandler;
    private DTDHandler _encodeDtdHandler;
    private DeclHandler _encodeDeclHandler;

    private AttributesImpl _attributeEventsHolder;

    private SAXParser _saxParser;

    private Event[] _events;

    /**
     * Return a serializer implementing at least ContentHandler.
     * (LexicalHandler, DTDHandler, and DeclHandler are also recognized.)
     *
     * @param outputStream
     *      destination OutputStream
     * @throws Exception
     */
    protected abstract ContentHandler getSAXEncoder(OutputStream outputStream)
    throws Exception;

    /**
     * Returns the {@link org.xml.sax.XMLReader} for this driver
     *
     * @return The XMLReader instance.
     *
     * @throws SAXException
     *             If any SAX errors occur during processing.
     */
    protected abstract XMLReader getXMLReader() throws Exception;

    public final void initializeDriver() {
        try {
            SAXParserFactory spf = SAXParserFactory.newInstance();
            initializeParserFactory(spf);
            _saxParser = spf.newSAXParser();
        } catch (Exception e) {
            System.err.println("Error initializing driver");
            e.printStackTrace();
            throw new RuntimeException(e);
        }
    }
    
    protected void initializeParserFactory(SAXParserFactory spf) throws Exception {
      spf.setNamespaceAware(true);
    }

    public final void prepare(TestCase testCase) {
        super.prepare(testCase);

        try {
            switch(_driverParams.measure) {
                case encode:
                    _events = createEventsFromXMLTestCase(
                            _testCaseParams.getXmlInputStream(), _testCaseParams.xmlSystemId);
                    _attributeEventsHolder = new AttributesImpl(_events);
                    break;
                case decode:
                    _decodeHandler = new EmptyHandler();

                    _xmlReader = getXMLReader();
                    _xmlReader.setContentHandler(_decodeHandler);
                    _xmlReader.setErrorHandler(_decodeHandler);
                    _xmlReader.setDTDHandler(_decodeHandler);
                    _xmlReader.setEntityResolver(_decodeHandler);
                    _xmlReader.setProperty(
                            "http://xml.org/sax/properties/lexical-handler",
                            _decodeHandler);
                    _xmlReader.setProperty(
                            "http://xml.org/sax/properties/declaration-handler",
                            _decodeHandler);
                    break;
                default:
            }
        } catch (Exception e) {
            System.err.println("Error preparing test: " + testCase.getName());
            e.printStackTrace();
            throw new RuntimeException(e);
        }
    }

    private static final String ROOT_SCHEMA = "<schema xmlns='http://www.w3.org/2001/XMLSchema'><element name='root'/></schema>";

    private EventSequence convertValidatingDom (XMLReader reader,
						InputStream input,
						boolean hasFragments,
						boolean hasDeviations,
						boolean isXml)
	throws Exception {
       	Transformer tf = TransformerFactory.newInstance().newTransformer();
	PrefixConverter superKludger = new PrefixConverter(reader);
	QnameInserter kludger = new QnameInserter(superKludger);
	FidelityFilter filter = new FidelityFilter(kludger,
						   _testCaseParams.preserves);
	XMLReader realReader = hasFragments && !isXml
	    ? new FragmentsXMLReader(filter) : filter;
	if (hasFragments && isXml) {
	    input = new FragmentsInputStream(input);
	}
	InputSource is = new InputSource(input);
	is.setSystemId(_testCaseParams.xmlSystemId);
	Source source = new SAXSource(realReader, is);
	ByteArrayOutputStream bout = new ByteArrayOutputStream();
	Result result = new StreamResult(bout);
	tf.transform(source, result);
	// Uncomment to see intermediate XML
	//System.out.println(new String(bout.toByteArray(), "UTF-8"));
	SchemaFactory scf = SchemaFactory.newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI);
	Schema schema;
	if (hasFragments) {
	    Source[] sources = new Source[2];
	    sources[0] = new StreamSource(new File(_testCaseParams.schemaLocation));
	    sources[1] = new StreamSource(new StringReader(ROOT_SCHEMA));
	    schema = scf.newSchema(sources);
	} else {
	    schema = scf.newSchema(new File(_testCaseParams.schemaLocation));
	}
	DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
	dbf.setNamespaceAware(true);
	dbf.setSchema(schema);
	if (!_testCaseParams.preserves.contains(PreserveParam.whitespace)) {
	    dbf.setIgnoringElementContentWhitespace(true);
	}
	DocumentBuilder db = dbf.newDocumentBuilder();
	ErrorHandler errorHandler = new ErrorHandler () {
		private void print (String type, SAXParseException ex) {
		    System.err.println(type + ": " + ex.getMessage());
		    //ex.printStackTrace();
		}
		public void warning (SAXParseException ex) {
		    //print("WARNING", ex);
		}
		public void error (SAXParseException ex) {
		    //print("ERROR", ex);
		}
		public void fatalError (SAXParseException ex)
		    throws SAXException {
		    print("FATAL", ex);
		    throw ex;
		}
	    };
	if (hasDeviations) {
	    db.setErrorHandler(errorHandler);
	}
	Document d = db.parse(new ByteArrayInputStream(bout.toByteArray()),
			      _testCaseParams.xmlSystemId);
	return XasExtUtil.domToSequence(d, false, !_testCaseParams.preserves.contains(
	    PreserveParam.lexicalvalues));
		    
	/*
	QnameInserter kludger = new QnameInserter(reader);
	FidelityFilter filter = new FidelityFilter(kludger,
						   _testCaseParams.preserves);
	filter.trimWhitespace();
	Transformer tf = TransformerFactory.newInstance().newTransformer();
	InputSource is = new InputSource(input);
	is.setSystemId(_testCaseParams.xmlSystemId);
	Source source = new SAXSource(filter, is);
	DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
	dbf.setNamespaceAware(true);
	DocumentBuilder db = dbf.newDocumentBuilder();
	Document d = db.newDocument();
	Result result = new DOMResult(d);
	tf.transform(source, result);
	return XasExtUtil.domToSequence(d);
	*/
    }

    private EventSequence convertValidatingSax (XMLReader reader,
						InputStream input)
	throws Exception {
	PrefixConverter superKludger = new PrefixConverter(reader);
	QnameInserter kludger = new QnameInserter(superKludger);
	FidelityFilter filter = new FidelityFilter(kludger,
						   _testCaseParams.preserves);
	EventSerializer ser = new EventSerializer();
	SaxWriter writer = new SaxWriter(ser);
	SchemaFactory scf = SchemaFactory.newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI);
	Schema schema = scf.newSchema(new File(_testCaseParams.schemaLocation));
	Validator validator = schema.newValidator();
	ErrorHandler errorHandler = new ErrorHandler () {
		private void print (String type, SAXParseException ex) {
		    System.err.println(type + ": " + ex.getMessage());
		    ex.printStackTrace();
		}
		public void warning (SAXParseException ex) {
		    print("WARNING", ex);
		}
		public void error (SAXParseException ex) {
		    print("ERROR", ex);
		}
		public void fatalError (SAXParseException ex) {
		    print("FATAL", ex);
		}
	    };
	//validator.setErrorHandler(errorHandler);
	InputSource is = new InputSource(input);
	is.setSystemId(_testCaseParams.xmlSystemId);
	Source source = new SAXSource(filter, is);
	SAXResult result = new SAXResult(writer);
	result.setLexicalHandler(writer);
	validator.validate(source, result);
	return ser.getCurrentSequence();
    }

    private EventSequence convert (XMLReader reader, InputStream input,
				   boolean hasFragments)
	throws Exception {
	PrefixConverter superKludger = new PrefixConverter(reader);
	QnameInserter kludger = new QnameInserter(superKludger);
	FidelityFilter filter = new FidelityFilter(kludger,
						   _testCaseParams.preserves,
						   true);
	EventSerializer ser = new EventSerializer();
	SaxWriter writer = new SaxWriter(ser);
	if (hasFragments) {
	    input = new FragmentsInputStream(input);
	    FragmentsSAXHandler handler = new FragmentsSAXHandler(writer);
	    filter.setContentHandler(handler);
	    filter.setDTDHandler(handler);
	    filter.setLexicalHandler(handler);
	    filter.setDeclHandler(handler);
	} else {
	    filter.setContentHandler(writer);
	    filter.setDTDHandler(writer);
	    filter.setLexicalHandler(writer);
	    filter.setDeclHandler(writer);
	}
	InputSource is = new InputSource(input);
	is.setSystemId(_testCaseParams.xmlSystemId);
	filter.parse(is);
	return ser.getCurrentSequence();
    }

    /**
     * Validate that driver can (re)parse input
     *
     * @param encodedInput
     *            the input stream of the encoded xml
     */
    protected void validateStream(InputStream encodedInput,
            InputStream originalInput) throws Exception {
        ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
	
        // use Xerces serialization instead of JAXP for candidates that generate URI-localname pairs, but not qnames
        OutputFormat outputFormat = new OutputFormat();
        if (_testCaseParams.fragments)
        	outputFormat.setOmitXMLDeclaration(true);
        XMLSerializer handler = new XMLSerializer(outputStream, outputFormat);

        XMLReader reader = getXMLReader();
        reader.setContentHandler(handler);
	reader.setDTDHandler(handler);
	reader.setProperty("http://xml.org/sax/properties/declaration-handler",
			   handler);
	reader.setProperty("http://xml.org/sax/properties/lexical-handler",
			   handler);
        if (_driverParams.isXmlProcessor) {
            InputSource source = new InputSource(encodedInput);
            source.setSystemId(_testCaseParams.xmlSystemId);
            reader.parse(source);
        } else {

	    boolean hasDiff = Boolean.getBoolean("org.w3c.exi.ttf.validateDiff");
	    Class diffClass = null;
	    if (hasDiff) {
		try {
		    diffClass = Class.forName("faxma.Diff");
		} catch (ClassNotFoundException ex) {
		    hasDiff = false;
		}
	    }
	    if (hasDiff) {
		SAXParserFactory spf = SAXParserFactory.newInstance();
		spf.setNamespaceAware(true);
		SAXParser _parser = spf.newSAXParser();
		XMLReader xmlReader = _parser.getXMLReader();
		// avoid having external dtds affect whitespace preservation policy. (2006-09-20 by taki)
                xmlReader.setFeature("http://apache.org/xml/features/nonvalidating/load-external-dtd", false);
		// These are the event sequences to diff
		EventSequence originalSequence = null;
		EventSequence candidateSequence = null;
		if (_driverParams.isSchemaOptimizing
		    && _testCaseParams.schemaLocation != null) {
 		    originalSequence = convertValidatingDom(xmlReader, originalInput, _testCaseParams.fragments, _testCaseParams.schemaDeviations, true);
 		    candidateSequence = convertValidatingDom(getXMLReader(), encodedInput, _testCaseParams.fragments, _testCaseParams.schemaDeviations, false);
		} else {
		    originalSequence = convert(xmlReader, originalInput,
					       _testCaseParams.fragments);
		    candidateSequence = convert(getXMLReader(), encodedInput,
						false);
		}		    

		ByteArrayOutputStream diffos = new ByteArrayOutputStream();

		// Changed this invocation to a dynamic one so that
		// the code can be distributed as such without faxma

// 		if (faxma.Diff.diff(originalSequence, null,
// 				    candidateSequence, null,
// 				    diffos,
// 				    faxma.Diff.AlignEncoder.class, null, false)) {
		Class encoderClass = Class.forName("faxma.Diff$AlignEncoder");
		java.lang.reflect.Method diffMethod =
		    diffClass.getDeclaredMethod
		    ("diff", EventSequence.class,
		     fc.fp.util.xas.TypedXmlParser.class, EventSequence.class,
		     fc.fp.util.xas.TypedXmlParser.class, OutputStream.class,
		     Class.class, java.util.Map.class, Boolean.TYPE);
		if ((Boolean) diffMethod.invoke(null, originalSequence, null,
				    candidateSequence, null,
				    diffos,
				    encoderClass, null, false)) {
		    System.out.write( diffos.toByteArray() );
		}
	    } else {
		// serialize encoded stream as XML
		reader.parse(new InputSource(encodedInput));
		InputStream xmlInput = new ByteArrayInputStream(outputStream.toByteArray());
		if (_testCaseParams.fragments)
			xmlInput = new FragmentsInputStream(xmlInput);
		InputSource is = new InputSource(xmlInput);
		is.setSystemId(_testCaseParams.xmlSystemId);
		SAXParserFactory spf = SAXParserFactory.newInstance();
		spf.setNamespaceAware(true);
		SAXParser _parser = spf.newSAXParser();
		XMLReader xmlReader = _parser.getXMLReader();
		xmlReader.setContentHandler(new EmptyHandler());
		xmlReader.parse(is);
	    }

        }
    }

    public final void run(TestCase testCase) {
        try {
            if (_driverParams.measure == MeasureParam.decode) {
                final InputSource inputSource = new InputSource(_dataSource.getInputStream());
                if (_driverParams.isXmlProcessor) {
                    inputSource.setSystemId(_testCaseParams.xmlSystemId);
                }
                _xmlReader.parse(inputSource);
                _dataSource.finish();
            } else if (_driverParams.measure == MeasureParam.encode) {
                writeEventsToHandler(_events, _dataSink.getOutputStream());
                _dataSink.finish();
            }
        } catch (Exception e) {
            System.err.println("Error during test run: " + testCase.getName());
            e.printStackTrace();
            try {
                if (_dataSource != null) _dataSource.close();
                if (_dataSink != null) _dataSink.close();
            } catch (Exception ex) { }
            throw new RuntimeException(e);
        }
    }

    /**
     * Parse text-xml and record Events for later playback.
     */
    private Event[] createEventsFromXMLTestCase(InputStream xmlInput, String systemId)
    throws Exception {
        // parse document and record parse events for replay
        ArrayList<Event> eventList = new ArrayList<Event>();
    	if (_testCaseParams.fragments)
    		xmlInput = new FragmentsInputStream(xmlInput);
        final InputSource inputSource = new InputSource(xmlInput);
        inputSource.setSystemId(systemId);

        SAXRecorder recorder = new SAXRecorder(eventList, true);
        DefaultHandler contentHandler = _testCaseParams.fragments ? new FragmentsSAXHandler(recorder) : recorder;
        _saxParser.setProperty(
                "http://xml.org/sax/properties/lexical-handler",
                recorder);
        _saxParser.setProperty(
                "http://xml.org/sax/properties/declaration-handler",
                recorder);
        if (!_testCaseParams.preserves.contains(PreserveParam.dtds)) {
          // Avoid having external dtds affect whitespace preservation policy. (2006-10-05 by taki)
          // Note that SAXRecorder skips ignorable whitespaces (in terms of dtd).
          _saxParser.getXMLReader().setFeature(
              "http://apache.org/xml/features/nonvalidating/load-external-dtd", false);
        }
        _saxParser.parse(inputSource, contentHandler);

        return eventList.toArray(new Event[eventList.size()]);
    }

    /**
     * Iterate over the events (as constructed by parseText()) and invoke
     * the appropriate methods on a serializer returned from getSAXEncoder().
     */
    private void writeEventsToHandler(Event[] inputEvents,
            OutputStream outputStream) throws Exception {
        ContentHandler encodeContentHandler = getSAXEncoder(outputStream);
        if (encodeContentHandler == null)
          return;
        if (encodeContentHandler != _encodeContentHandler) {
            _encodeContentHandler = encodeContentHandler;
            _encodeLexicalHandler = (encodeContentHandler instanceof LexicalHandler)
            ? (LexicalHandler)encodeContentHandler : null;
            _encodeDtdHandler = (encodeContentHandler instanceof DTDHandler)
            ? (DTDHandler)encodeContentHandler : null;
            _encodeDeclHandler = (encodeContentHandler instanceof DeclHandler)
            ? (DeclHandler)encodeContentHandler : null;
        }

        _encodeContentHandler.startDocument();
        for (int i=0; i < inputEvents.length; i++) {
            Event e = inputEvents[i];
            switch (e.type) {
                case Event.START_ELEMENT:
                    int elemIdx = i;
                    while (inputEvents[i+1].type == Event.ATTRIBUTE)
                        i++;
                    _attributeEventsHolder.init(elemIdx + 1, i - elemIdx);
                    _encodeContentHandler.startElement(e.namespace, e.localName, e.name,
                            _attributeEventsHolder);
                    break;
                case Event.END_ELEMENT:
                    _encodeContentHandler.endElement(e.namespace, e.localName, e.name);
                    break;
                case Event.CHARACTERS:
                    _encodeContentHandler.characters(e.charValue, 0, e.charValue.length);
                    break;
                case Event.NAMESPACE:
                    _encodeContentHandler.startPrefixMapping(e.name, e.namespace);
                    break;
                case Event.END_NAMESPACE:
                    _encodeContentHandler.endPrefixMapping(e.name);
                    break;
                case Event.COMMENT:
                    if (_encodeLexicalHandler != null)
                        _encodeLexicalHandler.comment(e.charValue, 0, e.charValue.length);
                    break;
                case Event.PROCESSING_INSTRUCTION:
                    _encodeContentHandler.processingInstruction(e.name, e.stringValue);
                    break;
                case Event.UNEXPANDED_ENTITY:
                    _encodeContentHandler.skippedEntity(e.name);
                    break;
                case Event.DOCTYPE:
                    if (_encodeLexicalHandler != null)
                        _encodeLexicalHandler.startDTD(e.name, e.localName/*SystemId*/, e.namespace/*PublicId*/);
                    break;
                case Event.END_DTD:
                    if (_encodeLexicalHandler != null)
                        _encodeLexicalHandler.endDTD();
                    break;
                case Event.NOTATION:
                    if (_encodeDtdHandler != null)
                        _encodeDtdHandler.notationDecl(e.name, e.localName/*SystemId*/, e.namespace/*PublicId*/);
                    break;
                case Event.UNPARSED_ENTITY:
                    if (_encodeDtdHandler != null)
                        _encodeDtdHandler.unparsedEntityDecl(e.name, e.localName/*SystemId*/, e.namespace/*PublicId*/, e.stringValue/*NotationName*/);
                    break;
                case Event.EXTERNAL_ENTITY:
                    if (_encodeDeclHandler != null)
                        _encodeDeclHandler.externalEntityDecl(e.name, e.localName/*SystemId*/, e.namespace/*PublicId*/);
                    break;
                default:
                    throw new RuntimeException("unexpected");
            }
        }
        _encodeContentHandler.endDocument();
    }

    /**
     * Implement SAX Attributes interface over an Event array.  Used by the encode() method.
     */
    private static class AttributesImpl implements Attributes {
        Event[] _events;
        int _idxStart;
        int _length;

        /**
         * Initialize providing event[] that will contain attribute information
         * @param events
         */
        public AttributesImpl(Event[] events) {
            _events = events;
        }

        /**
         * Prepare for use, attributes will be found sequencially
         * in the Event[] passed to the constructor starting at
         * index 'start' and continuing for 'attrCount' Events.
         * Each attribute is represented by a single Event object.
         * @param start
         *      index of the first attribute
         * @param attrCount
         *      count of attributes
         */
        public void init(int start, int attrCount) {
            this._idxStart = start;
            this._length = attrCount;
        }

        public int getLength() {
            return _length;
        }

        public String getLocalName(int index) {
            if (index < _length) {
                Event e = _events[_idxStart + index];
                return e.localName;
            } else {
                throw new IndexOutOfBoundsException();
            }
        }

        public String getQName(int index) {
            if (index < _length) {
                Event e = _events[_idxStart + index];
                return e.name;
            } else {
                throw new IndexOutOfBoundsException();
            }
        }

        public String getURI(int index) {
            if (index < _length) {
                Event e = _events[_idxStart + index];
                return e.namespace;
            } else {
                throw new IndexOutOfBoundsException();
            }
        }

        public String getValue(int index) {
            if (index < _length) {
                Event e = _events[_idxStart + index];
                return e.getValueString();
            } else {
                throw new IndexOutOfBoundsException();
            }
        }

        public int getIndex(String uri, String localName) {
            throw new RuntimeException("Not Implemented");
        }

        public int getIndex(String qName) {
            throw new RuntimeException("Not Implemented");
        }

        public String getType(int index) {
            return "CDATA";
        }

        public String getType(String uri, String localName) {
            throw new RuntimeException("Not Implemented");
        }

        public String getType(String qName) {
            throw new RuntimeException("Not Implemented");
        }

        public String getValue(String uri, String localName) {
            throw new RuntimeException("Not Implemented");
        }

        public String getValue(String qName) {
            throw new RuntimeException("Not Implemented");
        }
    }
}
