package org.w3c.exi.ttf.candidate.xebu;

import java.io.InputStream;
import java.io.OutputStream;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Enumeration;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.xml.sax.helpers.DefaultHandler;
import org.w3c.dom.Document;

import org.w3c.exi.ttf.CustomDriver;
import org.w3c.exi.ttf.fragments.FragmentsInputStream;
import org.w3c.exi.ttf.parameters.DriverParameters;
import org.w3c.exi.ttf.parameters.TestCaseParameters;

import fi.hiit.fuegocore.util.Util;
import fi.hiit.fuegocore.util.xas.Event;
import fi.hiit.fuegocore.util.xas.EventList;
import fi.hiit.fuegocore.util.xas.EventStream;
import fi.hiit.fuegocore.util.xas.TypedXmlParser;
import fi.hiit.fuegocore.util.xas.XasUtil;
import fi.hiit.fuegocore.util.xas.XasExtUtil;
import fi.hiit.fuegocore.message.encoding.XebuParser;
import fi.hiit.fuegocore.message.encoding.XebuSerializer;
import fi.hiit.fuegocore.message.encoding.CachePair;
import fi.hiit.fuegocore.message.encoding.DoaMachine;
import fi.hiit.fuegocore.message.encoding.EoaMachine;
import fi.hiit.fuegocore.message.encoding.XebuConstants;
import fi.hiit.fuegocore.message.encoding.coa.ReaderCoaMachine;

public class XebuCustomDriver extends CustomDriver {

    private static final String JAXP_SCHEMA_LANGUAGE
	= "http://java.sun.com/xml/jaxp/properties/schemaLanguage";
    private static final String JAXP_SCHEMA_SOURCE
	= "http://java.sun.com/xml/jaxp/properties/schemaSource";
    private static final String XML_SCHEMA
	= "http://www.w3.org/2001/XMLSchema";

    private DocumentBuilderFactory dbf = null;
    private ReaderCoaMachine rcm = null;
    private String schema = null;
    private String systemId = null;
    private boolean hasFragments = false;
    
    private XebuSerializer getXebuSerializer (OutputStream output) {
	XebuSerializer ser = new XebuSerializer();
	ser.setOutput(output, "UTF-8");
	if (rcm != null) {
	    CachePair pair = rcm.createNewPair();
	    ser.setProperty(XebuConstants.PROPERTY_INITIAL_CACHES,
			    pair.getOutCache());
	    EoaMachine eoa = rcm.createNewEoa();
	    if (!eoa.isIdentity()) {
		ser.setProperty(XebuConstants.PROPERTY_COA_MACHINE, eoa);
	    }
	}
	return ser;
    }

    private XebuParser getXebuParser () {
	XebuParser par = new XebuParser();
	if (rcm != null) {
	    CachePair pair = rcm.createNewPair();
	    par.setProperty(XebuConstants.PROPERTY_INITIAL_CACHES,
			    pair.getInCache());
	    DoaMachine doa = rcm.createNewDoa();
	    if (!doa.isIdentity()) {
		par.setProperty(XebuConstants.PROPERTY_COA_MACHINE, doa);
	    }
	}
	return par;
    }

    @Override
    protected void prepareTestCase (DriverParameters driverParameters,
				    TestCaseParameters testCaseParameters)
	throws Exception {
	dbf = DocumentBuilderFactory.newInstance();
	dbf.setNamespaceAware(true);
	systemId = testCaseParameters.xmlSystemId;
	hasFragments = testCaseParameters.fragments;
	if (driverParameters.isSchemaOptimizing
	    && !testCaseParameters.schemaDeviations) {
	    schema = testCaseParameters.schemaLocation;
	    dbf.setValidating(true);
	    if (schema.endsWith(".xsd")) {
		dbf.setAttribute(JAXP_SCHEMA_LANGUAGE, XML_SCHEMA);
		dbf.setAttribute(JAXP_SCHEMA_SOURCE, new File(schema));
		File tokFile = new File(schema.replaceAll("xsd$", "tok"));
		if (tokFile.exists()) {
		    rcm = new ReaderCoaMachine(new FileReader(tokFile));
		}
	    }
	}
    }

