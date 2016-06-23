/*
 * TransformerUtil.java
 *
 * Created on December 19, 2005, 6:42 PM
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

import javax.xml.parsers.*;
import javax.xml.transform.*;

import java.io.*;

public abstract class TransformerUtil {
    
    protected String type;
    
    protected final String TEMP_FILE = "tmp.xml";
    
    public abstract Source prepareSource(InputStream is) throws Exception;
    
    public abstract Result prepareResult() throws Exception;
    
    public abstract void checkResult(Result result, String version) throws Exception;
    
    public void checkResult(Result result, String version, String encoding) throws Exception{
        checkResult(result, version);
    }
    
    public DocumentBuilder getDomParser() throws Exception {
         DocumentBuilderFactory docBF = DocumentBuilderFactory.newInstance();
         return docBF.newDocumentBuilder();
    }
}
