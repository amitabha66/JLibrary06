/*
 * The contents of this file are subject to the terms
 * of the Common Development and Distribution License
 * (the "License").  You may not use this file except
 * in compliance with the License.
 * 
 * You can obtain a copy of the license at
 * https://jwsdp.dev.java.net/CDDLv1.0.html
 * See the License for the specific language governing
 * permissions and limitations under the License.
 * 
 * When distributing Covered Code, include this CDDL
 * HEADER in each file and include the License file at
 * https://jwsdp.dev.java.net/CDDLv1.0.html  If applicable,
 * add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your
 * own identifying information: Portions Copyright [yyyy]
 * [name of copyright owner]
 */
package com.sun.tools.xjc.reader.dtd.bindinfo;

import java.util.ArrayList;

import com.sun.tools.xjc.generator.bean.field.FieldRenderer;
import com.sun.tools.xjc.generator.bean.field.FieldRendererFactory;

import org.w3c.dom.Attr;
import org.w3c.dom.Element;

/** &lt;attribute> declaration in the binding file. */
public class BIAttribute
{
    /**
     * Wraps a given &lt;attribute> element.
     * <p>
     * Should be created only from {@link BIElement}.
     */
    BIAttribute( BIElement _parent, Element _e ) {
        this.parent = _parent;
        this.element = _e;
    }
    
    private final BIElement parent;
    private final Element element;

    /** Gets the name of this attribute-property declaration. */
    public final String name() {
        return element.getAttribute("name");
    }
    
    
    /**
     * Gets the conversion method for this attribute, if any.
     * 
     * @return
     *        If the convert attribute is not specified, this
     *        method returns null.
     */
    public BIConversion getConversion() {
        if (element.getAttributeNode("convert") == null)
            return null;

        String cnv = element.getAttribute("convert");
        return parent.conversion(cnv);
    }

    /**
     * Gets the realization of this particle, if any.
     * 
     * @return
     *      null if the "collection" attribute was not specified.
     */
    public final FieldRenderer getRealization() {
        Attr a = element.getAttributeNode("collection");
        if(a==null)     return null;
        
        String v = element.getAttribute("collection").trim();

        FieldRendererFactory frf = parent.parent.model.options.getFieldRendererFactory();
        if(v.equals("array"))   return frf.getArray();
        if(v.equals("list"))
            return frf.getList(
                parent.parent.codeModel.ref(ArrayList.class));
        
        // the correctness of the attribute value must be 
        // checked by the validator.
        throw new InternalError("unexpected collection value: "+v);
    }
    
    /**
     * Gets the property name for this attribute.
     * 
     * @return
     *      always a non-null, valid string.
     */
    public final String getPropertyName() {
        String r = DOMUtil.getAttribute(element,"property");
        if(r!=null)     return r;
        else            return name();
    }
}
