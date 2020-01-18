package shows.server.server;

import shows.model.Sale;
import shows.model.Ticket;
import shows.server.repository.Repository;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class Server {
    private int port;
    private ServerSocket serverSocket;
    private ExecutorService threadPool;
    private Repository repository;

    public Server(int port, int numberOfThreads, Repository repository) {
        this.port = port;
        this.repository = repository;
        threadPool = Executors.newFixedThreadPool(numberOfThreads);
    }

    public void start() {
        try {
            serverSocket = new ServerSocket(port);
            System.out.println("Server has started...");
            threadPool.execute(new LoggerWorker());
            System.out.println("Starting logger worker...");
            while (true) {
                System.out.println("Waiting for clients...");
                Socket client = serverSocket.accept();
                System.out.println("Client connected...");
                processRequest(client);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void processRequest(Socket client) {
        Future<Ticket> future = threadPool.submit(new MyCallable(client));
        Thread thread = new Thread(new Worker(future, client));
        thread.setDaemon(false);
        thread.start();
    }

    private class LoggerWorker implements Runnable {
        @Override
        public void run() {
            while (true){
                try {
                    Thread.sleep(20000);
                    repository.logActions();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    private class MyCallable implements Callable<Ticket>{
        private Socket client;
        private ObjectInputStream inputStream;

        public MyCallable(Socket client) {
            this.client = client;
            try {
                inputStream = new ObjectInputStream(client.getInputStream());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        @Override
        public Ticket call() throws Exception {
            Sale sale = (Sale)inputStream.readObject();
            return repository.buyTicket(sale);
        }
    }
}
