import client.ClientThread;
import controller.Controller;
import domain.entities.DummyTransaction;
import domain.entities.Seat;
import domain.entities.SeatType;
import domain.entities.Spectacle;
import repository.SeatRepository;
import repository.SpectacleRepository;
import repository.TicketRepository;

import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.locks.ReentrantLock;

import static utils.Utils.generateInInterval;
import static utils.Utils.generateRandomString;

public class main {


    public static void main(String[] args) {
        ReentrantLock lock = new ReentrantLock();
        Controller controller = getController();
        ArrayList<DummyTransaction> dummyTransactions = getDummyTransactions(controller);
        ArrayList<Runnable> tasks = new ArrayList<>();
        final int[] cnt = {0};
        dummyTransactions.forEach(x -> {
            tasks.add(new ClientThread(lock, cnt[0],x.getSellDate(), x.getSpectacleId(), x.getSeats(), controller));
            cnt[0]++;
        });
        ExecutorService pool = Executors.newFixedThreadPool(10);

        tasks.forEach(pool::execute);
        // pool shutdown ( Step 4)
        pool.shutdown();
        //dummyTransactions.forEach(System.out::println);
        /*ThreadPooledServer server = new ThreadPooledServer(9000);
        new Thread(server).start();

        try {
            Thread.sleep(3600 * 1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Stopping Server");
        server.stop();*/
    }

    private static ArrayList<DummyTransaction> getDummyTransactions(Controller ctr) {
        ArrayList<DummyTransaction> transactions = new ArrayList<>();
        for(int i = 0; i < 100; i++){
            int year = generateInInterval(2018, 2020);
            int month = generateInInterval(1, 12);
            int day = generateInInterval(1, 30);
            String date = "" + day + "-" + month + "-" + year;
            int size = ctr.getAllSpectacles().size();
            int spectacleId = generateInInterval(0, size - 1);
            size = ctr.getAllSeats().size();
            int toSelect = Math.min(4, size);
            int numSeats = generateInInterval(0, toSelect);
            ArrayList<Seat> seats = new ArrayList<>();
            for(int j = 0; j<numSeats; j++){
                int id = generateInInterval(0, size - 1);
                while(true){
                    boolean isIn = false;
                    for (Seat s:
                         seats) {
                        if(s.getId() == id){
                            id = generateInInterval(0, size - 1);
                            isIn = true;
                            break;
                        }
                    }
                    if(!isIn){
                        break;
                    }
                }
                seats.add(ctr.getAllSeats().get(id));
            }
            transactions.add(new DummyTransaction(date, spectacleId, seats));
        }
        return transactions;
    }

    private static Controller getController() {
        SeatRepository seatRepository = new SeatRepository();
        SpectacleRepository spectacleRepository = new SpectacleRepository();
        TicketRepository ticketRepository = new TicketRepository();
        Controller ctr = new Controller(seatRepository, ticketRepository, spectacleRepository);
        ArrayList<Seat> seats = generateSeats();
        ArrayList<Spectacle> spectacles = generateSpectacles();
        seats.forEach(ctr::addSeat);
        spectacles.forEach(ctr::addSpectacle);
        return ctr;
    }

    private static ArrayList<Spectacle> generateSpectacles() {
        ArrayList<Spectacle> spectacles = new ArrayList<>();
        for(int i = 0; i<100; i++){
            int year = generateInInterval(2018, 2020);
            int month = generateInInterval(1, 12);
            int day = generateInInterval(1, 30);
            String title = generateRandomString();
            String description = generateRandomString();
            spectacles.add(new Spectacle(i, "" + day + "-" + month + "-" + year, title, description));

        }
        return spectacles;
    }

    private static ArrayList<Seat> generateSeats() {
        ArrayList<Seat> seats = new ArrayList<>();
        for(int i = 0; i< 1000; i++){
            int rand = generateInInterval(0, 2);
            if(rand == 0){
                seats.add(new Seat(SeatType.BAD, i));
            }else if(rand == 1){
                seats.add(new Seat(SeatType.GOOD, i));
            }
            else{
                seats.add(new Seat(SeatType.PERFECT, i));
            }
        }
        return seats;
    }
}
