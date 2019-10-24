package domain.entities;

import domain.IHasId;

import java.time.LocalDate;
import java.time.LocalDateTime;

public class Concert implements IHasId<Integer> {
    private Integer concertId;
    private Integer locationId;
    private Integer artistId;
    private LocalDateTime date;
    private ConcertType type;
    private Integer seatsSold;

    /**
     * Constructor for Concert class
     * @param concertId - id of the concert
     * @param locationId - location of the concert
     * @param artistId - id of the artist
     * @param date - concert date
     * @param concertType - concert type
     * @param seatsSold - number of sold tickest
     */
    public Concert(Integer concertId, Integer locationId,
                   Integer artistId, LocalDateTime date,
                   ConcertType concertType, Integer seatsSold){
        this.concertId = concertId;
        this.locationId = locationId;
        this.artistId = artistId;
        this.date = date;
        this.type = concertType;
        this.seatsSold = seatsSold;
    }

    /**
     * Getters and setters
     */
    @Override
    public Integer getId() {
        return concertId;
    }

    @Override
    public void setId(Integer integer) {
        this.concertId = concertId;

    }

    public Integer getArtistId() {
        return artistId;
    }

    public Integer getLocationId() {
        return locationId;
    }

    public Integer getSeatsSold() {
        return seatsSold;
    }

    public ConcertType getType() {
        return type;
    }

    public LocalDateTime getDate() {
        return date;
    }

    public void setLocationId(Integer locationId) {
        this.locationId = locationId;
    }

    public void setDate(LocalDateTime date) {
        this.date = date;
    }

    public void setSeatsSold(Integer seatsSold) {
        this.seatsSold = seatsSold;
    }

    public void setType(ConcertType type) {
        this.type = type;
    }

    public void setArtistId(Integer artistId) {
        this.artistId = artistId;
    }

    /**
     * Overriding equals function
     * @param ot - object to compare
     * @return - true if the two objects are equal, false otherwise
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

        Concert conc = (Concert) ot;
        return conc.getId().equals(this.getId()) &&
               conc.getLocationId().equals(this.getLocationId()) &&
               conc.getDate().equals(this.getDate()) &&
               conc.getSeatsSold().equals(this.getSeatsSold()) &&
               conc.getType().equals(this.getType());
    }
}
