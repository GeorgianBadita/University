package server;

import controller.Controller;
import domain.entities.Seat;
import domain.entities.Spectacle;
import domain.entities.Ticket;

import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.ArrayList;
import java.util.concurrent.locks.ReentrantLock;


public class WorkerRunnable implements Runnable{

    protected Socket clientSocket = null;
    private String sellDate;
    private Integer spectacleId;
    private ArrayList<Seat> seats;
    private Controller ctr;
    private Integer id;
    private ReentrantLock lock;

    public WorkerRunnable(ReentrantLock lock, Integer id, String sellDate, Integer spectacleId,
                          ArrayList<Seat> seats, Controller ctr, Socket clientSocket){
        this.lock = lock;
        this.sellDate = sellDate;
        this.spectacleId = spectacleId;
        this.seats = seats;
        this.ctr = ctr;
        this.id = id;
        this.clientSocket = clientSocket;
    }


    public void run() {
        try {
            InputStream input  = clientSocket.getInputStream();
            OutputStream output = clientSocket.getOutputStream();
            long time = System.currentTimeMillis();

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
                    try {
                        output.write(("HTTP/1.1 200 OK\n\nWorkerRunnable: " +
                                "Inconsistent transaction " + x + " does not exist!" + " - TIME: " +
                                time +
                                "").getBytes());
                    } catch (IOException e) {
                        try {
                            output.close();
                        } catch (IOException ex) {
                            ex.printStackTrace();
                        }
                        try {
                            input.close();
                        } catch (IOException ex) {
                            ex.printStackTrace();
                        }
                        System.out.println("Request processed: " + time);
                        e.printStackTrace();
                    }
                    try {
                        output.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        input.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    System.out.println("Request processed: " + time);
                    return;
                }
            });
            this.seats.forEach(x -> {
                if(!ctr.findOneSeat(x)){
                    try {
                        output.write(("HTTP/1.1 200 OK\n\nWorkerRunnable: " +
                                "Inconsistent transaction " + x + " does not exist!" + " - TIME: " +
                                time +
                                "").getBytes());
                    } catch (IOException e) {
                        try {
                            output.close();
                        } catch (IOException ex) {
                            ex.printStackTrace();
                        }
                        try {
                            input.close();
                        } catch (IOException ex) {
                            ex.printStackTrace();
                        }
                        System.out.println("Request processed: " + time);
                        e.printStackTrace();
                    }
                    try {
                        output.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    try {
                        input.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    System.out.println("Request processed: " + time);
                    return;
                }
                ctr.deleteSeat(x.getId());
            });
            //System.out.println("ID: " + this.id);
            output.write(("HTTP/1.1 200 OK\n\nWorkerRunnable: " +
                    "Making transaction: " + new Ticket(0, sellDate, spectacleId, seats) + " - TIME: " +
                    time +
                    "").getBytes());

            lock.lock();
            ctr.makeTransaction(sellDate, spectacleId, seats);
            lock.unlock();



            output.close();
            input.close();
            System.out.println("Request processed: " + time);


        } catch (IOException e) {
            //report exception somewhere.
            e.printStackTrace();
        }
    }
}