
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlType;
import com.sun.codemodel.JAnnotationWriter;
import com.sun.codemodel.JType;

public interface XmlTypeWriter
    extends JAnnotationWriter<XmlType>
{


    XmlTypeWriter name(String value);

    XmlTypeWriter namespace(String value);

    XmlTypeWriter propOrder(String value);

    XmlTypeWriter factoryClass(Class value);

    XmlTypeWriter factoryClass(JType value);

    XmlTypeWriter factoryMethod(String value);

}
