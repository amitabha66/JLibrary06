import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import junit.framework.TestCase;
import junit.textui.TestRunner;

import org.w3c.dom.CDATASection;
import org.w3c.dom.DOMConfiguration;
import org.w3c.dom.DOMError;
import org.w3c.dom.DOMErrorHandler;
import org.w3c.dom.Document;

public class Bug4915748 extends TestCase {
      
    public static void main(String argv[]) {
        TestRunner.run(Bug4915748.class);
    }
    
    public void testMain() throws Exception {
        final boolean[] hadError = new boolean[1];
        
        DocumentBuilderFactory docBF = DocumentBuilderFactory.newInstance();
        DocumentBuilder docBuilder = docBF.newDocumentBuilder();
        
        Document doc = docBuilder.getDOMImplementation()
                       .createDocument("namespaceURI", "ns:root", null);;
        
        CDATASection cdata = doc.createCDATASection("text1]]>text2");
        doc.getDocumentElement().appendChild(cdata);
        
        DOMConfiguration config = doc.getDomConfig();
        DOMErrorHandler erroHandler = new DOMErrorHandler() {
            public boolean handleError(DOMError error) {
                System.out.println(error.getMessage());
                assertEquals("cdata-sections-splitted",error.getType());
                assertFalse("two errors were reported",hadError[0]);
                hadError[0] = true;
                return false;
            }
        };
        config.setParameter("error-handler", erroHandler);
        doc.normalizeDocument();
        assertTrue(hadError[0]);
    }
}