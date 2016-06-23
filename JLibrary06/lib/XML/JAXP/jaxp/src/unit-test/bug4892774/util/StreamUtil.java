/*
 * StreamUtil.java
 *
 * Created on December 19, 2005, 7:58 PM
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
import bug4892774.*;

import java.io.*;
import javax.xml.parsers.*;
import javax.xml.transform.*;
import javax.xml.transform.stream.*;
import org.w3c.dom.*;

import junit.framework.Assert;

public class StreamUtil extends TransformerUtil{
    
    DocumentBuilder docBuilder = null;
    
    private static StreamUtil instance = null;
    
    /** Creates a new instance of StreamUtil */
    private StreamUtil() throws Exception {
        if (docBuilder == null)
            docBuilder = getDomParser();
    }
    
    public static synchronized StreamUtil getInstance() throws Exception{
        if (instance == null)
            instance = new StreamUtil();
        return instance;
    }
    
    public Source prepareSource(InputStream is) throws Exception{
        return new StreamSource(is);
    }
    
    public Result prepareResult() throws Exception {
       FileOutputStream fos = new FileOutputStream(TEMP_FILE);
       return new StreamResult(fos);
    }
    
    public void checkResult(Result result, String inputVersion) throws Exception{
        ((StreamResult)result).getOutputStream().close();
        FileInputStream fis = new FileInputStream(TEMP_FILE);
        checkStream(fis, inputVersion);
    }
    
    public void checkStream(FileInputStream fis, String inputVersion) throws Exception{
        docBuilder.reset();
        Document output = docBuilder.parse(fis);
        String version = output.getXmlVersion();
        Assert.assertTrue("Expected XML Version is 1.1, but actual version "+version, inputVersion.equals(version));
    }
    
    public void checkResult(Result result, String version, String encoding) throws Exception{
        //use sax parser, as encoding info cannot be set on DOM document  
          SAXParser parser = SAXParserFactory.newInstance().newSAXParser();
          VersionDefaultHandler dh = new VersionDefaultHandler();
          parser.parse(new File(TEMP_FILE), dh);
          Assert.assertTrue("Expected version is "+version+" actual version "+dh.getVersion(), dh.getVersion().equals(version));
          Assert.assertTrue("Expected version is "+encoding+" actual version "+dh.getEncoding(), dh.getEncoding().equals(encoding));
    }
}
