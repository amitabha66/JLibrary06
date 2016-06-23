
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlAttribute;
import com.sun.codemodel.JAnnotationWriter;

public interface XmlAttributeWriter
    extends JAnnotationWriter<XmlAttribute>
{


    XmlAttributeWriter name(String value);

    XmlAttributeWriter namespace(String value);

    XmlAttributeWriter required(boolean value);

}
