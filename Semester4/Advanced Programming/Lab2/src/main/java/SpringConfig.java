import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Primary;

import java.io.IOException;
import java.util.Properties;

@Configuration
public class SpringConfig {
    @Bean
    @Primary
    public Properties jdbProps(){
        Properties serverProps = new Properties();
        try{
            serverProps.load(getClass().getResourceAsStream("/bd.config"));
            System.out.println("Properties set. ");
            serverProps.list(System.out);
        } catch (IOException e) {
            e.printStackTrace();
        }

        return serverProps;
    }

    @Bean(name="dbUtils")
    public DBUtils createDBUtils(Properties jdbcProps){
        return new DBUtils(jdbcProps);
    }

    @Bean(name="addr")
    public Address createAddress(){
        return new Address("abc", 123);
    }

    @Bean(name="stud")
    public Student createStudent(Address adr){
        return new Student("Geo", adr);
    }
}
