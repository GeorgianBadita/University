import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public class DBUtils {
    private Properties jdbcProps;
    private static final Logger logger = LogManager.getLogger();

    public DBUtils(Properties prop){
        this.jdbcProps = prop;
    }

    private Connection instnace = null;
    private Connection getNewConnection(){
        logger.traceEntry();
        String driver = jdbcProps.getProperty("tests.jdbc.driver");
        String url = jdbcProps.getProperty("tests.jdbc.url");
        String user = jdbcProps.getProperty("tests.jdbc.user");
        String pass = jdbcProps.getProperty("tests.jdbc.pass");
        logger.info("trying to connect to database... {}", url);
        logger.info("user: {}", user);
        logger.info("pass: {}", pass);
        Connection con = null;
        try{
            Class.forName(driver);
            logger.info("Loaded driver ...{}", driver);
            con = DriverManager.getConnection(url, user, pass);
        } catch (ClassNotFoundException e) {
            logger.error(e);
            System.out.println("Error loading driver " + e);
        } catch (SQLException e) {
            logger.error(e);
            System.out.printf("Error getting connection " + e);
        }
        return con;
    }

    public Connection getConnection(){
        logger.traceEntry();
        try{
            if(instnace == null || instnace.isClosed()){
                instnace = getNewConnection();
            }
        } catch (SQLException e) {
            logger.error(e);
            System.out.println("ERROR DB " + e);
        }
        logger.traceExit(instnace);
        return instnace;
    }
}
