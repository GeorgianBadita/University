package client;

import controller.Controller;
import domain.entities.Seat;
import domain.entities.Spectacle;
import domain.entities.Ticket;

import java.util.ArrayList;
import java.util.concurrent.locks.ReentrantLock;

public class ClientThread implements Runnable{

    private String sellDate;
    private Integer spectacleId;
    private ArrayList<Seat> seats;
    private Controller ctr;
    private Integer id;
    private ReentrantLock lock;

    public ClientThread(ReentrantLock lock, Integer id, String sellDate, Integer spectacleId, ArrayList<Seat> seats, Controller ctr){
        this.lock = lock;
        this.sellDate = sellDate;
        this.spectacleId = spectacleId;
        this.seats = seats;
        this.ctr = ctr;
        this.id = id;
    }

    @Override
    public  synchronized void run() {
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        lock.lock();
        ArrayList<Spectacle> spectacles = ctr.getAllSpectacles();
        ArrayList<Seat> seats = new ArrayList<>();
        try {
            seats =  ctr.getAllSeats();
        }catch (java.util.ConcurrentModificationException ignored){

        }

        lock.unlock();
        if(seats.size() == 0){
            return;
        }
        spectacles.forEach(x -> {
            if(!ctr.findOneSpectacle(x)){
                System.out.println("Inconsistent transaction " + x + " does not exist!");
                return;
            }
        });
        this.seats.forEach(x -> {
            if(!ctr.findOneSeat(x)){
                System.out.println("Inconsistent transaction " + x + " does not exist!");
                return;
            }
            ctr.deleteSeat(x.getId());
        });
        //System.out.println("ID: " + this.id);
        System.out.println("Making transaction: " + new Ticket(0, sellDate, spectacleId, seats));
        lock.lock();
        ctr.makeTransaction(sellDate, spectacleId, seats);
        lock.unlock();
    }

}
