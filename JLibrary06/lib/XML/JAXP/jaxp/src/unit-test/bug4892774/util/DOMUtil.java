/*
 * DOMUtil.java
 *
 * Created on December 19, 2005, 6:45 PM
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package bug4892774.util;

/**
 *
 * @author Sunitha Reddy
 */
import java.io.*;

import javax.xml.parsers.*;
import javax.xml.transform.*;
import javax.xml.transform.dom.*;
import org.w3c.dom.*;
import org.xml.sax.*;

import junit.framework.Assert;

public class DOMUtil extends TransformerUtil{
    
    DocumentBuilder docBuilder = null;
    
    private static DOMUtil instance = null;
    
    /** Creates a new instance of DOMUtil */
    private DOMUtil() throws Exception{
        if (docBuilder == null)
            docBuilder = getDomParser();
    }
    
    public static synchronized DOMUtil getInstance() throws Exception{
        if (instance == null)
            instance = new DOMUtil();
        return instance;
    }
    
    public Source prepareSource(InputStream is) throws Exception{
        docBuilder.reset();
        Document doc1 = docBuilder.parse(is);
        return new DOMSource(doc1);
    }
    
    public Result prepareResult(){
        Document target = docBuilder.newDocument();
     	return new DOMResult(target);
    }
    
    public void checkResult(Result result, String version){
        String resultVersion = ((Document)((DOMResult)result).getNode()).getXmlVersion();
	Assert.assertTrue("Expected XML Version is 1.1, but actual version "+resultVersion, version.equals(resultVersion));
    }
}
