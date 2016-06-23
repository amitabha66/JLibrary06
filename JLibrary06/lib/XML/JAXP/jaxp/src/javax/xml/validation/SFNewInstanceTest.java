/*
 * SFNewInstanceTest.java
 *
 * This class tests new overloaded newInstance() added in all factories.
 * New function allows application to specify factoryClassName and ClassLoader.
 * This gives more control to the application.
 *
 * JUnit based test
 *
 *
 */

package javax.xml.validation;

import javax.xml.XMLConstants;
import junit.framework.*;
import javax.xml.validation.SchemaFactory;
import junit.textui.TestRunner;

/**
 *
 * @author Neeraj Bajaj
 */
public class SFNewInstanceTest extends TestCase {
    
    public SFNewInstanceTest(String testName) {
        super(testName);
    }
    
    
    public static void main(String[] args) {
        TestRunner.run(SFNewInstanceTest.class);
    }
    
    protected void setUp() throws java.lang.Exception {
    }
    
    protected void tearDown() throws java.lang.Exception {
    }
    
    // TODO add test methods here. The name must begin with 'test'. For example:
    // public void testHello() {}
    
    public void test1(){
        try{
            //pass 'null' factoryClassName as parameter
            SchemaFactory sf = SchemaFactory.newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI,null, null);
        }catch(java.lang.IllegalArgumentException fce){
            //as expected
            return ;
        }catch(Exception e){
            e.printStackTrace();
            fail("should fail with IllegalArgumentException");
            return ;
        }
        fail("Shouldn't reach here, test should fail with IllegalArgumentException");
    }
    
    public void test2(){
        try{
            //pass arbitrary factoryClassName as parameter
            SchemaFactory sf = SchemaFactory.newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI, "foo", null);
        }catch(java.lang.IllegalArgumentException fce){
            //as expected
            return ;
        }catch(Exception e){
            e.printStackTrace();
            fail("should fail with IllegalArgumentException");
            return ;
        }
        fail("Shouldn't reach here, test should fail with IllegalArgumentException");
    }
    
    public void test3(){
        try{
            SchemaFactory sf = SchemaFactory.newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI);
            //get the class name from the old newInstance() function
            //this way it will work if the sources are renamed.
            String className = sf.getClass().getName();
            System.out.println("factory class name is = " + className);
            //now try to load the factory using new newInstance() signature className
            SchemaFactory s = SchemaFactory.newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI, className, null);
            System.out.println("s = " + s);
            if(s != null){
                return ;
            }
        }catch(java.lang.IllegalArgumentException fce){
            fce.printStackTrace();
        }catch(Exception e){
            e.printStackTrace();
        }
        fail("test routine shouldn't reach here");
    }
    
}
