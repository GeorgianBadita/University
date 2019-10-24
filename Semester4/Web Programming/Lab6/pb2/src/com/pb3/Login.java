package com.pb3;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.*;

import org.springframework.security.crypto.bcrypt.BCrypt;

@WebServlet(name = "login2", urlPatterns = {"/pb3/login"})
public class Login extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.sendRedirect("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        processRequest(req, resp);
    }

    private void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        try {
            String username=request.getParameter("username");
            String password=request.getParameter("password");
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/programare_web","root","");
            Statement st= con.createStatement();
            ResultSet rs=st.executeQuery("select * from php_users");
            boolean logare = false;
            while(rs.next()) {
                String dbUsername = rs.getString("username");
                String dbPassword = rs.getString("password");

                if (username.equals(dbUsername) && BCrypt.checkpw(password, dbPassword)) {
                    request.getSession().setAttribute("username", username);
                    response.sendRedirect("admin.jsp");
                    logare = true;
                }
            }
            if( logare == false)
                response.sendRedirect("index.jsp");

        } catch (SQLException ex) {
            System.out.println("Eroare la sql");
        } catch (ClassNotFoundException ex) {
            System.out.println("Class not found");
            ex.printStackTrace();
        }

    }
}
