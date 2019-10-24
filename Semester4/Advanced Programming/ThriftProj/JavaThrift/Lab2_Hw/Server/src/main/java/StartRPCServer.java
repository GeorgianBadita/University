import domain.validator.*;
import repository.EntitiesRepos.*;
import servImpl.FestivalService;
import service.IServer;

import java.io.IOException;
import java.rmi.AlreadyBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Properties;

public class StartRPCServer {

    static Registry registry;
    static int defaultPort = 55555;
    static String serverName="ServerABC";

    public static void main(String[] args) {
        System.setProperty("java.rmi.server.hostname", "127.0.0.1");
        Properties props = new Properties();
        try{
            props.load(StartObjServer.class.getResourceAsStream("/server.properties"));
            System.out.println("Server properties set....");
            props.list(System.out);
        } catch(IOException e) {
            System.err.println("Cannot find server.properties " + e);
            return;
        }

        ArtistDBRepo artistRepo = new ArtistDBRepo(props, new ArtistValidator());
        ConcertDBRepository concertRepo = new ConcertDBRepository(props, new ConcertValidator());
        LocationDBRepo locRepo = new LocationDBRepo(props, new LocationValidator());
        TicketDBRepository tickRepo = new TicketDBRepository(props, new TicketValidator());
        UserDBRepository userRepo = new UserDBRepository(props, new UserValidator());

        IServer serverImpl = new FestivalService(artistRepo, concertRepo, locRepo, tickRepo, userRepo);

        int serverPort = defaultPort;
        try {

            serverPort = Integer.parseInt(props.getProperty("server.port"));

        }catch (NumberFormatException nef){
            System.err.println("Wrong port number " + nef.getMessage());
            System.err.println("Using default port " + defaultPort);
        }
        try {
            LocateRegistry.createRegistry(serverPort);
            IServer stub = (IServer) UnicastRemoteObject.exportObject(serverImpl, serverPort);
            registry = LocateRegistry.getRegistry("127.0.0.1", serverPort);
            registry.bind(serverName, stub);
        } catch (RemoteException | AlreadyBoundException e) {
            e.printStackTrace();
        }

        System.out.println("RPC SERVER STARTED");

    }
}
