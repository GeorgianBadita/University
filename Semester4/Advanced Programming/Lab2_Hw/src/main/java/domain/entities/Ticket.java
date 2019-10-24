package domain.entities;

import com.sun.tools.javac.util.Pair;
import domain.IHasId;

import java.time.LocalDate;

public class Ticket implements IHasId<Integer> {

    private Integer ticketId;
    private Integer concertId;
    private String clientName;
    private LocalDate buyDate;
    private Integer numOfSeats;

    /**
     * Constructor for Ticket class
     * @param clientName - name of the client
     * @param idConcert - id of the concert
     * @param buyDate - buy date
     * @param numOfSeats - number of seats
     */
    public Ticket(Integer ticketId,
                  Integer idConcert,
                  String clientName,
                  LocalDate buyDate,
                  Integer numOfSeats){
        this.ticketId = ticketId;
        this.concertId = idConcert;
        this.buyDate = buyDate;
        this.numOfSeats = numOfSeats;
        this.clientName = clientName;
    }

    /**
     * Getters and setters
     * @return
     */
    @Override
    public Integer getId() {
        return ticketId;
    }

    @Override
    public void setId(Integer integerIntegerPair) {
        this.ticketId = integerIntegerPair;
    }

    public Integer getNumOfSeats() {
        return numOfSeats;
    }


    public LocalDate getBuyDate() {
        return buyDate;
    }

    public Integer getConcertId(){
        return this.concertId;
    }

    public void setConcertId(Integer newConcertId){
        this.concertId = newConcertId;
    }

    public String getClientName(){
        return clientName;
    }

    public void setClientName(String newClientName){
        this.clientName = newClientName;
    }

    public void setBuyDate(LocalDate buyDate) {
        this.buyDate = buyDate;
    }

    public void setNumOfSeats(Integer numOfSeats) {
        this.numOfSeats = numOfSeats;
    }

    /**
     * Overriding equals method
     * @param ot - object to be compared
     * @return - true if the objects are equal, false otherwise
     */
    @Override
    public boolean equals(Object ot){
        if(ot == null){
            return false;
        }

        if(this == ot){
            return true;
        }

        if(this.getClass() != ot.getClass()){
            return false;
        }

        Ticket ticket = (Ticket) ot;

        return ticket.getId().equals(this.getId()) &&
               ticket.getBuyDate().equals(this.getBuyDate());
    }
}
