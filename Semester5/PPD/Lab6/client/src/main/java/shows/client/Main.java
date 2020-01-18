package shows.client;

import shows.client.client.ClientWorker;

public class Main {
    public static void main(String[] args) {
        ClientWorker clientWorker = new ClientWorker();
        while (true) {
            try {
                clientWorker.connect();
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
