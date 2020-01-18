package shows.server.server;

import shows.model.Ticket;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.concurrent.Future;

public class Worker implements Runnable {
    private Socket client;
    private ObjectOutputStream outputStream;
    private Future<Ticket> future;

    public Worker(Future<Ticket> future, Socket client) {
        this.future = future;
        this.client = client;
        try {
            outputStream = new ObjectOutputStream(client.getOutputStream());
            outputStream.flush();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        try {
            Ticket response = future.get();
            String responseMessage = "received";
            if (response == null) responseMessage = "failed";
            outputStream.writeObject(responseMessage);
            outputStream.flush();
            outputStream.close();
            client.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
