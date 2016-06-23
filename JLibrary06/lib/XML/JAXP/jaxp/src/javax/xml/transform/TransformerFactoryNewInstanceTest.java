/*
 * TransformerFactoryNewInstanceTest.java
 *
 * This class tests new overloaded newInstance() added in all factories.
 * New function allows application to specify factoryClassName and ClassLoader.
 * This gives more control to the application.
 *
 * JUnit based test
 *
 *
 */

package javax.xml.transform;

import junit.framework.*;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.TransformerFactoryConfigurationError;
import junit.textui.TestRunner;

/**
 *
 * @author Neeraj Bajaj
 */
public class TransformerFactoryNewInstanceTest extends TestCase {
    
    public TransformerFactoryNewInstanceTest(String testName) {
        super(testName);
    }
    
    
    public static void main(String[] args) {
        TestRunner.run(TransformerFactoryNewInstanceTest.class);
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
            TransformerFactory sf = TransformerFactory.newInstance(null, null);
        }catch(TransformerFactoryConfigurationError fce){
            //as expected
            return ;
        }catch(Exception e){
            e.printStackTrace();
            fail("should fail with TransformerConfigurationException");
            return ;
        }
        fail("Shouldn't reach here, test should fail with TransformerConfigurationException");
    }
    
    public void test2(){
        try{
            //pass arbitrary factoryClassName as parameter
            TransformerFactory sf = TransformerFactory.newInstance("foo", null);
        }catch(TransformerFactoryConfigurationError fce){
            //as expected
            return;
        }catch(Exception e){
            e.printStackTrace();
            fail("should fail with TransformerConfigurationException");
            return;
        }
        
        fail("Shouldn't reach here, test should fail with TransformerConfigurationException");
    }
    
    public void test3(){
        try{
            TransformerFactory sf = TransformerFactory.newInstance();
            //get the class name from the old newInstance() function
            //this way it will work if the sources are renamed.
            String className = sf.getClass().getName();
            System.out.println("factory class name is = " + className);
            //now try to load the factory using new newInstance() signature className
            TransformerFactory s = TransformerFactory.newInstance(className, null);
            System.out.println("s = " + s);
            if(s != null){
                return ;
            }
        }catch(TransformerFactoryConfigurationError fce){
            fce.printStackTrace();
        }catch(Exception e){
            e.printStackTrace();
        }
        fail("test routine shouldn't reach here");
    }
    
}
