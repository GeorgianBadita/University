package shows.model;

public class Category {
    private CategoryType type;
    private int start;
    private int end;
    private double price;

    public Category(CategoryType type, int start, int end, double price) {
        if (start >= end) throw new IllegalArgumentException("start >= end");
        this.type = type;
        this.start = start;
        this.end = end;
        this.price = price;
    }

    public CategoryType getType() {
        return type;
    }

    public void setType(CategoryType type) {
        this.type = type;
    }

    public int getStart() {
        return start;
    }

    public void setStart(int start) {
        this.start = start;
    }

    public int getEnd() {
        return end;
    }

    public void setEnd(int end) {
        this.end = end;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public boolean isInThisCategory(int number) {

        return number >= start && number < end;
    }

    @Override
    public String toString() {
        return "Category{" +
                "type=" + type +
                ", start=" + start +
                ", end=" + end +
                ", price=" + price +
                '}';
    }
}
