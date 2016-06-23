/*
 * XPathFactoryNewInstanceTest.java
 *
 * This class tests new overloaded newInstance() added in all factories.
 * New function allows application to specify factoryClassName and ClassLoader.
 * This gives more control to the application.
 *
 * JUnit based test
 *
 *
 */

package javax.xml.xpath;

import junit.framework.*;
import javax.xml.xpath.XPathFactory;
import javax.xml.xpath.XPathFactoryConfigurationException;
import junit.textui.TestRunner;

/**
 *
 * @author Neeraj Bajaj
 */
public class XPathFactoryNewInstanceTest extends TestCase {
    
    public XPathFactoryNewInstanceTest(String testName) {
        super(testName);
    }
    
    
    public static void main(String[] args) {
        TestRunner.run(XPathFactoryNewInstanceTest.class);
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
            XPathFactory sf = XPathFactory.newInstance(XPathFactory.DEFAULT_OBJECT_MODEL_URI, null, null);
        }catch(XPathFactoryConfigurationException fce){
            //as expected
            return ;
        }catch(Exception e){
            e.printStackTrace();
            fail("should fail with XPathFactoryConfigurationException");
            return ;
        }
        fail("Shouldn't reach here, test should fail with XPathFactoryConfigurationException");
    }
    
    public void test2(){
        try{
            //pass arbitrary factoryClassName as parameter
            XPathFactory sf = XPathFactory.newInstance(XPathFactory.DEFAULT_OBJECT_MODEL_URI, "foo", null);
        }catch(XPathFactoryConfigurationException fce){
            //as expected
            return;
        }catch(Exception e){
            e.printStackTrace();
            fail("should fail with XPathFactoryConfigurationException");
            return;
        }
        
        fail("Shouldn't reach here, test should fail with XPathFactoryConfigurationException");
    }
    
    public void test3(){
        try{
            XPathFactory sf = XPathFactory.newInstance();
            //get the class name from the old newInstance() function
            //this way it will work if the sources are renamed.
            String className = sf.getClass().getName();
            System.out.println("factory class name is = " + className);
            //now try to load the factory using new newInstance() signature className
            XPathFactory s = XPathFactory.newInstance(XPathFactory.DEFAULT_OBJECT_MODEL_URI, className, null);
            System.out.println("s = " + s);
            if(s != null){
                return ;
            }
        }catch(XPathFactoryConfigurationException fce){
            fce.printStackTrace();
        }catch(Exception e){
            e.printStackTrace();
        }
        fail("test routine shouldn't reach here");
    }
    
}
