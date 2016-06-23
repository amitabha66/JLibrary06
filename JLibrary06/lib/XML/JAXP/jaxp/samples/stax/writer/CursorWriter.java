package stax.writer;

import java.io.FileOutputStream;
import javax.xml.stream.XMLOutputFactory;
import javax.xml.stream.XMLStreamWriter;
import java.util.Date;
import javax.xml.namespace.QName;

/**
 * CursorWriter sample is used to demonstrate the use of STAX Writer api's.
 *
 * @author k.venugopal@sun.com
 */

public class CursorWriter {
    
    private static String filename = null;
    
    private static void printUsage() {
        System.out.println("usage: java -Djava.endorsed.dirs=<jaxp dist/lib directory> stax.writer.CursorWriter -f <outputFileName>");
    }
    
    /**
     * @param args
     * @throws Exception
     */
    public static void main(String[] args) throws Exception {
        try{
            String fileName = null;
            try{
                if(args[0].equals("-f")){
                    fileName = args[1];
                }
                else{
                    printUsage() ;
                    return;
                }
            }catch(Exception ex){
                printUsage() ;
                return;
            }
            
            XMLOutputFactory xof =  XMLOutputFactory.newInstance();
            XMLStreamWriter xtw = null;
            xtw = xof.createXMLStreamWriter(new FileOutputStream(fileName),"utf-8"); 
            xtw.writeComment("all elements here are explicitly in the HTML namespace");
            xtw.writeStartDocument("utf-8","1.0");
            xtw.setPrefix("html", "http://www.w3.org/TR/REC-html40");
            xtw.writeStartElement("http://www.w3.org/TR/REC-html40","html");
            xtw.writeNamespace("html", "http://www.w3.org/TR/REC-html40");
            xtw.writeStartElement("http://www.w3.org/TR/REC-html40","head");
            xtw.writeStartElement("http://www.w3.org/TR/REC-html40","title");
            xtw.writeCharacters("Frobnostication");
            xtw.writeEndElement();
            xtw.writeEndElement();
            xtw.writeStartElement("http://www.w3.org/TR/REC-html40","body");
            xtw.writeStartElement("http://www.w3.org/TR/REC-html40","p");
            xtw.writeCharacters("Moved to");
            xtw.writeStartElement("http://www.w3.org/TR/REC-html40","a");
            xtw.writeAttribute("href","http://frob.com");
            xtw.writeCharacters("here");
            xtw.writeEndElement();
            xtw.writeEndElement();
            xtw.writeEndElement();
            xtw.writeEndElement();
            xtw.writeEndDocument();
            xtw.flush();
            xtw.close();
        }catch(Exception ex){
            ex.printStackTrace();
            System.err.println("Exception occurred while running writer samples");
        }
        System.out.println("Done");
    }
}