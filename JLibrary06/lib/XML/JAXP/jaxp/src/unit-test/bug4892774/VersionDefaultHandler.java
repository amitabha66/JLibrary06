/*
 * VersionDefaultHandler.java
 *
 * Created on December 15, 2005, 3:54 PM
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package bug4892774;

import org.xml.sax.*;
import org.xml.sax.ext.*;
import org.xml.sax.helpers.*;
/**
 *
 * @author Sunitha Reddy
 */
public class VersionDefaultHandler extends DefaultHandler{
    
    private String version = null;
    
    private String encoding = null;
    
    /** Creates a new instance of VersionDefaultHandler */
    public VersionDefaultHandler() {
    }
    
    Locator saxLocator = null;
    public void setDocumentLocator(Locator locator){
            saxLocator = locator;
    }

    public void startElement(String uri,String localName,String qName,Attributes attributes)throws SAXException {
          version = ((org.xml.sax.ext.Locator2)saxLocator).getXMLVersion();
          encoding = ((org.xml.sax.ext.Locator2)saxLocator).getEncoding();
    }
    
    public void error(SAXParseException e) throws SAXException {
        e.printStackTrace();
    }
            
    public String getVersion(){
        return version;
    }
    
    public String getEncoding() {
        return encoding;
    }
    
}
