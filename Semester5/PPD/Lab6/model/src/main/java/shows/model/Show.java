package shows.model;

public class Show {
    private Integer id;
    private String title;
    private Long time;
    private String description;

    public Show(Integer id, String title, Long time, String description) {
        this.id = id;
        this.title = title;
        this.time = time;
        this.description = description;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public Long getTime() {
        return time;
    }

    public void setTime(Long timestamp) {
        this.time = timestamp;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }
}
