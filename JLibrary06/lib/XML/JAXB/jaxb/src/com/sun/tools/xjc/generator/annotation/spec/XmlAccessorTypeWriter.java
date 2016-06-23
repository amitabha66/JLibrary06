
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import com.sun.codemodel.JAnnotationWriter;

public interface XmlAccessorTypeWriter
    extends JAnnotationWriter<XmlAccessorType>
{


    XmlAccessorTypeWriter value(XmlAccessType value);

}
