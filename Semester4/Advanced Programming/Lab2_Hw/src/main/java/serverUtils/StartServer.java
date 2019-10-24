package serverUtils;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import serverUtils.AbstractServer;
import service.UserService;

public class StartServer {
    public static void main(String[] args) {

       AbstractServer server=new SequentialServer(55555);
       //AbstractServer server=new MyConcurrentServer(55555);
      //AbstractServer server=new SerialConcurrentServer(55555);
        try {
            server.start();
        } catch (curs.sockets.server.ServerException e) {
            System.out.println(e.getMessage());
        }
    }


}
