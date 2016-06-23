
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlElement;
import com.sun.codemodel.JAnnotationWriter;
import com.sun.codemodel.JType;

public interface XmlElementWriter
    extends JAnnotationWriter<XmlElement>
{


    XmlElementWriter name(String value);

    XmlElementWriter type(Class value);

    XmlElementWriter type(JType value);

    XmlElementWriter namespace(String value);

    XmlElementWriter defaultValue(String value);

    XmlElementWriter required(boolean value);

    XmlElementWriter nillable(boolean value);

}
