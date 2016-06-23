
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.adapters.XmlJavaTypeAdapter;
import com.sun.codemodel.JAnnotationWriter;
import com.sun.codemodel.JType;

public interface XmlJavaTypeAdapterWriter
    extends JAnnotationWriter<XmlJavaTypeAdapter>
{


    XmlJavaTypeAdapterWriter value(Class value);

    XmlJavaTypeAdapterWriter value(JType value);

    XmlJavaTypeAdapterWriter type(Class value);

    XmlJavaTypeAdapterWriter type(JType value);

}
