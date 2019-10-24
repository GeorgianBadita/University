
import domain.validator.*;
import repository.EntitiesRepos.*;

import servImpl.FestivalService;
import utils.AbstractServer;
import utils.ObjectConcurrentServer;
import utils.ServerException;

import java.io.IOException;
import java.util.Properties;

public class StartObjServer {
    private static int defaultPort=55555;

    public static void main(String[] args) {
        Properties props = new Properties();
        try{
            props.load(StartObjServer.class.getResourceAsStream("/server.properties"));
            System.out.println("Server properties set....");
            props.list(System.out);
        } catch (IOException e) {
            System.err.println("Cannot find server.properties " + e);
            return;
        }

        ArtistDBRepo artistRepo = new ArtistDBRepo(props, new ArtistValidator());
        ConcertDBRepository concertRepo = new ConcertDBRepository(props, new ConcertValidator());
        LocationDBRepo locRepo = new LocationDBRepo(props, new LocationValidator());
        TicketDBRepository tickRepo = new TicketDBRepository(props, new TicketValidator());
        UserDBRepository userRepo = new UserDBRepository(props, new UserValidator());

        service.IServer serverImpl = new FestivalService(artistRepo, concertRepo, locRepo, tickRepo, userRepo);
        int serverPort = defaultPort;
        try {

            serverPort = Integer.parseInt(props.getProperty("server.port"));

        }catch (NumberFormatException nef){
            System.err.println("Wrong port number " + nef.getMessage());
            System.err.println("Using default port " + defaultPort);
        }

        AbstractServer server = new ObjectConcurrentServer(serverPort, serverImpl);
        try {
            server.start();
        } catch (ServerException e) {
            System.err.println("Error starting the server ... " + e) ;
        }
    }
}
