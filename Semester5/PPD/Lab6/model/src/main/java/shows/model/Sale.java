package shows.model;

import java.io.Serializable;

public class Sale implements Serializable {
    private Integer number;
    private Integer showId;

    public Sale(Integer number, Integer showId) {
        this.number = number;
        this.showId = showId;
    }

    public Sale() {
    }

    public Integer getNumber() {
        return number;
    }

    public void setNumber(Integer number) {
        this.number = number;
    }

    public Integer getShowId() {
        return showId;
    }

    public void setShowId(Integer showId) {
        this.showId = showId;
    }

    @Override
    public String toString() {
        return "Sale{" +
                "number=" + number +
                ", showId=" + showId +
                '}';
    }
}
