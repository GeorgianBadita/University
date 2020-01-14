package controller;

import domain.entities.Seat;
import domain.entities.Spectacle;
import domain.entities.Ticket;
import repository.SeatRepository;
import repository.SpectacleRepository;
import repository.TicketRepository;

import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicReference;

public class Controller {
    private SeatRepository seatRepository;
    private TicketRepository ticketRepository;
    private SpectacleRepository spectacleRepository;

    public Controller(SeatRepository seatRepository, TicketRepository ticketRepository, SpectacleRepository spectacleRepository){
        this.seatRepository= seatRepository;
        this.ticketRepository = ticketRepository;
        this.spectacleRepository = spectacleRepository;
    }

    public ArrayList<Seat> getAllSeats(){
        Iterable<Seat> seats = seatRepository.findAll();
        ArrayList<Seat> seatArrayList = new ArrayList<>();
        seats.forEach(seatArrayList::add);
        return seatArrayList;
    }

    public ArrayList<Spectacle> getAllSpectacles(){
        Iterable<Spectacle> spectacles = spectacleRepository.findAll();
        ArrayList<Spectacle> spectacleArrayList = new ArrayList<>();
        spectacles.forEach(spectacleArrayList::add);
        return spectacleArrayList;
    }

    public ArrayList<Ticket> getAllTickets(){
        Iterable<Ticket> tickets = ticketRepository.findAll();
        ArrayList<Ticket> ticketArrayList = new ArrayList<>();
        tickets.forEach(ticketArrayList::add);
        return ticketArrayList;
    }

    public boolean findOneSeat(Seat s){
        return seatRepository.findOne(s.getId()) != null;
    }

    public boolean findOneSpectacle(Spectacle s){
        return spectacleRepository.findOne(s.getId()) != null;
    }

    public boolean findOneTicket(Ticket t){
        return ticketRepository.findOne(t.getId()) != null;
    }

    public void makeTransaction(String sellDate, Integer spectacleId, ArrayList<Seat> seats){
        Integer ticketId = ticketRepository.size() + 1;
        Ticket ticket = new Ticket(ticketId, sellDate, spectacleId, seats);
        ticketRepository.save(ticket);

    }
    public void addSpectacle(Spectacle spectacle){
        this.spectacleRepository.save(spectacle);
    }
    public void addSeat(Seat seat){
        this.seatRepository.save(seat);
    }

    public Integer calculateRevenue(){
        AtomicReference<Integer> revenue = new AtomicReference<>(0);
        ticketRepository
                .findAll()
                .forEach(x -> x.getSeats()
                        .forEach(y -> revenue.updateAndGet(v -> v + y.getType().seatPrice())));
        return revenue.get();
    }

    public void deleteSeat(Integer id) {
        seatRepository.delete(id);
    }
}
