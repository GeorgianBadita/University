package domain.entities;

public class Seat implements IEntity<Integer> {
    private SeatType type;
    private Integer id;

    public Seat(SeatType type, Integer id) {
        this.type = type;
        this.id = id;
    }

    @Override
    public Integer getId() {
        return id;
    }

    @Override
    public void setId(Integer integer) {
        id = integer;
    }

    public SeatType getType() {
        return type;
    }

    public void setType(SeatType type) {
        this.type = type;
    }

    @Override
    public String toString() {
        return "Seat{" +
                "type=" + type +
                ", id=" + id +
                '}';
    }
}
