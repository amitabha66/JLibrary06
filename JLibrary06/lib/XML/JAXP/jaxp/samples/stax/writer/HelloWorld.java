package stax.writer;

import java.io.FileOutputStream;
import javax.xml.stream.XMLOutputFactory;
import javax.xml.stream.XMLStreamWriter;
import java.util.Date;
import javax.xml.namespace.QName;

/**
 * HelloWorld sample is used to demonstrate the use of STAX Writer api's.
 *
 * @author <a href="mailto:Jeff.Suttor@Sun.com">Jeff Suttor</a>
 */

public class HelloWorld {
    
    private static String filename = null;
    
    private static void printUsage() {
        System.out.println("usage: java -Djava.endorsed.dirs=<jaxp dist/lib directory> stax.writer.HelloWorld -f <outputFileName>");
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
            xtw.writeStartDocument("utf-8","1.0");
            xtw.writeComment("StAX Sample: writer.HelloWorld");
            xtw.writeStartElement("hello");
            xtw.writeDefaultNamespace("http://samples");
            xtw.writeCharacters("this crazy");
            xtw.writeEmptyElement("world");
            xtw.writeEndElement();
            xtw.writeEndDocument();
            xtw.flush();
            xtw.close();
        }catch(Exception ex){
            ex.printStackTrace();
            System.err.println("Exception occurred while running Hello World samples");
        }
        System.out.println("Done");
    }
}