
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Problema 1 :)</title>
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
    <h1 class="title">ANDROID PHONE HACKS COULD UNLOCK MILLIONS OF CARS</h1>

    <div class="img-wrapper">
        <img src="./uploads/car_hacking.jpg">
    </div>

    <div class="article-text">
        <p>&emsp;IN THE ERA of the connected car, automakers and third-party developers compete to turn smartphones into vehicular remote controls, allowing drivers to locate, lock, and unlock their rides with a screen tap. Some apps even summon cars and trucks in Knight Rider fashion. But phones can be hacked. And when they are, those car-connected features can fall into the hands of hackers, too.</p>

        <p>&emsp;That's the troubling result of a test of nine different connected-car Android apps from seven companies. A pair of researchers from the Russian security firm Kaspersky found that most of the apps, several of which have been downloaded hundreds of thousands or over a million times, lacked even basic software defenses that drivers might expect to protect one of their most valuable possessions. By either rooting the target phone or tricking a user into installing malicious code, the researchers say, hackers could use any of the apps Kaspersky tested to locate a car, unlock it, and in some cases start its ignition.</p>
    </div>

    <hr>

    <h2>Comments</h2>
    <div class="comment-form">
        <form action="index.jsp" method="POST">
            <label>Email</label><br>
            <input type="email" name="email"><br><br>

            <label>Comment</label><br>
            <textarea name="comment-text"></textarea>

            <input type="submit" name="submit" value="Submit comment for moderation">
        </form>
    </div>

    <%
        if ("POST".equalsIgnoreCase(request.getMethod()) && request.getParameter("submit") != null) {
            try{
                Class.forName("com.mysql.cj.jdbc.Driver");
                Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/diawp","root","root123");

                String sql = "INSERT INTO php_pb6_comments (name, comment, status) VALUES (?, ?, 'WAITING')";
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
    <%
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/diawp","root","root123");
        Statement st= con.createStatement();
        ResultSet rs=st.executeQuery("select * from php_pb6_comments where status = 'PUBLISHED'");
        while(rs.next()) {
            String email = rs.getString("name");
            String comment = rs.getString("comment");
            Date date = rs.getDate("published_time");
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
