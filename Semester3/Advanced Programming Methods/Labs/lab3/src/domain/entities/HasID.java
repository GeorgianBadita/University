package domain.entities;

/**
 * Interface for ID
 * @param <ID> Requires ID
 */
public interface HasID<ID> {
    ID getID();
    void setID(ID id);
}