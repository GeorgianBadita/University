package shows.client.client;

import shows.model.Sale;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Random;

public class ClientWorker {
    private static final String host = "localhost";
    private static final int port = 55555;
    private Socket connection;
    private ObjectInputStream inputStream;
    private ObjectOutputStream outputStream;
    private Random random = new Random();

    public void connect() {
        try {
            connection = new Socket(host, port);
            outputStream = new ObjectOutputStream(connection.getOutputStream());
            outputStream.flush();
            inputStream = new ObjectInputStream(connection.getInputStream());
            sendSales();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void sendSales() {
        Sale sale = new Sale(random.nextInt(99),random.nextInt(3));
        try {
            outputStream.writeObject(sale);
            outputStream.flush();
            String response = (String) inputStream.readObject();
            System.out.println(response);
            inputStream.close();
            outputStream.close();
            connection.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
