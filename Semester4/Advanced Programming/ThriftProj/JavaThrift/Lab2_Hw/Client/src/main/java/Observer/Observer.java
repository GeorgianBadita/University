package Observer;

import org.apache.thrift.server.TServer;

public class Observer implements Runnable {


    private final TServer server;

    public Observer(TServer server) {
        this.server = server;
    }

    @Override
    public void run() {
        System.out.println("Starting server.");

        while(true){
            server.serve();
        }
       // System.out.println("Server closed.");
    }
}
