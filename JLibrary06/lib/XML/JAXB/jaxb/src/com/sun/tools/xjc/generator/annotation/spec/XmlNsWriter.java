
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlNs;
import com.sun.codemodel.JAnnotationWriter;

public interface XmlNsWriter
    extends JAnnotationWriter<XmlNs>
{


    XmlNsWriter prefix(String value);

    XmlNsWriter namespaceURI(String value);

}
