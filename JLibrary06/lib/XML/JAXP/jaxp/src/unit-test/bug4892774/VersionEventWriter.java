/*
 * VersionEventWriter.java
 *
 * Created on December 15, 2005, 5:00 PM
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package bug4892774;

import javax.xml.stream.*;
import javax.xml.stream.events.*;
import javax.xml.namespace.*;

/**
 *
 * @author Sunitha Reddy
 */
public class VersionEventWriter implements XMLEventWriter{
    
    private String version = null;
    
    private String encoding = null;
    
    /** Creates a new instance of VersionEventWriter */
    public VersionEventWriter() {
    }
    
    public void add(XMLEvent event)
     throws XMLStreamException{
            if (event.getEventType() == XMLStreamConstants.START_DOCUMENT){
                    version = ((StartDocument)event).getVersion();
                    encoding = ((StartDocument)event).getCharacterEncodingScheme();
            }
    }

    public void flush()
       throws XMLStreamException{}

    public void close()
       throws XMLStreamException{}

    public void add(XMLEventReader reader)
     throws XMLStreamException{}

    public java.lang.String getPrefix(java.lang.String uri)
                       throws XMLStreamException{return null;}

    public void setPrefix(java.lang.String prefix,
                  java.lang.String uri)
           throws XMLStreamException{}

    public void setDefaultNamespace(java.lang.String uri)
                     throws XMLStreamException{}

    public void setNamespaceContext(NamespaceContext context)
                     throws XMLStreamException{}

    public NamespaceContext getNamespaceContext(){return null;} 
    
    public String getVersion() {
        return version;
    }
    
    public String getEncoding() {
        return encoding;
    }
}
