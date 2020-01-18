package shows.model;

import java.io.Serializable;

public class Ticket implements Serializable {
    private Category category;
    private int number;
    private Integer showId;
    private String date;

    public Ticket(Category category, int number, Integer showId) {
        this.category = category;
        this.number = number;
        this.showId = showId;
    }

    public Integer getShowId() {
        return showId;
    }

    public void setShowId(Integer showId) {
        this.showId = showId;
    }

    public Category getCategory() {
        return category;
    }

    public void setCategory(Category category) {
        this.category = category;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    @Override
    public String toString() {

        return "Ticket{" +
                "category=" + category +
                ", number=" + number +
                ", showId=" + showId +
                ", issuedAt=" + date +
                '}';
    }
}
