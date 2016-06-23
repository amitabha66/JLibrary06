
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlElementRefs;
import com.sun.codemodel.JAnnotationWriter;

public interface XmlElementRefsWriter
    extends JAnnotationWriter<XmlElementRefs>
{


    XmlElementRefWriter value();

}
