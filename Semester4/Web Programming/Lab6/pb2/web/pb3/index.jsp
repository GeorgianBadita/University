
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Problema 3 :)</title>
    <link rel="stylesheet" type="text/css" href="index.css">
</head>
<body>

<% String username = (String)session.getAttribute("username"); %>
<% if (username == null) {%>
<div class="login_div">
    <form action="login" method="POST">
        <h2>Admin login</h2>

        <label>Username</label>
        <input type="text" name="username"><br><br>

        <label>Password</label>
        <input type="password" name="password"><br><br>

        <input type="submit" name="submit" value="Log in">
    </form>
</div>
<% } %>

<% if (username != null) {%>
    <div class="login_div">
        <a href="admin.jsp">Go to moderation page</a><br><br>
        <a href="logout.jsp">Logout</a>
    </div>
<% } %>
<div class="article">
    <h2>Comments</h2>
    <div class="comment-form">
        <form action="index.jsp" method="POST">
            <label>Email</label><br>
            <input type="email" name="email"><br><br>

            <label>Comment</label><br>
            <textarea name="comment-text"></textarea>

            <input type="submit" name="submit" value="Submit comment">
        </form>
    </div>

    <%
        if ("POST".equalsIgnoreCase(request.getMethod()) && request.getParameter("submit") != null) {
            try{
                Class.forName("com.mysql.cj.jdbc.Driver");
                Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/programare_web","root","");

                String sql = "INSERT INTO php_pb6_comments (name, comment, status) VALUES (?, ?, 'PUBLISHED')";
                PreparedStatement preparedStatement = con.prepareStatement(sql);
                preparedStatement.setString(1, request.getParameter("email"));
                preparedStatement.setString(2, request.getParameter("comment-text"));
                preparedStatement.executeUpdate();

            }catch(Exception e){
                e.printStackTrace();
            }
        }
    %>
    <%@ page import ="java.sql.*" %>
    <%@ page import="static com.pb3.Comments.filterComment" %>
    <%
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/programare_web","root","");
        Statement st= con.createStatement();
        ResultSet rs=st.executeQuery("select * from php_pb6_comments where status = 'PUBLISHED'");
        while(rs.next()) {
            String email = rs.getString("name");
            String comment = rs.getString("comment");
            Date date = rs.getDate("published_time");

            comment = filterComment(comment);
    %>
    <div class="comment">
        <div class="email">
            <h3>From :<% out.print(email); %></h3>
        </div>
        <div class="published_time">
            <h3><% out.print(date); %></h3>
        </div>
        <hr>
        <p><% out.print(comment); %></p>
    </div>

    <% } %>

</div>






</body>
</html>
