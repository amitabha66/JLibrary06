/*
 * Bug.java
 *
 * Created on December 14, 2005, 5:22 PM
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package bug4892774;

import java.io.*;
import javax.xml.parsers.*;
import javax.xml.stream.*;
import javax.xml.transform.*; 
import javax.xml.transform.dom.*; 
import javax.xml.transform.sax.*;
import javax.xml.transform.stax.*;
import javax.xml.transform.stream.*; 
import org.w3c.dom.*;
import org.xml.sax.*;

import junit.framework.TestCase;
import junit.textui.TestRunner;

import bug4892774.util.*;
/**
 * This test case tests Identity transformer with all possible types of Source 
 * and Result combinations for doucment version and encoding information.
 *
 * @author Sunitha Reddy
 */
public class Bug  extends TestCase{
    
    private final String XML_FILE = "catalog.xml"; 
    private final String XML10_FILE = "catalog_10.xml";  // 1.0 version document
    private final String TEMP_FILE = "tmp.xml";
    private final String EXPECTED_VERSION = "1.1";
    static private Transformer idTransform = null;
    
    private static DOMUtil domUtil = null;
    private static StreamUtil streamUtil = null;
    private static SAXUtil saxUtil = null;
    private static StAXUtil staxUtil = null;
    
    /** Creates a new instance of Bug */
    public Bug(String name) {
        super(name);
    }
    
     public static void main(String[] args) {
    	TestRunner.run(Bug.class);
    }
     
     protected void setUp() {
         File tmpFile = new File(TEMP_FILE);
         if (tmpFile.exists())
             tmpFile.delete();
        try{ 
                 
         if (idTransform == null)
            idTransform = getIdTransformer();
         else
            idTransform.reset();
         
            initializeUtils();
        }catch(Exception e){
            e.printStackTrace();
            fail("Exception occured during setUp(): "+e.getMessage());
        }
         
     }
     
     protected void tearDown() {
         File tmpFile = new File(TEMP_FILE);
         if (tmpFile.exists())
             tmpFile.delete();
     }
     
     private void initializeUtils() throws Exception{
        if (domUtil == null)
            domUtil = (DOMUtil)TransformerUtilFactory.getUtil(TransformerUtilFactory.DOM);
        if (saxUtil == null)
            saxUtil = (SAXUtil)TransformerUtilFactory.getUtil(TransformerUtilFactory.SAX);
        if (streamUtil == null)
            streamUtil = (StreamUtil)TransformerUtilFactory.getUtil(TransformerUtilFactory.STREAM);
        if (staxUtil == null)
            staxUtil = (StAXUtil)TransformerUtilFactory.getUtil(TransformerUtilFactory.StAX);
     }
     
