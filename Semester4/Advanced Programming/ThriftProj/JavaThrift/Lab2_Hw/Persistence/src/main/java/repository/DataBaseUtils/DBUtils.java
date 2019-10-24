package repository.DataBaseUtils;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public class DBUtils {
    private Properties jdbcProps;
    private static final Logger logg = LogManager.getLogger("DBUtilsLogger");
    private Connection instance = null;

    public DBUtils(Properties props){
        this.jdbcProps = props;
    }

    private Connection getNewConnection(){
        logg.traceEntry();
        String driver = jdbcProps.getProperty("repo.jdbc.driver");
        String url = jdbcProps.getProperty("repo.jdbc.url");
        String user = jdbcProps.getProperty("repo.jdbc.user");
        String pass = jdbcProps.getProperty("repo.jdbc.pass");

        logg.info("trying to connect to database... {}", url);
        logg.info("user: {}", user);
        logg.info("pass: {}", user);
        Connection con = null;
        try{
            Class.forName(driver);
            logg.info("Loaded driver ...{}", driver);
            con = DriverManager.getConnection(url, user, pass);
        } catch (ClassNotFoundException e) {
            logg.error(e);
            System.out.println("Error loading driver " + e);
        } catch (SQLException e) {
            logg.error(e);
            System.out.println("Error getting connection " + e);
        }
        return con;
    }

    public Connection getConnection(){
        logg.traceEntry();
        try{
            if(instance == null || instance.isClosed()){
                instance = getNewConnection();
            }
        } catch (SQLException e) {
            logg.error(e);
            System.out.println("ERROR DB " + e);
        }
        logg.traceExit(instance);
        return instance;
    }
}
