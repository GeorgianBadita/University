package domain.entities;

public interface IEntity<ID>{
    ID getId();
    void setId(ID id);
}