     public void testDOM2DOM(){
         try {
            Source input = domUtil.prepareSource(this.getClass().getResourceAsStream(XML_FILE));
            DOMResult domResult = (DOMResult)domUtil.prepareResult();
	    idTransform.transform(input, domResult);  
            domUtil.checkResult(domResult, EXPECTED_VERSION);
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
     }
         
     private Transformer getIdTransformer() throws Exception {
         return TransformerFactory.newInstance().newTransformer();
     }
     
       
     public void testDOM2Stream(){
         try {
            
     	    Source input = domUtil.prepareSource(this.getClass().getResourceAsStream(XML_FILE));
            StreamResult strResult = (StreamResult)streamUtil.prepareResult();
	    idTransform.transform(input, strResult);
            streamUtil.checkResult(strResult, EXPECTED_VERSION, "UTF-8");
          
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
     }
         
     public void testDOM2SAX() {
         try {
            Source input = domUtil.prepareSource(this.getClass().getResourceAsStream(XML_FILE));
            SAXResult saxResult = (SAXResult)saxUtil.prepareResult();
	    idTransform.transform(input, saxResult);
            saxUtil.checkResult(saxResult, EXPECTED_VERSION, "UTF-8");
         
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
     }
     
     public void testDOM2StAX() {
         try {
            Source input = domUtil.prepareSource(this.getClass().getResourceAsStream(XML_FILE));
            StAXResult staxResult = (StAXResult)staxUtil.prepareResult();
	    idTransform.transform(input, staxResult);
            staxUtil.checkResult(staxResult, EXPECTED_VERSION, "UTF-8");
                     
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
     }
       
     public void testDOM2StAXStream() {
         try {
            Source input = domUtil.prepareSource(this.getClass().getResourceAsStream(XML_FILE));
            StAXResult staxResult = (StAXResult)staxUtil.prepareStreamResult();
	    idTransform.transform(input, staxResult);
            staxUtil.checkStreamResult(staxResult, EXPECTED_VERSION);
          
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
     }
     
     public void testSAX2DOM() {
         try {
            Source input = saxUtil.prepareSource(this.getClass().getResourceAsStream(XML_FILE));
            DOMResult domResult = (DOMResult)domUtil.prepareResult();
	    idTransform.transform(input, domResult);  
            domUtil.checkResult(domResult, EXPECTED_VERSION);
           
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
     }
     
    
     public void testSAX2SAX() {
         try {
            Source input = saxUtil.prepareSource(this.getClass().getResourceAsStream(XML_FILE));
            SAXResult saxResult = (SAXResult)saxUtil.prepareResult();
	    idTransform.transform(input, saxResult);
            saxUtil.checkResult(saxResult, EXPECTED_VERSION, "UTF-8");
            
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
     }
     
     public void testSAX2Stream() {
         try {
            Source input = saxUtil.prepareSource(this.getClass().getResourceAsStream(XML_FILE));
            StreamResult strResult = (StreamResult)streamUtil.prepareResult();
	    idTransform.transform(input, strResult);
            streamUtil.checkResult(strResult, EXPECTED_VERSION, "UTF-8");
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
     }
     
     public void testSAX2StAX() {
         try {
            Source input = saxUtil.prepareSource(this.getClass().getResourceAsStream(XML_FILE));
            StAXResult staxResult = (StAXResult)staxUtil.prepareResult();
	    idTransform.transform(input, staxResult);
            staxUtil.checkResult(staxResult, EXPECTED_VERSION,"UTF-8");
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
     }
     
     public void testSAX2StAXStream() {
         try {
            Source input = saxUtil.prepareSource(this.getClass().getResourceAsStream(XML_FILE));
            StAXResult staxResult = (StAXResult)staxUtil.prepareStreamResult();
	    idTransform.transform(input, staxResult);
            staxUtil.checkStreamResult(staxResult, EXPECTED_VERSION);
                       
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
     }
       
     public void testStream2DOM() {
         try {
             Source input = streamUtil.prepareSource(this.getClass().getResourceAsStream(XML_FILE));
             DOMResult domResult = (DOMResult)domUtil.prepareResult();
             idTransform.transform(input, domResult);  
             domUtil.checkResult(domResult, EXPECTED_VERSION);
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
     }
     
     public void testStream2Stream() {
         try {
             Source input = streamUtil.prepareSource(this.getClass().getResourceAsStream(XML_FILE));
             StreamResult strResult = (StreamResult)streamUtil.prepareResult();
             idTransform.transform(input, strResult);  
             streamUtil.checkResult(strResult, EXPECTED_VERSION, "UTF-8");
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
     }
     
     public void testStream2Stax() {
         try {
             Source input = streamUtil.prepareSource(this.getClass().getResourceAsStream(XML_FILE));
             StAXResult staxResult = (StAXResult)staxUtil.prepareResult();
             idTransform.transform(input, staxResult);  
             staxUtil.checkResult(staxResult, EXPECTED_VERSION, "UTF-8");
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
     }
     
      public void testStream2StaxStream() {
         try {
             Source input = streamUtil.prepareSource(this.getClass().getResourceAsStream(XML_FILE));
             StAXResult staxResult = (StAXResult)staxUtil.prepareStreamResult();
             idTransform.transform(input, staxResult);  
             staxUtil.checkStreamResult(staxResult, EXPECTED_VERSION);
            
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
     }
      
      public void testStream2SAX() {
         try {
             Source input = streamUtil.prepareSource(this.getClass().getResourceAsStream(XML_FILE));
             SAXResult saxResult = (SAXResult)saxUtil.prepareResult();
             idTransform.transform(input, saxResult);  
             saxUtil.checkResult(saxResult, EXPECTED_VERSION,  "UTF-8");
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
     }
      
      public void testStAX2DOM() {
          try {
              Source input = staxUtil.prepareStreamSource(this.getClass().getResourceAsStream(XML10_FILE));
              DOMResult domResult = (DOMResult)domUtil.prepareResult();
              idTransform.transform(input, domResult);  
              domUtil.checkResult(domResult, "1.0");
          }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
          }
      }
              
      public void testStAX2Stream() { 
          try {
              Source input = staxUtil.prepareStreamSource(this.getClass().getResourceAsStream(XML10_FILE));
              StreamResult strResult = (StreamResult)streamUtil.prepareResult();
	      idTransform.transform(input, strResult);
              streamUtil.checkResult(strResult, "1.0", "UTF-8");
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
      }
          
      public void testStAX2StAX() {
          try {
              Source input = staxUtil.prepareStreamSource(this.getClass().getResourceAsStream(XML10_FILE));
              StAXResult staxResult = (StAXResult)staxUtil.prepareResult();
	      idTransform.transform(input, staxResult);
              staxUtil.checkResult(staxResult, "1.0", "UTF-8");
          }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
          }
      }

      public void testStAXEvent2DOM(){
          try {
              Source input = staxUtil.prepareSource(this.getClass().getResourceAsStream(XML10_FILE));
              DOMResult domResult = (DOMResult)domUtil.prepareResult();
	      idTransform.transform(input, domResult);
              domUtil.checkResult(domResult, "1.0");
          }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
          }
      }
      
      public void testStAXEvent2Stream(){
          try {
              Source input = staxUtil.prepareSource(this.getClass().getResourceAsStream(XML10_FILE));
              StreamResult strResult = (StreamResult)streamUtil.prepareResult();
	      idTransform.transform(input, strResult);
              streamUtil.checkResult(strResult, "1.0", "UTF-8");
         }catch (Exception e){
             e.printStackTrace();
             fail("Exception occured: "+e.getMessage());
         }
      }
}
