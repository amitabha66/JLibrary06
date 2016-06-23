
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlMimeType;
import com.sun.codemodel.JAnnotationWriter;

public interface XmlMimeTypeWriter
    extends JAnnotationWriter<XmlMimeType>
{


    XmlMimeTypeWriter value(String value);

}
