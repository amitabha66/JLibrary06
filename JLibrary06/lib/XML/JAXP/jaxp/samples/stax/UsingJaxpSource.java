package stax;

import java.io.File;
import java.io.FileInputStream;
import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLEventWriter;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLOutputFactory;
import javax.xml.stream.XMLStreamReader;
import javax.xml.transform.Result;
import javax.xml.transform.Source;
import javax.xml.transform.stream.StreamSource;

/*
 * UsingJaxpSource.java
 *
 * Created on June 24, 2004, 11:38 AM
 */

/**
 *
 * @author  Neeraj Bajaj, Sun Microsystems
 */
public class UsingJaxpSource {
    
    /** Creates a new instance of UsingJaxpSource */
    public UsingJaxpSource() {
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        XMLInputFactory factory = XMLInputFactory.newInstance();
        try{
            // TODO code application logic here
            StreamSource stsource = new StreamSource(new FileInputStream("../data/city.xml"));
            XMLStreamReader streamReader =  factory.createXMLStreamReader(stsource);
            while(streamReader.hasNext()){
                System.out.println(streamReader.next());
            }
        }
        catch(java.io.FileNotFoundException fne){
            fne.printStackTrace();
        }
        catch(javax.xml.stream.XMLStreamException xse){
            xse.printStackTrace();
        }
        System.out.println("------------------------");
        System.out.println("XMLStreamReader finished");
        System.out.println("------------------------");
        
        try{
            StreamSource stsource = new StreamSource("../data/city.xml");
            XMLEventReader eventReader = factory.createXMLEventReader(stsource);
            while(eventReader.hasNext()){
                System.out.println(eventReader.nextEvent());
            }
        }
        catch(javax.xml.stream.XMLStreamException xse){
            xse.printStackTrace();
        }
     
        System.out.println("------------------------");
        System.out.println("XMLEventReader finished");
        System.out.println("------------------------");
        
        try{
            Source source = new SourceImpl();
            source.setSystemId("../data/city.xml");
            XMLEventReader eventReader = factory.createXMLEventReader(source);
            while(eventReader.hasNext()){
                System.out.println(eventReader.nextEvent());
            }
        }
        catch(javax.xml.stream.XMLStreamException xse){
            xse.printStackTrace();
        }
        catch(java.lang.UnsupportedOperationException uoe){
            System.out.println("Operation not supported.");
            System.out.println("uoe.getMessage() = " + uoe.getMessage());
        }

        System.out.println("------------------------");
        System.out.println("Testing XMLEventWriter ");
        System.out.println("------------------------");
        
        try{
            Result result = new ResultImpl();
            Source source = new SourceImpl();
            source.setSystemId("../data/city.xml");
            factory.setProperty("http://java.sun.com/xml/stream/properties/report-cdata-event", Boolean.TRUE);
            XMLEventReader eventReader = factory.createXMLEventReader(source);            
            result.setSystemId("../data/city output.xml");
            XMLOutputFactory outputFactory = XMLOutputFactory.newInstance();
            XMLEventWriter eventWriter = outputFactory.createXMLEventWriter(result);
            eventWriter.add(eventReader);
            eventWriter.flush();
        }
        catch(javax.xml.stream.XMLStreamException xse){
            xse.printStackTrace();
        }
        catch(java.lang.UnsupportedOperationException uoe){
            System.out.println("Operation not supported.");
            System.out.println("uoe.getMessage() = " + uoe.getMessage());
        }
        
    }
    
    static class SourceImpl implements Source{
        public SourceImpl(){
            
        }

        String systemId ;
        public String getSystemId(){
            return systemId;
        }
        public void setSystemId(String id){
            systemId = id ;
        }
    }
    
    static class ResultImpl implements Result{
        
        String systemId ;
        public String getSystemId(){
            return systemId;
        }
        public void setSystemId(String id){
            systemId = id ;
        }
    }
    
}
