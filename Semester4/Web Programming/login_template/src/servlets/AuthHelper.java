package servlets;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class AuthHelper {
    public static boolean isAllowed(String username, String password) {
        Connection con = ConnectionManager.getConnection();

        PreparedStatement statement = null;
        String statementString = "SELECT * FROM user where username = ? AND password = ?";



        try {
            statement = con.prepareStatement(statementString);
            statement.setString(1, username);
            statement.setString(2, password);

            ResultSet resSet = statement.executeQuery();
            if(resSet.next()){
                return true;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return false;
        //return username.contentEquals("admin") && password.contentEquals("password");
    }
}