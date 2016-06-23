
package com.sun.tools.xjc.generator.annotation.ri;

import com.sun.codemodel.JAnnotationWriter;
import com.sun.xml.bind.annotation.XmlIsSet;

public interface XmlIsSetWriter
    extends JAnnotationWriter<XmlIsSet>
{


    XmlIsSetWriter value(String value);

}
