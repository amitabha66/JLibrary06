<%@ page language="java" %>
<%@ page import="com.devsphere.examples.xml.taglib.*" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="o" uri="http://devsphere.com/xml/taglib/output" %>

<jsp:useBean id="b" scope="page"
    class="com.devsphere.examples.xml.taglib.TestBean"/>

<o:document>
<root>

<o:element name="e" attr="b.a1 b.a2 b.a3">
...
</o:element>

<e a1="<c:out value='${b.a1}'/>"
   a2="<c:out value='${b.a2}'/>"
   a3="<c:out value='${b.a3}'/>">
...
</e>

<%
String v1 = DemoUtils.escapeXml(b.getA1());
String v2 = DemoUtils.escapeXml(b.getA2());
String v3 = DemoUtils.escapeXml(b.getA3());
%>
<e a1="<%=v1%>" a2="<%=v2%>" a3="<%=v3%>">
...
</e>

</root>
</o:document>
