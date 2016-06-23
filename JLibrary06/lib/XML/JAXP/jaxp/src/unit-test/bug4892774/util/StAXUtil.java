/*
 * StAXUtil.java
 *
 * Created on December 20, 2005, 11:28 AM
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
import javax.xml.stream.*;
import javax.xml.transform.*;
import javax.xml.transform.stax.*;
import org.w3c.dom.*;
import org.xml.sax.*;

import junit.framework.Assert;

public class StAXUtil extends TransformerUtil{
    
    private static StAXUtil instance = null;
    
    /** Creates a new instance of StAXUtil */
    private  StAXUtil() {
    }
    
    public static synchronized StAXUtil getInstance() throws Exception{
        if (instance == null)
            instance = new StAXUtil();
        return instance;
    }
    
    public Source prepareSource(InputStream is) throws Exception{
        XMLEventReader reader = XMLInputFactory.newInstance().createXMLEventReader(is);
        return new StAXSource(reader);
    }
    
    public Result prepareResult() throws Exception {
       VersionEventWriter writer = new VersionEventWriter();
       return new StAXResult(writer);
    }
    
    public void checkResult(Result staxResult, String version) throws Exception{
        VersionEventWriter writer = (VersionEventWriter)((StAXResult)staxResult).getXMLEventWriter();
        Assert.assertTrue("Expected XML Version is 1.1, but actual version "+writer.getVersion(), writer.getVersion().equals(version));
    }
    
    public void checkResult(Result staxResult, String version, String encoding) throws Exception{
        VersionEventWriter writer = (VersionEventWriter)((StAXResult)staxResult).getXMLEventWriter();
        Assert.assertTrue("Expected XML Version is 1.1, but actual version "+writer.getVersion(), writer.getVersion().equals(version));  
        Assert.assertTrue("Expected encoding is "+encoding+", but actual encoding "+writer.getEncoding(), writer.getEncoding().equals(encoding));
    }
    
    public Source prepareStreamSource(InputStream is) throws Exception{
        XMLStreamReader reader = XMLInputFactory.newInstance().createXMLStreamReader(is);
        return new StAXSource(reader);    
    }
    
    public Result prepareStreamResult() throws Exception {
        XMLStreamWriter writer = XMLOutputFactory.newInstance().createXMLStreamWriter(new FileOutputStream(TEMP_FILE));
        return new StAXResult(writer);
    }
    
     public void checkStreamResult(Result staxResult, String version) throws Exception{
         ((StAXResult)staxResult).getXMLStreamWriter().close();
         ((StreamUtil)TransformerUtilFactory.getUtil(TransformerUtilFactory.STREAM)).checkStream(new FileInputStream(TEMP_FILE), version );
     }
}
