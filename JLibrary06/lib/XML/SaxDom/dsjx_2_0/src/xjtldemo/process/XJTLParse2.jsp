<%@ page language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="x" uri="http://java.sun.com/jstl/xml" %>
<%@ taglib prefix="p" uri="http://devsphere.com/xml/taglib/process" %>

<p:parse systemId="sample.xml" ignoreSpaces="true">
    <p:start>
        <HTML>
        <BODY>
    </p:start>
    <p:element testName="person">
        <p:start>
            <P>ID: <c:out value="${attr.id}"/>
        </p:start>
        <p:element testName="name">
            <p:data>
                <BR>Name: <c:out value="${data}"/>
            </p:data>
        </p:element>
        <p:element testName="email">
            <p:data>
                <BR>Email: <c:out value="${data}"/>
            </p:data>
        </p:element>
        <p:element testName="phone">
            <p:data>
                <BR>Phone: <c:out value="${data}"/>
            </p:data>
        </p:element>
        <p:element testName="address">
            <p:start>
                <BR>City:    <c:out value="${attr.city}"/>
                <BR>State:   <c:out value="${attr.state}"/>
                <BR>ZIP:     <c:out value="${attr.zip}"/>
                <BR>Country: <c:out value="${attr.country}"/>
            </p:start>
            <p:element testName="line1">
                <p:data>
                    <BR>Line1: <c:out value="${data}"/>
                </p:data>
            </p:element>
            <p:element testName="line2">
                <p:data>
                    <BR>Line2: <c:out value="${data}"/>
                </p:data>
            </p:element>
        </p:element>
    </p:element>
    <p:end>
        </BODY>
        </HTML>
    </p:end>
</p:parse>
