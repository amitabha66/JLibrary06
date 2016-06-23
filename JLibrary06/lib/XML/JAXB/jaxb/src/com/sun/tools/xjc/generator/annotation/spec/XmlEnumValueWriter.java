
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlEnumValue;
import com.sun.codemodel.JAnnotationWriter;

public interface XmlEnumValueWriter
    extends JAnnotationWriter<XmlEnumValue>
{


    XmlEnumValueWriter value(String value);

}
