package serverUtils;

import domain.entities.User;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import serverUtils.AbstractServer;
import service.UserService;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Date;

/**
 * Created by IntelliJ IDEA.
 * User: grigo
 * Date: Mar 18, 2009
 * Time: 11:49:21 AM
 */
public class SequentialServer extends AbstractServer {
    private UserService usrSrv;

    public SequentialServer(int port) {
        super(port);
        this.usrSrv = new ClassPathXmlApplicationContext("FestivalSpringXML.xml").getBean(UserService.class);
        System.out.println("SequentialServer");
    }

    protected void processRequest(Socket client) {
        try (BufferedReader br=new BufferedReader(new InputStreamReader(client.getInputStream()));
             PrintWriter writer=new PrintWriter(client.getOutputStream())){

             //read message from client
            String line=br.readLine();
            String[] split = line.split(" ");

            //send result back to client
            boolean connect = usrSrv.validateLogIn(split[0], split[1]);

            if(connect){
                writer.println("OK");
                writer.flush();
            }
            else{
                writer.println("WRONG CREDENTIALS");
                writer.flush();
            }

        } catch (IOException e) {
            System.err.println("Communication error "+e);
        }finally {
            try {
                client.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }
}