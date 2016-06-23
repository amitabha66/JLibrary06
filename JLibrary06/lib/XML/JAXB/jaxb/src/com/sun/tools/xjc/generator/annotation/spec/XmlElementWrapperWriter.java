
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlElementWrapper;
import com.sun.codemodel.JAnnotationWriter;

public interface XmlElementWrapperWriter
    extends JAnnotationWriter<XmlElementWrapper>
{


    XmlElementWrapperWriter name(String value);

    XmlElementWrapperWriter namespace(String value);

    XmlElementWrapperWriter required(boolean value);

    XmlElementWrapperWriter nillable(boolean value);

}
