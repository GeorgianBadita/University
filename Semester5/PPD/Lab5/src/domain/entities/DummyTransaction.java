package domain.entities;

import java.util.ArrayList;

public class DummyTransaction {
    private String sellDate;
    private Integer spectacleId;
    private ArrayList<Seat> seats;

    @Override
    public String toString() {
        return "DummyTransaction{" +
                "sellDate='" + sellDate + '\'' +
                ", spectacleId=" + spectacleId +
                ", seats=" + seats +
                '}';
    }

    public DummyTransaction(String sellDate, Integer spectacleId, ArrayList<Seat> seats) {
        this.sellDate = sellDate;
        this.spectacleId = spectacleId;
        this.seats = seats;
    }


    public String getSellDate() {
        return sellDate;
    }

    public void setSellDate(String sellDate) {
        this.sellDate = sellDate;
    }

    public Integer getSpectacleId() {
        return spectacleId;
    }

    public void setSpectacleId(Integer spectacleId) {
        this.spectacleId = spectacleId;
    }

    public ArrayList<Seat> getSeats() {
        return seats;
    }

    public void setSeats(ArrayList<Seat> seats) {
        this.seats = seats;
    }
}
