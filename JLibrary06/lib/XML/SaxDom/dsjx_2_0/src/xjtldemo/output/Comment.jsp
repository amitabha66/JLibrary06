<%@ page language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="o" uri="http://devsphere.com/xml/taglib/output" %>

<o:document>
<root>

<o:comment text="${param.c}"/>
<!--<c:out value="${param.c}" escapeXml="false"/>-->
<!--<%= request.getParameter("c") %>-->

</root>
</o:document>
