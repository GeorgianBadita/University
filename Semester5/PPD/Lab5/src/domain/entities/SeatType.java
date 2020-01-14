package domain.entities;

interface SeatTraits{
    default Integer seatPrice() {
        return 0;
    }
}

public enum SeatType implements SeatTraits {
    BAD {
        @Override
        public Integer seatPrice() {
            return 20;
        }
    },
    GOOD{
        @Override
        public Integer seatPrice() {
            return 40;
        }
    },
    PERFECT{
        @Override
        public Integer seatPrice() {
            return 100;
        }
    }
}
