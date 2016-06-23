/*
 * EXI Testing Task Force Measurement Suite: http://www.w3.org/XML/EXI/
 * 
 * Copyright ? [2006] World Wide Web Consortium, (Massachusetts Institute of
 * Technology, European Research Consortium for Informatics and Mathematics,
 * Keio University). All Rights Reserved. This work is distributed under the
 * W3C? Software License [1] in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.
 * 
 * [1] http://www.w3.org/Consortium/Legal/2002/copyright-software-20021231
 */

package org.w3c.exi.ttf.sax;

import java.io.IOException;
import java.util.Set;
import java.util.Stack;

import org.w3c.exi.ttf.parameters.PreserveParam;
import org.xml.sax.Attributes;
import org.xml.sax.ContentHandler;
import org.xml.sax.DTDHandler;
import org.xml.sax.ErrorHandler;
import org.xml.sax.InputSource;
import org.xml.sax.Locator;
import org.xml.sax.SAXException;
import org.xml.sax.SAXParseException;
import org.xml.sax.SAXNotSupportedException;
import org.xml.sax.SAXNotRecognizedException;
import org.xml.sax.XMLReader;
import org.xml.sax.ext.DeclHandler;
import org.xml.sax.ext.DefaultHandler2;
import org.xml.sax.ext.EntityResolver2;
import org.xml.sax.ext.LexicalHandler;
import org.xml.sax.helpers.XMLFilterImpl;

