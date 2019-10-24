package servlets;

import java.io.*;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/app")
public class AppServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        String uname=request.getParameter("username");
        HttpSession  session = request.getSession();
        session.setAttribute("user", uname);
        out.print("<a href='logout'>LogOut</a><br>");
        out.print("Hello "+ uname);
        out.close();
    }
}