package stax.stream;

import java.io.*;
import java.nio.MappedByteBuffer;
import java.nio.channels.FileChannel;
import javax.xml.stream.*;
import javax.xml.stream.events.* ;
import java.util.Date;
import javax.xml.namespace.QName;

/**
 * MyNamespaceFilter sample is used to demonstrates the use
 * of STAX stream filter api's. This filter accepts only
 * StartElement events that belong to a particular namespace and filters out rest of
 * the events.
 */

public class MyStreamReader {
    
    private static String filename = null;
    
    
    private static void printUsage() {
        System.out.println("usage: java -Djava.endorsed.dirs=<jaxp dist/lib directory> stax.stream.MyStreamReader <xmlfile>");
    }
    
    /**
     * 
     * @param args 
     * @throws Exception 
     */
    public static void main(String[] args) throws Exception {
                
        if (args.length != 1) {
            printUsage() ;
        }
        
        filename = args[0];
        
        XMLInputFactory xmlif = null ;
        try{
            xmlif = XMLInputFactory.newInstance();
            xmlif.setProperty(XMLInputFactory.IS_REPLACING_ENTITY_REFERENCES,Boolean.TRUE);
            xmlif.setProperty(XMLInputFactory.IS_SUPPORTING_EXTERNAL_ENTITIES,Boolean.FALSE);
            xmlif.setProperty(XMLInputFactory.IS_NAMESPACE_AWARE , Boolean.TRUE);
            xmlif.setProperty(XMLInputFactory.IS_COALESCING , Boolean.TRUE);
        }catch(Exception ex){
            ex.printStackTrace();
        }
        System.out.println("XMLInputFactory: " + xmlif);
        System.out.println("filename = "+ filename);
                
        
        XMLStreamReader xmlr = null;
        try {
            
            FileInputStream fis = new FileInputStream(filename);
            
            xmlr = xmlif.createXMLStreamReader(fis);
                        
        } catch(Exception ex) {
            ex.printStackTrace();
        }
        
        for (int event = xmlr.next(); event != XMLStreamConstants.END_DOCUMENT; event = xmlr.next()) {
            if (event == XMLStreamConstants.START_ELEMENT) {
              String element = xmlr.getLocalName();
            }
        }
    }

    
    
    
    private static void printAttributes(XMLStreamReader xmlr) {
        
        if (xmlr.getAttributeCount() > 0) {
            
            int count = xmlr.getAttributeCount() ;
            for(int i = 0 ; i < count ; i++) {
                
                QName name = xmlr.getAttributeName(i) ;
                String namespace = xmlr.getAttributeNamespace(i) ;
                String  type = xmlr.getAttributeType(i) ;
                String prefix = xmlr.getAttributePrefix(i) ;
                String value = xmlr.getAttributeValue(i) ;
                
                System.out.println("\tAttribute: {" + namespace + "}:" + name.toString() + "(" + type + ")=" + value);
            }
        }
    }
}
