<%@ page language="java" %>
<%@ page import="com.devsphere.examples.xml.taglib.*" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="o" uri="http://devsphere.com/xml/taglib/output" %>

<o:document>
<root>

<o:element name="e" attr="param.a1 param.a2 param.a3">
...
</o:element>

<e a1="<c:out value='${param.a1}'/>"
   a2="<c:out value='${param.a2}'/>"
   a3="<c:out value='${param.a3}'/>">
...
</e>

<%
String v1 = DemoUtils.escapeXml(request.getParameter("a1"));
String v2 = DemoUtils.escapeXml(request.getParameter("a2"));
String v3 = DemoUtils.escapeXml(request.getParameter("a3"));
%>
<e a1="<%=v1%>" a2="<%=v2%>" a3="<%=v3%>">
...
</e>

<o:attributes var="a">
  <o:attribute name="a1" value="${param['a1']}"/>
  <o:attribute name="a2" value="${param['a2']}"/>
  <o:attribute name="a3" value="${param['a3']}"/>
</o:attributes>
<o:element name="e" attr="${a}">
...
</o:element>

</root>
</o:document>
