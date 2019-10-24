package utils;

import objProtocol.ClientObjectWorker;
import service.IServer;

import java.net.Socket;

public class ObjectConcurrentServer extends ConcurrentServer {

    private IServer server;
    public ObjectConcurrentServer(int port, IServer server){
        super(port);
        this.server = server;
        System.out.println("Festival - FestivalConcurrentObject started");
    }

    @Override
    protected Thread createWorker(Socket client) {
        ClientObjectWorker worker = new ClientObjectWorker(server, client);
        return new Thread(worker);
    }
}
