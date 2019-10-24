import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class DataBaseTest {
    public static void main(String[] args) {
        save(5, "Geo", "Badita");
       // delete(5);
        selectAll();

        Student st;
        ApplicationContext context = new ClassPathXmlApplicationContext("springDbTest.xml");
        st = context.getBean(Student.class);

       // ApplicationContext context = new AnnotationConfigApplicationContext(SpringConfig.class);
       // st = context.getBean(Student.class);
        System.out.println("========================= " + st.getName() + " " + st.getAdr().getStreet() + " " + st.getAdr().getNumber());
    }


    private static void selectAll(){
     /*   ApplicationContext context = new ClassPathXmlApplicationContext("springDbTest.xml");
        DBUtils dbUtils = context.getBean(DBUtils.class);*/

        ApplicationContext context = new AnnotationConfigApplicationContext(SpringConfig.class);
        DBUtils  dbUtils = context.getBean(DBUtils.class);
        Connection con = dbUtils.getConnection();
        try(PreparedStatement prStm = con.prepareStatement("select * from Student")) {
            try(ResultSet result = prStm.executeQuery()){
                while(result.next()) {

                    int id = result.getInt("id");
                    String name = result.getString("name");
                    String surname = result.getString("surname");
                    System.out.println("=========================== " + id + " " +  name + " " + surname);
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void save(Integer id, String name, String surname){
        /*
        ApplicationContext context = new ClassPathXmlApplicationContext("springDbTest.xml");
        DBUtils dbUtils = context.getBean(DBUtils.class);*/

        ApplicationContext context = new AnnotationConfigApplicationContext(SpringConfig.class);
        DBUtils  dbUtils = context.getBean(DBUtils.class);
        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("insert into Student values (?, ?, ?)")) {
            prSt.setInt(1, id);
            prSt.setString(2, name);
            prSt.setString(3, surname);
            int  res = prSt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void delete(Integer id){
       /* ApplicationContext context = new ClassPathXmlApplicationContext("springDbTest.xml");

        DBUtils dbUtils = context.getBean(DBUtils.class);*/

        ApplicationContext context = new AnnotationConfigApplicationContext(SpringConfig.class);
        DBUtils  dbUtils = context.getBean(DBUtils.class);
        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("delete from Student where Student.ID= ?")) {
            prSt.setInt(1, id);
            int  res = prSt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
