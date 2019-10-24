package domain.entities;

import java.time.LocalDateTime;

public class DTOConcert {
    private Integer concertId;
    private String artistName;
    private LocalDateTime date;
    private String locationName;
    private Integer numOfSeats;
    private Integer soldSeats;
    private Integer freeSeats;


    /**
     * Constructor for DTOConcert class
     * @param concertId - id of the concert
     * @param artistName - name of the artist
     * @param date - date of the concert
     * @param locationName - concert location
     * @param numOfSeats - number of seats
     * @param soldSeats - number sold seats
     */
    public DTOConcert(Integer concertId,String artistName, LocalDateTime date, String locationName, Integer numOfSeats, Integer soldSeats) {
        this.concertId = concertId;
        this.artistName = artistName;
        this.date = date;
        this.locationName = locationName;
        this.numOfSeats = numOfSeats;
        this.soldSeats = soldSeats;
        this.freeSeats = numOfSeats - soldSeats;
    }


    /**
     * Getters and setters
     */
    public String getArtistName() {
        return artistName;
    }

    public void setArtistName(String artistName) {
        this.artistName = artistName;
    }

    public LocalDateTime getDate() {
        return date;
    }

    public void setDate(LocalDateTime date) {
        this.date = date;
    }

    public String getLocationName() {
        return locationName;
    }

    public void setLocationName(String locationName) {
        this.locationName = locationName;
    }

    public Integer getNumOfSeats() {
        return numOfSeats;
    }

    public void setNumOfSeats(Integer numOfSeats) {
        this.numOfSeats = numOfSeats;
    }

    public Integer getSoldSeats() {
        return soldSeats;
    }

    public void setSoldSeats(Integer soldSeats) {
        this.soldSeats = soldSeats;
    }


    public Integer getConcertId() {
        return concertId;
    }

    public void setConcertId(Integer newID){
        this.concertId = newID;
    }

    public Integer getFreeSeats() {
        return freeSeats;
    }


}
