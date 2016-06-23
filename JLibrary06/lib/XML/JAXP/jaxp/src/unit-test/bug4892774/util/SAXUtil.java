/*
 * SAXUtil.java
 *
 * Created on December 20, 2005, 11:12 AM
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
import javax.xml.transform.sax.*;
import org.w3c.dom.*;
import org.xml.sax.*;

import junit.framework.Assert;

public class SAXUtil extends TransformerUtil {
    
    private static SAXUtil instance = null;
    
    /** Creates a new instance of SAXUtil */
    private SAXUtil() {
        
    }
    
    public static synchronized SAXUtil getInstance() throws Exception{
        if (instance == null)
            instance = new SAXUtil();
        return instance;
    }
    
    public Source prepareSource(InputStream is) throws Exception{
        return new SAXSource(new InputSource(is));
    }
    
    public Result prepareResult() throws Exception {
       VersionDefaultHandler dh = new VersionDefaultHandler();
       return new SAXResult(dh);
    }
    
    public void checkResult(Result result, String inputVersion) throws Exception{
        String version = ((VersionDefaultHandler)((SAXResult)result).getHandler()).getVersion();
        Assert.assertTrue("Expected XML Version is 1.1, but actual version "+version, inputVersion.equals(version));
    }
    
    public void checkResult(Result result, String inputVersion, String encoding) throws Exception{
        checkResult(result, inputVersion);
        String resultEncoding = ((VersionDefaultHandler)((SAXResult)result).getHandler()).getEncoding();
        Assert.assertTrue("Expected XML Version is "+encoding+" , but actual  encoding "+resultEncoding, encoding.equals(resultEncoding));
    }
}
