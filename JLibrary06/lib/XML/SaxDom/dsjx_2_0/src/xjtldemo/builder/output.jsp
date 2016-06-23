<%@ page language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="x" uri="http://java.sun.com/jstl/xml" %>
<%@ taglib prefix="o" uri="http://devsphere.com/xml/taglib/output" %>

<o:document>
    <c:set var="id" value="js890"/>
    <o:element name="person" attr="id">
        <o:element name="name">
            <o:data>John Smith</o:data>
        </o:element>
        <o:element name="email">
            <o:data>John.Smith@yahoo.com</o:data>
        </o:element>
        <o:element name="phone">
            <o:data>650-123-4567</o:data>
        </o:element>
        <c:set var="city" value="Palo Alto"/>
        <c:set var="state" value="CA"/>
        <c:set var="zip" value="94303"/>
        <c:set var="country" value="USA"/>
        <o:element name="address" attr="city state zip country">
            <o:element name="line1">
                <o:data>JS Information Systems, Inc.</o:data>
            </o:element>
            <o:element name="line2">
                <o:data>1001 San Antonio Road</o:data>
            </o:element>
        </o:element>
    </o:element>
</o:document>
