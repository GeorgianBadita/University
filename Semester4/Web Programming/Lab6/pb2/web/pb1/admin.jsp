
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
    <link rel="stylesheet" href="index.css">
</head>
<body>


<% String username = (String)session.getAttribute("username"); %>
<% if (username != null) {%>

<a href="index.jsp">Go back to the article</a>
<h2>Here is a list of comments waiting for your approval, <% out.print(username); %></h2>

<%@ page import ="java.sql.*" %>
<%
    Class.forName("com.mysql.cj.jdbc.Driver");
    Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/diawp","root","root123");
    Statement st= con.createStatement();
    ResultSet rs=st.executeQuery("select * from php_pb6_comments where status = 'WAITING'");
    while(rs.next()) {
        String id = String.valueOf(rs.getInt("id"));
        String email = rs.getString("name");
        String comment = rs.getString("comment");
        %>
        <div class="comment">
            <div class="username">
                <h3>From : <% out.println(email); %></h3>
            </div>
            <hr>
            <p><% out.println(comment); %></p>
            <hr>
            <a href="comments/publish/<% out.print(id); %>">Publish</a>
            <a href="comments/delete/<% out.print(id); %>">Delete</a>
        </div>

   <% }
%>
<% } %>


</body>
</html>
