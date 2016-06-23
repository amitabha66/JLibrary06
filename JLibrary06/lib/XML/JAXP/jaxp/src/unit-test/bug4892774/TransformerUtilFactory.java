/*
 * TransformerUtilFactory.java
 *
 * Created on December 19, 2005, 7:07 PM
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package bug4892774;

/**
 *
 * @author Sunitha Reddy
 */

import bug4892774.util.*;

public class TransformerUtilFactory {
    
    public final static String DOM = "dom";
    
    public final static String SAX = "sax";
    
    public final static String StAX = "stax";
    
    public final static String STREAM = "stream";
    
    /** Creates a new instance of TransformerUtilFactory */
    private TransformerUtilFactory() {
    }
    
    public static TransformerUtil getUtil(String type) throws Exception{
        if (type.equals(DOM)){
            return DOMUtil.getInstance();
        }
        else if (type.equals(STREAM))
            return StreamUtil.getInstance();
        else if (type.equals(SAX))
            return SAXUtil.getInstance();
        else if (type.equals(StAX))
            return StAXUtil.getInstance();
        else
            return null;
    }
        
}
