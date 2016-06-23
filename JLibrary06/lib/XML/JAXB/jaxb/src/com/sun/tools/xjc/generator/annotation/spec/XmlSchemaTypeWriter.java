
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlSchemaType;
import com.sun.codemodel.JAnnotationWriter;
import com.sun.codemodel.JType;

public interface XmlSchemaTypeWriter
    extends JAnnotationWriter<XmlSchemaType>
{


    XmlSchemaTypeWriter name(String value);

    XmlSchemaTypeWriter type(Class value);

    XmlSchemaTypeWriter type(JType value);

    XmlSchemaTypeWriter namespace(String value);

}
