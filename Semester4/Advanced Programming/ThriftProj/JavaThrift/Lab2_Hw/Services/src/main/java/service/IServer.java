package service;

import domain.entities.Concert;
import domain.entities.DTOConcert;
import domain.entities.Ticket;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.time.LocalDate;
import java.util.List;

public interface IServer extends Remote {

    boolean validateLogIn(String userName, String pass, IObserver obs) throws RemoteException;
    Concert findConcert(Integer concert) throws RemoteException;
    Ticket sellTicket(Integer concert, String clientName, LocalDate now, Integer numSeats) throws RemoteException;
    boolean canSellTicket(Integer concId, Integer numTickets) throws RemoteException;
    List<DTOConcert> getConcertDtosByDate(LocalDate dateFilter) throws RemoteException;
    List<DTOConcert> getConcertDtos() throws RemoteException;
    Concert updateConcert(Concert conc) throws RemoteException;
    void notifyClients() throws RemoteException;
}
