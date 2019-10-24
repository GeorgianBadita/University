package com.pb1;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.*;

@WebServlet(name = "comments", urlPatterns = {"/pb1/comments/*"})
public class Comments extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        processRequest(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.sendRedirect("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
    }

    private void processRequest(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        if (req.getSession().getAttribute("username") == null) {
            resp.sendRedirect("https://www.google.com&q=how+to+hack");
        }
        String url = req.getRequestURI();
        String[] data = url.split("/");
        System.out.println(url);
        System.out.println(data.length);

        if (data.length > 4) {

            try {
                String action = data[4];
                Integer id = Integer.valueOf(data[5]);

                Class.forName("com.mysql.cj.jdbc.Driver");
                Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/diawp","root","root123");
                if (action.equals("delete")) {
                    PreparedStatement st = con.prepareStatement("delete from php_pb6_comments where id=?");
                    st.setInt(1, id);

                    st.executeUpdate();
                }
                else if (action.equals("publish")) {
                    PreparedStatement st = con.prepareStatement("UPDATE php_pb6_comments SET status = 'PUBLISHED' WHERE id = ?");
                    st.setInt(1, id);

                    st.executeUpdate();
                }
                resp.sendRedirect("/pb2_war_exploded/pb1/admin.jsp");
            } catch (SQLException e) {
                System.out.println(e.getMessage());
            } catch (ClassNotFoundException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}
