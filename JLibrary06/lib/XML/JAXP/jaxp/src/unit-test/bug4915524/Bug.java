package bug4915524;
/**
 *
 * @author Sunitha Reddy
 */

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import org.xml.sax.InputSource;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import java.io.StringReader;

import junit.framework.TestCase;
import junit.textui.TestRunner;

public class Bug extends TestCase{

    String data = 
          "<?xml version=\"1.0\" ?>"
        + "<!DOCTYPE root ["
        + "<!ELEMENT root ANY>"
        + "<!ATTLIST root attr1 ID #FIXED 'xxx'" 
        + "               attr2 CDATA #IMPLIED> "
        + "]>"
        + "<root attr2='yyy'/>";
      
    DocumentBuilder docBuilder = null;

    public static void main(String argv[]) {
       TestRunner.run(Bug.class);
    }
    
    /* This method tries to adopt a node from Defered document to non-defered document.
     */
    public void testAdoptNode() {
        try {
            DocumentBuilderFactory docBF = DocumentBuilderFactory.newInstance();
            docBuilder = docBF.newDocumentBuilder();
            
            Document doc1 = parse(data);
            Document doc2 = docBuilder.newDocument();
            
            Node element = doc2.adoptNode(doc1.getDocumentElement());
            
            System.out.println("OK.");
        } catch (Exception e) {
            e.printStackTrace();
            fail("Excpetion while adopting node: " +e.getMessage());
        }

    }
    
    private Document parse(String xmlData) throws Exception {
         StringReader in = new StringReader(xmlData);
         InputSource source = new InputSource(in);
         return docBuilder.parse(source);
    }
}