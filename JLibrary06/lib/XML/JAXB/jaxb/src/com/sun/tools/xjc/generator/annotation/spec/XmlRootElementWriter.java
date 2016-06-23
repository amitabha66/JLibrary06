
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlRootElement;
import com.sun.codemodel.JAnnotationWriter;

public interface XmlRootElementWriter
    extends JAnnotationWriter<XmlRootElement>
{


    XmlRootElementWriter name(String value);

    XmlRootElementWriter namespace(String value);

}
