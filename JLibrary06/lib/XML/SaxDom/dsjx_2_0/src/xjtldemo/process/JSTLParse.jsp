<%@ page language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="x" uri="http://java.sun.com/jstl/xml" %>

<c:import var="xml" url="sample.xml"/>
<x:parse varDom="dom" xml="${xml}"/>
<x:set var="attrPersonId"       select="string($dom/person/@id)"/>
<x:set var="dataName"           select="string($dom/person/name/text())"/>
<x:set var="dataEmail"          select="string($dom/person/email/text())"/>
<x:set var="dataPhone"          select="string($dom/person/phone/text())"/>
<x:set var="attrAddressCity"    select="string($dom/person/address/@city)"/>
<x:set var="attrAddressState"   select="string($dom/person/address/@state)"/>
<x:set var="attrAddressZip"     select="string($dom/person/address/@zip)"/>
<x:set var="attrAddressCountry" select="string($dom/person/address/@country)"/>
<x:set var="dataAddressLine1"   select="string($dom/person/address/line1/text())"/>
<x:set var="dataAddressLine2"   select="string($dom/person/address/line2/text())"/>

<HTML>
<BODY>
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
</BODY>
</HTML>
