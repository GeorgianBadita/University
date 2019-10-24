
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<html>
<head>
    <title>Problema 2 btw</title>
        <html>
        <head>
            <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
            <link rel="stylesheet" href="style.css">
            <title>Captcha</title>
        </head>
<body>
<center>
    <form method="post">
        <img src="http://localhost:8080/pb2_war_exploded/CaptchaServlet">

        <br><br>

        <table cellspacing="15">
            <tr>
                <td>Are you human?</td>
                <td><input type="text" name="code"></td>
            </tr>
        </table>

        <br><br>
        <input type="submit" value="submit">

    </form>
    <br><br>
    <%
        String captcha = (String) session.getAttribute("captcha");
        String code = (String) request.getParameter("code");

        if (captcha != null && code != null) {
            if (captcha.equals(code)) {
                out.print("<p class='corect'>Correct</p>");
            } else {
                out.print("<p class='alert'>Incorrect</p>");
            }
        }
    %>
</center>
</body>
</html></title>
</head>
<body>

</body>
</html>
