<%@ page language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="x" uri="http://java.sun.com/jstl/xml" %>
<%@ taglib prefix="p" uri="http://devsphere.com/xml/taglib/process" %>

<HTML>
<BODY>

<p:parse systemId="big.xml" ignoreSpaces="true">
<p:element testName="database">
    <p:element varDom="person" testName="person">
<x:set var="attrPersonId"       select="string($person/@id)"/>
<x:set var="dataName"           select="string($person/name/text())"/>
<x:set var="dataEmail"          select="string($person/email/text())"/>
<x:set var="dataPhone"          select="string($person/phone/text())"/>
<x:set var="attrAddressCity"    select="string($person/address/@city)"/>
<x:set var="attrAddressState"   select="string($person/address/@state)"/>
<x:set var="attrAddressZip"     select="string($person/address/@zip)"/>
<x:set var="attrAddressCountry" select="string($person/address/@country)"/>
<x:set var="dataAddressLine1"   select="string($person/address/line1/text())"/>
<x:set var="dataAddressLine2"   select="string($person/address/line2/text())"/>
<P> ID:      <c:out value="${attrPersonId}"/>
<BR>Name:    <c:out value="${dataName}"/>
<BR>Email:   <c:out value="${dataEmail}"/>
<BR>Phone:   <c:out value="${dataPhone}"/>
<BR>City:    <c:out value="${attrAddressCity}"/>
<BR>State:   <c:out value="${attrAddressState}"/>
<BR>ZIP:     <c:out value="${attrAddressZip}"/>
<BR>Country: <c:out value="${attrAddressCountry}"/>
<BR>Line1:   <c:out value="${dataAddressLine1}"/>
<BR>Line2:   <c:out value="${dataAddressLine2}"/>
    </p:element>
</p:element>
</p:parse>

</BODY>
</HTML>
