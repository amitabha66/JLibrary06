<%@ page language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="x" uri="http://java.sun.com/jstl/xml" %>
<%@ taglib prefix="p" uri="http://devsphere.com/xml/taglib/process" %>

<p:parse systemId="sample.xml" validate="false" ignoreSpaces="true">
    <p:start>
        <%-- startDocument --%>
    </p:start>
    <p:element varName="name" varAttr="attr" varDom="dom" testName="person">
        <%-- dom="..." name="person", attr.id="js890" --%>
        <%-- XPath expressions:
            $dom
                string($dom/@id)
                $dom/name
                    string($dom/name/text())
                $dom/email
                    string($dom/email/text())
                $dom/phone
                    string($dom/phone/text())
                $dom/address
                    string($dom/address/@city)
                    string($dom/address/@state)
                    string($dom/address/@zip)
                    string($dom/address/@country)
                    $dom/address/line1
                        string($dom/address/line1/text())
                    $dom/address/line2
                        string($dom/address/line2/text())
        --%>
    </p:element>
    <p:end>
        <%-- endDocument --%>
    </p:end>
</p:parse>
