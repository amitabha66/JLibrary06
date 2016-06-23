
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlElementRef;
import com.sun.codemodel.JAnnotationWriter;
import com.sun.codemodel.JType;

public interface XmlElementRefWriter
    extends JAnnotationWriter<XmlElementRef>
{


    XmlElementRefWriter name(String value);

    XmlElementRefWriter type(Class value);

    XmlElementRefWriter type(JType value);

    XmlElementRefWriter namespace(String value);

}
