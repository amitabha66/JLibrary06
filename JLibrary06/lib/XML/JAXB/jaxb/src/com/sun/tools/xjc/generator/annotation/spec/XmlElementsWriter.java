
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlElements;
import com.sun.codemodel.JAnnotationWriter;

public interface XmlElementsWriter
    extends JAnnotationWriter<XmlElements>
{


    XmlElementWriter value();

}
