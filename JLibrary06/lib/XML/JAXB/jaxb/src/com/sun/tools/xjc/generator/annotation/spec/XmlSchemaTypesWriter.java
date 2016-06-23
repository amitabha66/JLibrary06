
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlSchemaTypes;
import com.sun.codemodel.JAnnotationWriter;

public interface XmlSchemaTypesWriter
    extends JAnnotationWriter<XmlSchemaTypes>
{


    XmlSchemaTypeWriter value();

}
