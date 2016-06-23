package stax;

import javax.xml.stream.*;
import javax.xml.stream.events.*;

import java.io.*;

public class jsr173client {

static String filename;

  public static void main(String[] args) throws Exception {
    
    filename = args[0];

    // create XMLInputFactory
    System.out.println("Getting XMLInputFactory...");
    XMLInputFactory xmlif = XMLInputFactory.newInstance();
    System.out.println("XMLInputFactory == " + xmlif );

    
    int state = -1;
    
System.out.println("Warming up for 100 parse ");

for(int i = 0 ; i < 100 ; i++) {

    //System.out.println("Getting XMLStreamReader...");
    XMLStreamReader xmlr = xmlif.createXMLStreamReader(new FileInputStream(filename));    
    //System.out.println("Got XMLStreamReader.");
        
    while(xmlr.hasNext()){
        state = xmlr.next();

    }

}

System.out.println("Finished warming for 100 parse ");

long timeBefore = System.currentTimeMillis();

for(int i = 0 ; i < 100 ; i++) {

    XMLStreamReader xmlr = xmlif.createXMLStreamReader(new FileInputStream(filename));    
        
    while(xmlr.hasNext()){

        state = xmlr.next();
    }
}
    
    long timeAfter = System.currentTimeMillis();
    System.out.println("Total time = " + (timeAfter - timeBefore) );
    System.out.println("Time per parse = " + (timeAfter - timeBefore) / 100 ); 
  
  }
  
  public final static String getEventTypeString(int eventType) {
    switch (eventType){
    case XMLEvent.START_DOCUMENT:
      return "START_DOCUMENT";
    case XMLEvent.END_DOCUMENT:
      return "END_DOCUMENT";
    case XMLEvent.START_ELEMENT:
      return "START_ELEMENT";
    case XMLEvent.END_ELEMENT:
      return "END_ELEMENT";
    case XMLEvent.PROCESSING_INSTRUCTION:
      return "PROCESSING_INSTRUCTION";
    case XMLEvent.CHARACTERS:
      return "CHARACTERS";
    case XMLEvent.COMMENT:
      return "COMMENT";

    }
    return "UNKNOWN_EVENT_TYPE";
  }

  private static void printEventType(int eventType) {
    System.out.print("EVENT TYPE("+eventType+"):");
    System.out.println(getEventTypeString(eventType));
  }

}