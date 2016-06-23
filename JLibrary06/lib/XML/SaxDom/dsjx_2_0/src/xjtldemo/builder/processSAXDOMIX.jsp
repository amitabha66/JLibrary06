<%@ page language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="x" uri="http://java.sun.com/jstl/xml" %>
<%@ taglib prefix="p" uri="http://devsphere.com/xml/taglib/process" %>

<p:parse systemId="sample.xml" validate="false" ignoreSpaces="true">
    <p:start>
        <%-- startDocument --%>
    </p:start>
    <p:element varName="name" varAttr="attr" testName="person">
        <p:start>
            <%-- startElement name="person", attr.id="js890" --%>
        </p:start>
        <p:element varName="name" varAttr="attr" testName="name">
            <p:start>
                <%-- startElement name="name" --%>
            </p:start>
            <p:data varData="data">
                <%-- characters data="John Smith" --%>
            </p:data>
            <p:end>
                <%-- endElement name="name" --%>
            </p:end>
        </p:element>
        <p:element varName="name" varAttr="attr" varDom="dom" testName="email">
            <%-- dom="..." name="email" --%>
            <%-- XPath expressions:
                $dom
                    string($dom/text())
            --%>
        </p:element>
        <p:element varName="name" varAttr="attr" testName="phone">
            <p:start>
                <%-- startElement name="phone" --%>
            </p:start>
            <p:data varData="data">
                <%-- characters data="650-123-4567" --%>
            </p:data>
            <p:end>
                <%-- endElement name="phone" --%>
            </p:end>
        </p:element>
        <p:element varName="name" varAttr="attr" varDom="dom" testName="address">
            <%-- dom="..." name="address", attr.city="Palo Alto", attr.state="CA", attr.zip="94303", attr.country="USA" --%>
            <%-- XPath expressions:
                $dom
                    string($dom/@city)
                    string($dom/@state)
                    string($dom/@zip)
                    string($dom/@country)
                    $dom/line1
                        string($dom/line1/text())
                    $dom/line2
                        string($dom/line2/text())
            --%>
        </p:element>
        <p:end>
            <%-- endElement name="person" --%>
        </p:end>
    </p:element>
    <p:end>
        <%-- endDocument --%>
    </p:end>
</p:parse>