    private org.w3c.exi.ttf.Event convert (Event ev) {
	switch (ev.getType()) {
	case Event.START_DOCUMENT:
	case Event.END_DOCUMENT:
	    return null;
	case Event.START_ELEMENT:
	    return RealEvent.newStartElement(ev.getNamespace(), ev.getName(), "");
	case Event.ATTRIBUTE:
	    return RealEvent.newAttribute(ev.getNamespace(), ev.getName(), "",
				      (String) ev.getValue());
	case Event.END_ELEMENT:
	    return RealEvent.newEndElement(ev.getNamespace(), ev.getName(), "");
	case Event.CONTENT: {
	    RealEvent e = new RealEvent();
	    e.type = RealEvent.CHARACTERS;
	    e.datatype = RealEvent.DATATYPE_NONE;
	    e.stringValue = (String) ev.getValue();
	    return e;
	}
	case Event.TYPED_CONTENT: {
	    RealEvent e = new RealEvent();
	    e.type = RealEvent.CHARACTERS;
	    e.datatype = RealEvent.DATATYPE_BYTE_ARRAY;
	    e.namespace = ev.getNamespace();
	    e.localName = ev.getName();
	    e.objectValue = ev.getValue();
	    return e;
	}
	case Event.NAMESPACE_PREFIX:
	    return RealEvent.newNamespace((String) ev.getValue(),
					  ev.getNamespace());
	case Event.COMMENT: {
	    RealEvent e = new RealEvent();
	    e.type = RealEvent.COMMENT;
	    e.stringValue = (String) ev.getValue();
	    return e;
	}
	case Event.PROCESSING_INSTRUCTION: {
	    RealEvent e = new RealEvent();
	    e.type = RealEvent.PROCESSING_INSTRUCTION;
	    e.stringValue = (String) ev.getValue();
	    return e;
	}
	case Event.ENTITY_REFERENCE:
	    return RealEvent.newUnexpandedEntity(ev.getName());
	default:
	    throw new IllegalArgumentException("Unrecognized event " + ev);
	}
    }

    @Override
    protected org.w3c.exi.ttf.Event[]
    createEventsFromXMLTestCase (InputStream xmlInput)
	throws Exception {
	if (hasFragments) {
	    xmlInput = new FragmentsInputStream(xmlInput);
	}
	DocumentBuilder builder = dbf.newDocumentBuilder();
	builder.setErrorHandler(new DefaultHandler());
	Document document = systemId != null
	    ? builder.parse(xmlInput, systemId) : builder.parse(xmlInput);
	EventList el = (EventList) XasExtUtil.domToSequence(document);
	document = null;
	org.w3c.exi.ttf.Event[] result = new org.w3c.exi.ttf.Event[el.size()];
	int i = 0;
	int depth = 0;
	for (Enumeration e = el.events(); e.hasMoreElements(); ) {
	    Event ev = (Event) e.nextElement();
	    if (hasFragments && ev.getType() == Event.START_ELEMENT) {
		depth += 1;
		if (depth <= 1) {
		    continue;
		}
	    } else if (hasFragments && ev.getType() == Event.END_ELEMENT) {
		depth -= 1;
		if (depth <= 0) {
		    continue;
		}
	    }
	    org.w3c.exi.ttf.Event event = convert(ev);
	    if (event != null || ev.getType() == Event.START_DOCUMENT
		|| ev.getType() == Event.END_DOCUMENT) {
		result[i++] = event;
	    } else {
		System.err.println("Could not convert event " + ev);
	    }
	}
	return result;
    }

    @Override
    protected void encode (org.w3c.exi.ttf.Event[] inputEvents,
			   OutputStream output)
	throws Exception {
	XebuSerializer ser = getXebuSerializer(output);
	ser.startDocument(null, null);
	for (org.w3c.exi.ttf.Event e : inputEvents) {
	    if (e != null) {
		switch (e.type) {
		case RealEvent.START_ELEMENT:
		    ser.startTag(e.namespace, e.localName);
		    break;
		case RealEvent.END_ELEMENT:
		    ser.endTag(e.namespace, e.localName);
		    break;
		case RealEvent.CHARACTERS:
		    if (e.datatype == RealEvent.DATATYPE_NONE) {
			ser.text(e.stringValue);
		    } else {
			ser.typedContent(((RealEvent) e).objectValue,
					 e.namespace, e.localName);
		    }
		    break;
		case RealEvent.NAMESPACE:
		    ser.setPrefix(e.name, e.namespace);
		    break;
		case RealEvent.ATTRIBUTE:
		    ser.attribute(e.namespace, e.localName, e.stringValue);
		    break;
		case RealEvent.COMMENT:
		    ser.comment(e.stringValue);
		    break;
		case RealEvent.PROCESSING_INSTRUCTION:
		    ser.processingInstruction(e.stringValue);
		    break;
		case RealEvent.UNEXPANDED_ENTITY:
		    ser.entityRef(e.name);
		    break;
		default:
		    throw new IllegalArgumentException("Type of event " + e
						       + " not recognized");
		}
	    }
	}
	ser.endDocument();
    }

