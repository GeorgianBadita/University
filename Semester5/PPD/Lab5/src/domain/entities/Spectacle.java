package domain.entities;

import java.util.Objects;

public class Spectacle implements IEntity<Integer> {
    private Integer id;
    private String date;
    private String title;
    private String description;

    public Spectacle(Integer id, String date, String title, String description){
        this.id = id;
        this.date = date;
        this.title = title;
        this.description = description;
    }


    @Override
    public Integer getId() {
        return id;
    }

    @Override
    public void setId(Integer integer) {
        id = integer;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Spectacle)) return false;
        Spectacle spectacle = (Spectacle) o;
        return Objects.equals(getId(), spectacle.getId()) &&
                Objects.equals(getDate(), spectacle.getDate()) &&
                Objects.equals(getTitle(), spectacle.getTitle()) &&
                Objects.equals(getDescription(), spectacle.getDescription());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getId(), getDate(), getTitle(), getDescription());
    }

    @Override
    public String toString() {
        return "Spectacle{" +
                "id=" + id +
                ", date='" + date + '\'' +
                ", title='" + title + '\'' +
                ", description='" + description + '\'' +
                '}';
    }
}
