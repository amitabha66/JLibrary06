
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlSeeAlso;
import com.sun.codemodel.JAnnotationWriter;
import com.sun.codemodel.JType;

public interface XmlSeeAlsoWriter
    extends JAnnotationWriter<XmlSeeAlso>
{


    XmlSeeAlsoWriter value(Class value);

    XmlSeeAlsoWriter value(JType value);

}
