
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlNsForm;
import javax.xml.bind.annotation.XmlSchema;
import com.sun.codemodel.JAnnotationWriter;

public interface XmlSchemaWriter
    extends JAnnotationWriter<XmlSchema>
{


    XmlSchemaWriter location(String value);

    XmlSchemaWriter namespace(String value);

    XmlNsWriter xmlns();

    XmlSchemaWriter elementFormDefault(XmlNsForm value);

    XmlSchemaWriter attributeFormDefault(XmlNsForm value);

}
