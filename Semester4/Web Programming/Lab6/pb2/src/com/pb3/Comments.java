package com.pb3;


import javax.servlet.http.HttpServlet;

import java.sql.*;

public class Comments extends HttpServlet {
    public static String filterComment(String comment) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/programare_web","root","");
            Statement st= con.createStatement();
            ResultSet rs=st.executeQuery("select * from banned_words");

            while(rs.next()) {
                String word = rs.getString("word");

                comment = comment.replaceAll(word, "***");
            }

        } catch (SQLException|ClassNotFoundException ex) {
            System.out.println(ex.getMessage());
        }

        return comment;
    }
}
