<%@ page language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="o" uri="http://devsphere.com/xml/taglib/output" %>

<o:document>
<root>

<o:pi target="${param.t}" data="${param.d}"/>
<?<c:out value="${param.t}"/> <c:out value="${param.d}" escapeXml="false"/>?>
<?<%= request.getParameter("t") %> <%= request.getParameter("d") %>?>

</root>
</o:document>
