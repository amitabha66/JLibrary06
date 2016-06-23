<%@ page language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="x" uri="http://java.sun.com/jstl/xml" %>
<%@ taglib prefix="o" uri="http://devsphere.com/xml/taglib/output" %>

<c:import url="sample.xml" var="xml"/>
<x:parse xml="${xml}" varDom="dom"/>
<o:document dom="${dom}"/>
