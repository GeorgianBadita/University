
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
    <link rel="stylesheet" href="index.css">
</head>
<body>


<% String username = (String)session.getAttribute("username"); %>
<% if (username != null) {%>

<a href="index.jsp">Go back</a>
<h2>Here is a list of the banned words, <% out.print(username); %></h2>

<div class="comment-form">
    <form action="admin.jsp" method="POST">
        <label>New word to ban</label><br>
        <input type="text" name="word"><br><br>

        <input type="submit" name="submit" value="Submit comment">
    </form>
</div>
<%
    if ("POST".equalsIgnoreCase(request.getMethod()) && request.getParameter("submit") != null) {
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/programare_web","root","");

            String sql = "INSERT INTO banned_words VALUES (?)";
            PreparedStatement preparedStatement = con.prepareStatement(sql);
            preparedStatement.setString(1, request.getParameter("word"));
            preparedStatement.executeUpdate();

            response.sendRedirect("admin.jsp");
        }catch(Exception e){
            e.printStackTrace();
        }
    }
%>

<%@ page import ="java.sql.*" %>
<%
    Class.forName("com.mysql.cj.jdbc.Driver");
    Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/programare_web","root","");
    Statement st= con.createStatement();
    ResultSet rs=st.executeQuery("select * from banned_words");
    while(rs.next()) {
        String word = rs.getString("word");
        %>
        <p><% out.print(word); %></p>
   <% }
%>
<% } %>


</body>
</html>
