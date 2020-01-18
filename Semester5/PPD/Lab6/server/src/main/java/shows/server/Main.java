package shows.server;

import shows.server.repository.Repository;
import shows.server.server.Server;

public class Main {
    private static int NUMBER_OF_THREADS = 5;
    private static int port = 55555;

    public static void main(String[] args) {
        Repository repository = new Repository();
        Server showServer = new Server(port,NUMBER_OF_THREADS,repository);
        showServer.start();
    }
}
