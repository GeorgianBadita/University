package servlets;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnectionManager {

    public static Connection getConnection(){
        Connection con = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
            con= DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/users","root","root123");
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }

        return con;
    }
}
