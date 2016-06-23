<%@ page language="java" %>
<%@ page import="com.devsphere.examples.xml.taglib.*" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="o" uri="http://devsphere.com/xml/taglib/output" %>

<o:document>
<root>

<o:data value="${param.d}"/>
<c:out value="${param.d}"/>
<%= DemoUtils.escapeXml(request.getParameter("d")) %>

</root>
</o:document>
