package utils;

import java.net.Socket;

public abstract class ConcurrentServer extends AbstractServer {

    public ConcurrentServer(int port){
        super(port);
        System.out.println("Concurrent AbstractServer");
    }

    @Override
    public void processRequest(Socket client) {
        Thread tw  = createWorker(client);
        tw.start();
    }

    protected abstract Thread createWorker(Socket client);
}
