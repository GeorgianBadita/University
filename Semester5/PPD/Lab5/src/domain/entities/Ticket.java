package domain.entities;

import java.util.ArrayList;

public class Ticket implements IEntity<Integer> {
    private Integer id;
    private String sellDate;
    private Integer spectacleId;
    private ArrayList<Seat> seats;

    public Ticket(Integer id, String sellDate, Integer spectacleId, ArrayList<Seat> seats) {
        this.id = id;
        this.sellDate = sellDate;
        this.seats = seats;
        this.spectacleId = spectacleId;
    }

    @Override
    public Integer getId() {
        return id;
    }

    @Override
    public void setId(Integer integer) {
        id = integer;
    }

    public String getSellDate() {
        return sellDate;
    }

    public void setSellDate(String sellDate) {
        this.sellDate = sellDate;
    }

    public ArrayList<Seat> getSeats() {
        return seats;
    }

    public void setSeats(ArrayList<Seat> seats) {
        this.seats = seats;
    }

    public Integer getSpectacleId(){
        return spectacleId;
    }

    public void setSpectacleId(Integer spectacleId){
        this.spectacleId = spectacleId;
    }

    @Override
    public String toString() {
        return "Ticket{" +
                "id=" + id +
                ", sellDate='" + sellDate + '\'' +
                ", spectacleId=" + spectacleId +
                ", seats=" + seats +
                '}';
    }
}
