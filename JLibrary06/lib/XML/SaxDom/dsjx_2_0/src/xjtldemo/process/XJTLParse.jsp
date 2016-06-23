<%@ page language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="x" uri="http://java.sun.com/jstl/xml" %>
<%@ taglib prefix="p" uri="http://devsphere.com/xml/taglib/process" %>

<p:parse systemId="sample.xml" ignoreSpaces="true">
    <p:element varAttr="attrPerson" testName="person">
        <p:element testName="name"><p:data varData="dataName"/></p:element>
        <p:element testName="email"><p:data varData="dataEmail"/></p:element>
        <p:element testName="phone"><p:data varData="dataPhone"/></p:element>
        <p:element varAttr="attrAddress" testName="address">
            <p:element testName="line1"><p:data varData="dataAddressLine1"/></p:element>
            <p:element testName="line2"><p:data varData="dataAddressLine2"/></p:element>
        </p:element>
    </p:element>
</p:parse>

<HTML>
<BODY>
<P> ID:      <c:out value="${attrPerson.id}"/>
<BR>Name:    <c:out value="${dataName}"/>
<BR>Email:   <c:out value="${dataEmail}"/>
<BR>Phone:   <c:out value="${dataPhone}"/>
<BR>City:    <c:out value="${attrAddress.city}"/>
<BR>State:   <c:out value="${attrAddress.state}"/>
<BR>ZIP:     <c:out value="${attrAddress.zip}"/>
<BR>Country: <c:out value="${attrAddress.country}"/>
<BR>Line1:   <c:out value="${dataAddressLine1}"/>
<BR>Line2:   <c:out value="${dataAddressLine2}"/>
</BODY>
</HTML>