public class FidelityFilter extends XMLFilterImpl implements LexicalHandler,
	DeclHandler {

    private boolean hasComments = false;
    private boolean hasDtds = false;
    private boolean hasErs = false;
    private boolean hasLexical = false;
    private boolean hasNotations = false;
    private boolean hasPis = false;
    private boolean hasPrefixes = false;
    private boolean hasWhitespace = false;

    private boolean filterPrefixes = false;
    private boolean externalDtd = false;

    private boolean currentXmlSpace = false;
    private Stack<Boolean> xmlSpaceStack = new Stack<Boolean>();
    private StringBuilder whitespaceBuffer = new StringBuilder();

    private static final int INITIAL = 0;
    private static final int AFTER_START = 1;
    private static final int AFTER_END = 2;
    private static final int CONTENT = 3;
    private int state = INITIAL;

    private DefaultHandler2 handler = new DefaultHandler2();
    private DeclHandler declHandler = handler;
    private LexicalHandler lexicalHandler = handler;

    public FidelityFilter (XMLReader parent, Set<PreserveParam> preserves)
	    throws SAXException {
	this(parent, preserves, false);
    }

    public FidelityFilter (XMLReader parent, Set<PreserveParam> preserves,
	    boolean filterPrefixes) throws SAXException {
	super(parent);
	for (PreserveParam param : preserves) {
	    switch (param) {
	    case comments:
		hasComments = true;
		break;
	    case dtds:
		hasDtds = true;
		break;
	    case entityreferences:
		hasErs = true;
		break;
	    case lexicalvalues:
		hasLexical = true;
		break;
	    case notations:
		hasNotations = true;
		break;
	    case pis:
		hasPis = true;
		break;
	    case prefixes:
		hasPrefixes = true;
		break;
	    case whitespace:
		hasWhitespace = true;
		break;
	    }
	}
	this.filterPrefixes = filterPrefixes;
	parent.setProperty("http://xml.org/sax/properties/declaration-handler",
	    this);
	parent.setProperty("http://xml.org/sax/properties/lexical-handler",
	    this);
    }

    public void setProperty (String name, Object value)
	    throws SAXNotRecognizedException, SAXNotSupportedException {
	if (name.equals("http://xml.org/sax/properties/declaration-handler")) {
	    declHandler = (DeclHandler) value;
	} else if (name.equals("http://xml.org/sax/properties/lexical-handler")) {
	    lexicalHandler = (LexicalHandler) value;
	} else {
	    super.setProperty(name, value);
	}
    }

    public void setDeclHandler (DeclHandler declHandler) {
	this.declHandler = declHandler;
    }

    public void setLexicalHandler (LexicalHandler lexicalHandler) {
	this.lexicalHandler = lexicalHandler;
    }

    public void attributeDecl (String eName, String aName, String type,
	    String mode, String value) throws SAXException {
	if (hasDtds && !externalDtd) {
	    declHandler.attributeDecl(eName, aName, type, mode, value);
	}
    }

    public void comment (char[] ch, int start, int length) throws SAXException {
	if (hasComments && !externalDtd) {
	    outputWhitespace();
	    state = CONTENT;
	    lexicalHandler.comment(ch, start, length);
	}
    }

    public void elementDecl (String name, String model) throws SAXException {
	if (hasDtds && !externalDtd) {
	    declHandler.elementDecl(name, model);
	}
    }

    public void endCDATA () throws SAXException {
	lexicalHandler.endCDATA();
    }

    public void endDTD () throws SAXException {
	if (hasDtds) {
	    lexicalHandler.endDTD();
	}
    }

    public void endEntity (String name) throws SAXException {
	lexicalHandler.endEntity(name);
	if (name.equals("[dtd]")) {
	    externalDtd = false;
	}
    }

    public void externalEntityDecl (String name, String publicId,
	    String systemId) throws SAXException {
	if (hasDtds && !externalDtd) {
	    declHandler.externalEntityDecl(name, publicId, systemId);
	}
    }

    public void internalEntityDecl (String name, String value)
	    throws SAXException {
	if (hasDtds && !externalDtd) {
	    declHandler.internalEntityDecl(name, value);
	}
    }

    public void startCDATA () throws SAXException {
	lexicalHandler.startCDATA();
    }

    public void startDTD (String name, String publicId, String systemId)
	    throws SAXException {
        if (hasDtds) {
          lexicalHandler.startDTD(name, publicId, systemId);
        }
    }

    public void startEntity (String name) throws SAXException {
	lexicalHandler.startEntity(name);
	if (name.equals("[dtd]")) {
	    externalDtd = true;
	}
    }

    private boolean isWhitespace (char[] ch, int start, int length) {
	for (int i = start; i < start + length; i++) {
	    if (!Character.isWhitespace(ch[i])) {
		return false;
	    }
	}
	return true;
    }

    public void characters (char[] ch, int start, int length)
	    throws SAXException {
	if (currentXmlSpace || state == CONTENT || !isWhitespace(ch, start, length)) {
	    outputWhitespace();
	    super.characters(ch, start, length);
	    state = CONTENT;
	} else {
	    whitespaceBuffer.append(ch, start, length);
	}
    }

    private void outputWhitespace () throws SAXException {
	if (whitespaceBuffer.length() > 0) {
	    char[] ch = whitespaceBuffer.toString().toCharArray();
	    super.characters(ch, 0, whitespaceBuffer.length());
	    whitespaceBuffer.setLength(0);
	}
    }

    private void outputComplexWhitespace () throws SAXException {
	if (hasWhitespace) {
	    outputWhitespace();
	} else {
	    whitespaceBuffer.setLength(0);
	}
    }

    @Override
    public void endElement (String uri, String localName, String qName)
	    throws SAXException {
	if (state == AFTER_START) {
	    outputWhitespace();
	} else if (state == AFTER_END) {
	    outputComplexWhitespace();
	}
	currentXmlSpace = xmlSpaceStack.pop();
	if (xmlSpaceStack.empty()) {
	    state = INITIAL;
	} else {
	    state = AFTER_END;
	}
	super.endElement(uri, localName, qName);
    }

    @Override
    public void startElement (String uri, String localName, String qName,
	    Attributes atts) throws SAXException {
	if (state == AFTER_START || state == AFTER_END) {
	    outputComplexWhitespace();
	}
	xmlSpaceStack.push(currentXmlSpace);
	String xmlSpace = atts.getValue("http://www.w3.org/XML/1998/namespace",
	    "space");
	if (xmlSpace != null) {
	    if (xmlSpace.equals("preserve")) {
		currentXmlSpace = true;
	    } else {
		currentXmlSpace = false;
	    }
	}
	state = AFTER_START;
	super.startElement(uri, localName, qName, atts);
    }

    public void endPrefixMapping (String prefix) throws SAXException {
	if (!filterPrefixes || hasPrefixes) {
	    super.endPrefixMapping(prefix);
	}
    }

    public void ignorableWhitespace (char[] ch, int start, int length)
	    throws SAXException {
	if (currentXmlSpace || hasWhitespace) {
	    super.ignorableWhitespace(ch, start, length);
	}
    }

    public void notationDecl (String name, String publicId, String systemId)
	    throws SAXException {
	if (hasNotations) {
	    super.notationDecl(name, publicId, systemId);
	}
    }

    public void processingInstruction (String target, String data)
	    throws SAXException {
	if (hasPis && !externalDtd) {
	    outputWhitespace();
	    state = CONTENT;
	    super.processingInstruction(target, data);
	}
    }

    public void skippedEntity (String name) throws SAXException {
	if (hasErs) {
	    super.skippedEntity(name);
	}
    }

    public void startPrefixMapping (String prefix, String uri)
	    throws SAXException {
	if (!filterPrefixes || hasPrefixes) {
	    super.startPrefixMapping(prefix, uri);
	}
    }

    public void unparsedEntityDecl (String name, String publicId,
	    String systemId, String notationName) throws SAXException {
	if (hasDtds && !externalDtd) {
	    super.unparsedEntityDecl(name, publicId, systemId, notationName);
	}
    }

}
