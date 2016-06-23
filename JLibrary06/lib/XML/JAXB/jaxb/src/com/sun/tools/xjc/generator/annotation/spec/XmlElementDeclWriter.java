
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlElementDecl;
import com.sun.codemodel.JAnnotationWriter;
import com.sun.codemodel.JType;

public interface XmlElementDeclWriter
    extends JAnnotationWriter<XmlElementDecl>
{


    XmlElementDeclWriter name(String value);

    XmlElementDeclWriter namespace(String value);

    XmlElementDeclWriter defaultValue(String value);

    XmlElementDeclWriter scope(Class value);

    XmlElementDeclWriter scope(JType value);

    XmlElementDeclWriter substitutionHeadNamespace(String value);

    XmlElementDeclWriter substitutionHeadName(String value);

}
