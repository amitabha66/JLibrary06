package org.w3c.exi.ttf.candidate.xebu;

import java.io.IOException;
import java.util.Set;

import org.w3c.exi.ttf.parameters.PreserveParam;
import org.xml.sax.Attributes;
import org.xml.sax.ContentHandler;
import org.xml.sax.DTDHandler;
import org.xml.sax.ErrorHandler;
import org.xml.sax.InputSource;
import org.xml.sax.Locator;
import org.xml.sax.SAXException;
import org.xml.sax.SAXParseException;
import org.xml.sax.XMLReader;
import org.xml.sax.ext.DeclHandler;
import org.xml.sax.ext.DefaultHandler2;
import org.xml.sax.ext.EntityResolver2;
import org.xml.sax.ext.LexicalHandler;

public class FidelityFilter extends DefaultHandler2 {

    private boolean hasComments = false;
    private boolean hasDtds = false;
    private boolean hasErs = false;
    private boolean hasLexical = false;
    private boolean hasNotations = false;
    private boolean hasPis = false;
    private boolean hasPrefixes = false;
    private boolean hasWhitespace = false;

    private boolean externalDtd = false;

    private DefaultHandler2 handler = new DefaultHandler2();
    private ContentHandler contentHandler;
    private DTDHandler dtdHandler;
    private ErrorHandler errorHandler;
    private DeclHandler declHandler;
    private EntityResolver2 entityResolver;
    private LexicalHandler lexicalHandler;

    public FidelityFilter (Set<PreserveParam> preserves) {
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
	contentHandler = handler;
	dtdHandler = handler;
	errorHandler = handler;
	declHandler = handler;
	lexicalHandler = handler;
	entityResolver = handler;
    }

    public void setContentHandler (ContentHandler contentHandler) {
	this.contentHandler = contentHandler;
    }

    public void setDTDHandler (DTDHandler dtdHandler) {
	this.dtdHandler = dtdHandler;
    }

    public void setErrorHandler (ErrorHandler errorHandler) {
	this.errorHandler = errorHandler;
    }

    public void setDeclHandler (DeclHandler declHandler) {
	this.declHandler = declHandler;
    }

    public void setLexicalHandler (LexicalHandler lexicalHandler) {
	this.lexicalHandler = lexicalHandler;
    }

    public void setEntityResolver (EntityResolver2 entityResolver) {
	this.entityResolver = entityResolver;
    }

    public void register (XMLReader parser) throws SAXException {
	parser.setContentHandler(this);
	parser.setDTDHandler(this);
	parser.setErrorHandler(this);
	parser.setProperty("http://xml.org/sax/properties/declaration-handler",
		this);
	parser.setEntityResolver(this);
	parser.setProperty("http://xml.org/sax/properties/lexical-handler",
		this);
    }

    @Override
    public void attributeDecl (String eName, String aName, String type,
	    String mode, String value) throws SAXException {
	if (hasDtds && !externalDtd) {
	    declHandler.attributeDecl(eName, aName, type, mode, value);
	}
    }

    @Override
    public void comment (char[] ch, int start, int length) throws SAXException {
	if (hasComments && !externalDtd) {
	    lexicalHandler.comment(ch, start, length);
	}
    }

    @Override
    public void elementDecl (String name, String model) throws SAXException {
	if (hasDtds && !externalDtd) {
	    declHandler.elementDecl(name, model);
	}
    }

    @Override
    public void endCDATA () throws SAXException {
	lexicalHandler.endCDATA();
    }

    @Override
    public void endDTD () throws SAXException {
	if (hasDtds) {
	    lexicalHandler.endDTD();
	}
    }

    @Override
    public void endEntity (String name) throws SAXException {
	lexicalHandler.endEntity(name);
	if (name.equals("[dtd]")) {
	    externalDtd = false;
	}
    }

    @Override
    public void externalEntityDecl (String name, String publicId,
	    String systemId) throws SAXException {
	if (hasDtds && !externalDtd) {
	    declHandler.externalEntityDecl(name, publicId, systemId);
	}
    }

    @Override
    public InputSource getExternalSubset (String name, String baseURI)
	    throws SAXException, IOException {
	return entityResolver.getExternalSubset(name, baseURI);
    }

    @Override
    public void internalEntityDecl (String name, String value)
	    throws SAXException {
	if (hasDtds && !externalDtd) {
	    declHandler.internalEntityDecl(name, value);
	}
    }

    @Override
    public InputSource resolveEntity (String name, String publicId,
	    String baseURI, String systemId) throws SAXException, IOException {
	return entityResolver.resolveEntity(name, publicId, baseURI, systemId);
    }

    @Override
    public InputSource resolveEntity (String publicId, String systemId)
	    throws SAXException, IOException {
	return entityResolver.resolveEntity(publicId, systemId);
    }

    @Override
    public void startCDATA () throws SAXException {
	lexicalHandler.startCDATA();
    }

    @Override
    public void startDTD (String name, String publicId, String systemId)
	    throws SAXException {
	lexicalHandler.startDTD(name, publicId, systemId);
    }

    @Override
    public void startEntity (String name) throws SAXException {
	lexicalHandler.startEntity(name);
	if (name.equals("[dtd]")) {
	    externalDtd = true;
	}
    }

    @Override
    public void characters (char[] ch, int start, int length)
	    throws SAXException {
	contentHandler.characters(ch, start, length);
    }

    @Override
    public void endDocument () throws SAXException {
	contentHandler.endDocument();
    }

    @Override
    public void endElement (String uri, String localName, String qName)
	    throws SAXException {
	contentHandler.endElement(uri, localName, qName);
    }

    @Override
    public void endPrefixMapping (String prefix) throws SAXException {
	contentHandler.endPrefixMapping(prefix);
    }

    @Override
    public void error (SAXParseException e) throws SAXException {
	errorHandler.error(e);
    }

    @Override
    public void fatalError (SAXParseException e) throws SAXException {
	errorHandler.fatalError(e);
    }

    @Override
    public void ignorableWhitespace (char[] ch, int start, int length)
	    throws SAXException {
	if (hasWhitespace) {
	    contentHandler.ignorableWhitespace(ch, start, length);
	}
    }

    @Override
    public void notationDecl (String name, String publicId, String systemId)
	    throws SAXException {
	if (hasNotations) {
	    dtdHandler.notationDecl(name, publicId, systemId);
	}
    }

    @Override
    public void processingInstruction (String target, String data)
	    throws SAXException {
	if (hasPis && !externalDtd) {
	    contentHandler.processingInstruction(target, data);
	}
    }

    @Override
    public void setDocumentLocator (Locator locator) {
	contentHandler.setDocumentLocator(locator);
    }

    @Override
    public void skippedEntity (String name) throws SAXException {
	if (hasErs) {
	    contentHandler.skippedEntity(name);
	}
    }

    @Override
    public void startDocument () throws SAXException {
	contentHandler.startDocument();
    }

    @Override
    public void startElement (String uri, String localName, String qName,
	    Attributes attributes) throws SAXException {
	contentHandler.startElement(uri, localName, qName, attributes);
    }

    @Override
    public void startPrefixMapping (String prefix, String uri)
	    throws SAXException {
	contentHandler.startPrefixMapping(prefix, uri);
    }

    @Override
    public void unparsedEntityDecl (String name, String publicId,
	    String systemId, String notationName) throws SAXException {
	if (hasDtds && !externalDtd) {
	    dtdHandler.unparsedEntityDecl(name, publicId, systemId,
		    notationName);
	}
    }

    @Override
    public void warning (SAXParseException e) throws SAXException {
	errorHandler.warning(e);
    }

}
