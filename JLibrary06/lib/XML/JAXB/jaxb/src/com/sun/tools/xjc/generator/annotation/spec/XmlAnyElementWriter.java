
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlAnyElement;
import com.sun.codemodel.JAnnotationWriter;
import com.sun.codemodel.JType;

public interface XmlAnyElementWriter
    extends JAnnotationWriter<XmlAnyElement>
{


    XmlAnyElementWriter value(Class value);

    XmlAnyElementWriter value(JType value);

    XmlAnyElementWriter lax(boolean value);

}
