package com.sun.tools.xjc.api.impl.s2j;

import javax.xml.namespace.QName;

import com.sun.codemodel.JCodeModel;
import com.sun.codemodel.JType;
import com.sun.tools.xjc.api.Mapping;
import com.sun.tools.xjc.api.Property;
import com.sun.tools.xjc.outline.FieldOutline;

/**
 * @author Kohsuke Kawaguchi
 */
public /*for BSH*/ final class PropertyImpl implements Property {
    protected final FieldOutline fr;
    protected final QName elementName;
    protected final Mapping parent;
    protected final JCodeModel codeModel;

    PropertyImpl( Mapping parent, FieldOutline fr, QName elementName ) {
        this.parent = parent;
        this.fr = fr;
        this.elementName = elementName;
        this.codeModel = fr.getRawType().owner();
    }

    public final String name() {
        return fr.getPropertyInfo().getName(false);
    }

    public final QName elementName() {
        return elementName;
    }

    public final JType type() {
        return fr.getRawType();
    }
}