    @Override
    protected void decode (InputStream input,
			   ArrayList<org.w3c.exi.ttf.Event> outputEvents)
	throws Exception {
	XebuParser parser = getXebuParser();
	parser.setInput(input, null);
	boolean inProgress = true;
	while (inProgress) {
	    if (outputEvents == null) {
		if (parser.getEventType() == TypedXmlParser.END_DOCUMENT) {
		    inProgress = false;
		}
	    } else {
		int type = parser.getEventType();
		switch (type) {
		case TypedXmlParser.START_DOCUMENT:
		    outputEvents.add(null);
		    break;
		case TypedXmlParser.END_DOCUMENT:
		    outputEvents.add(null);
		    inProgress = false;
		    break;
		case TypedXmlParser.START_TAG: {
		    int nsStart =
			parser.getNamespaceCount(parser.getDepth() - 1);
		    int nsEnd = parser.getNamespaceCount(parser.getDepth());
		    for (int i = nsStart; i < nsEnd; i++) {
			String prefix = parser.getNamespacePrefix(i);
			String uri = parser.getNamespaceUri(i);
			outputEvents.add(RealEvent.newNamespace(prefix, uri));
		    }
		    outputEvents.add(RealEvent.newStartElement(parser.getNamespace(),
							       parser.getName(),
							       ""));
		    int atts = parser.getAttributeCount();
		    for (int i = 0; i < atts; i++) {
			outputEvents.add(RealEvent.newAttribute
					 (parser.getAttributeNamespace(i),
					  parser.getAttributeName(i), "",
					  parser.getAttributeValue(i)));
		    }
		    break;
		}
		case TypedXmlParser.END_TAG:
		    outputEvents.add(RealEvent.newEndElement(parser.getNamespace(),
							     parser.getName(),
							     ""));
		    break;
		case TypedXmlParser.TEXT: {
		    RealEvent e = new RealEvent();
		    e.type = RealEvent.CHARACTERS;
		    e.datatype = RealEvent.DATATYPE_NONE;
		    e.stringValue = parser.getText();
		    outputEvents.add(e);
		    break;
		}
		case TypedXmlParser.OBJECT: {
		    RealEvent e = new RealEvent();
		    e.type = RealEvent.CHARACTERS;
		    e.datatype = RealEvent.DATATYPE_BYTE_ARRAY;
		    e.namespace = parser.getNamespace();
		    e.localName = parser.getName();
		    e.objectValue = parser.getObject();
		    outputEvents.add(e);
		    break;
		}
		case TypedXmlParser.COMMENT: {
		    RealEvent e = new RealEvent();
		    e.type = RealEvent.COMMENT;
		    e.stringValue = parser.getText();
		    outputEvents.add(e);
		    break;
		}
		case TypedXmlParser.PROCESSING_INSTRUCTION: {
		    RealEvent e = new RealEvent();
		    e.type = RealEvent.PROCESSING_INSTRUCTION;
		    e.stringValue = parser.getText();
		    outputEvents.add(e);
		    break;
		}
		case TypedXmlParser.ENTITY_REF: {
		    String text = null;
		    String name = parser.getName();
		    if (name.charAt(0) == '#') {
			text = parser.getText();
		    } else if (Util.equals(name, "lt")) {
			text = "<";
		    } else if (Util.equals(name, "gt")) {
			text = ">";
		    } else if (Util.equals(name, "amp")) {
			text = "&";
		    } else if (Util.equals(name, "apos")) {
			text = "'";
		    } else if (Util.equals(name, "quot")) {
			text = "\"";
		    }
		    if (text != null) {
			RealEvent e = new RealEvent();
			e.type = RealEvent.CHARACTERS;
			e.datatype = RealEvent.DATATYPE_NONE;
			e.stringValue = text;
			outputEvents.add(e);
		    } else {
			outputEvents.add(RealEvent.newUnexpandedEntity(name));
		    }
		    break;
		}
		default:
		    throw new IllegalArgumentException("Event type " + type
						       + " not recognized");
		}
	    }
	    parser.nextToken();
	}
    }

    private static class RealEvent extends org.w3c.exi.ttf.Event {

	public Object objectValue;

    }

}
