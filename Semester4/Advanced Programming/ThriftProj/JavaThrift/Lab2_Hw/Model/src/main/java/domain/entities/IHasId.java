package domain.entities;

public interface IHasId<ID> {
    /**
     * Function to return the id of the entity
     * @return - returns entity id
     */
    ID getId();

    /**
     * Function to set the entity id
     * @param id - id of the entity
     */
    void setId(ID id);
}
