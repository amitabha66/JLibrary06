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
        <p:element varName="name" varAttr="attr" testName="email">
            <p:start>
                <%-- startElement name="email" --%>
            </p:start>
            <p:data varData="data">
                <%-- characters data="John.Smith@yahoo.com" --%>
            </p:data>
            <p:end>
                <%-- endElement name="email" --%>
            </p:end>
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
        <p:element varName="name" varAttr="attr" testName="address">
            <p:start>
                <%-- startElement name="address", attr.city="Palo Alto", attr.state="CA", attr.zip="94303", attr.country="USA" --%>
            </p:start>
            <p:element varName="name" varAttr="attr" testName="line1">
                <p:start>
                    <%-- startElement name="line1" --%>
                </p:start>
                <p:data varData="data">
                    <%-- characters data="JS Information Systems, Inc." --%>
                </p:data>
                <p:end>
                    <%-- endElement name="line1" --%>
                </p:end>
            </p:element>
            <p:element varName="name" varAttr="attr" testName="line2">
                <p:start>
                    <%-- startElement name="line2" --%>
                </p:start>
                <p:data varData="data">
                    <%-- characters data="1001 San Antonio Road" --%>
                </p:data>
                <p:end>
                    <%-- endElement name="line2" --%>
                </p:end>
            </p:element>
            <p:end>
                <%-- endElement name="address" --%>
            </p:end>
        </p:element>
        <p:end>
            <%-- endElement name="person" --%>
        </p:end>
    </p:element>
    <p:end>
        <%-- endDocument --%>
    </p:end>
</p:parse>
