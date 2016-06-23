package org.w3c.exi.ttf.sax;

import java.util.List;
import java.util.ArrayList;
import java.util.Stack;

import org.xml.sax.XMLReader;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.XMLFilterImpl;
import org.xml.sax.helpers.AttributesImpl;

public class PrefixConverter extends XMLFilterImpl {

    private Stack<List<String>> nsStack = new Stack<List<String>>();

    public PrefixConverter (XMLReader parent) {
	super(parent);
    }

    public void startElement (String uri, String localName, String qName,
			      Attributes atts)
	throws SAXException {
	List<String> nss = new ArrayList<String>();
	if (atts != null && atts.getLength() > 0) {
	    int n = atts.getLength();
	    AttributesImpl newAtts = new AttributesImpl();
	    for (int i = 0; i < n; i++) {
		String aqName = atts.getQName(i);
		if (aqName != null && aqName.startsWith("xmlns")) {
		    String prefix;
		    if (aqName.length() == 5) {
			prefix = "";
		    } else {
			prefix = aqName.substring(6);
		    }
		    nss.add(prefix);
		    startPrefixMapping(prefix, atts.getValue(i));
		} else {
		    newAtts.addAttribute(atts.getURI(i), atts.getLocalName(i),
					 aqName, atts.getType(i),
					 atts.getValue(i));
		}
	    }
	    atts = newAtts;
	}
	nsStack.push(nss);
	super.startElement(uri, localName, qName, atts);
    }

    public void endElement (String uri, String localName, String qName)
	throws SAXException {
	super.endElement(uri, localName, qName);
	List<String> nss = nsStack.pop();
	for (String prefix : nss) {
	    endPrefixMapping(prefix);
	}
    }

}
