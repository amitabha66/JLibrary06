
package com.sun.tools.xjc.generator.annotation.spec;

import javax.xml.bind.annotation.XmlAccessOrder;
import javax.xml.bind.annotation.XmlAccessorOrder;
import com.sun.codemodel.JAnnotationWriter;

public interface XmlAccessorOrderWriter
    extends JAnnotationWriter<XmlAccessorOrder>
{


    XmlAccessorOrderWriter value(XmlAccessOrder value);

}
