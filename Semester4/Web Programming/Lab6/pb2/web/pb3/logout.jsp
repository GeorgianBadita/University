
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>

<%
    session.invalidate();
    response.sendRedirect("index.jsp");
%>
</body>
</html>
