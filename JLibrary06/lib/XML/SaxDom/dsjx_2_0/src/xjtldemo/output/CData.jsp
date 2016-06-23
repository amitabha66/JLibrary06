<%@ page language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="o" uri="http://devsphere.com/xml/taglib/output" %>

<o:document>
<root>

<o:data value="${param.d}" section="true"/>
<![CDATA[<c:out value="${param.d}" escapeXml="false"/>]]>
<![CDATA[<%= request.getParameter("d") %>]]>

</root>
</o:document>
