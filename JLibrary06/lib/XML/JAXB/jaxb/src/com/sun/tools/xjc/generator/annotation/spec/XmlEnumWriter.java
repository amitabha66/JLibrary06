
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlEnum;
import com.sun.codemodel.JAnnotationWriter;
import com.sun.codemodel.JType;

public interface XmlEnumWriter
    extends JAnnotationWriter<XmlEnum>
{


    XmlEnumWriter value(Class value);

    XmlEnumWriter value(JType value);

}
