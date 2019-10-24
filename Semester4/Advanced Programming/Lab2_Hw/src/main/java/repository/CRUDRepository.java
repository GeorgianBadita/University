package repository;

import domain.IHasId;
import domain.exceptions.IllegalArgumentException;
import domain.exceptions.ValidatorException;

public interface CRUDRepository<ID, E extends IHasId<ID> > {
    /**
     * Function to find an element into the repository
     * @param id - id of the entity to be remove
     * @return - returns the entity with the given id, or
     * null if there is no entity with the specified id
     * @throws - Illegal argument exception if
     */
    E findOne(ID id) throws IllegalArgumentException;

    /**
     *
     * @param entity - entity to be saved
     * @return - Null if the entity was added, the entity otherwise
     * @throws IllegalArgumentException - if entity is null
     * @throws ValidatorException - if the entity is not well defined
     */
    E save(E entity) throws IllegalArgumentException, ValidatorException;

    /**
     * Function to delete an entity from the repository
     * @param id - id of the entity
     * @return - the entity if it was deleted, null otherwise
     * @throws IllegalArgumentException - if the id is null
     */
    E delete(ID id) throws IllegalArgumentException;

    /**
     * Function to update an entity from the repository
     * @param entity - the entity to be updated
     * @return - Null if the entity was updated, the given entity otherwise
     * @throws IllegalArgumentException - if the entity is null
     * @throws ValidatorException - if the entity is not well defined
     */
    E update(E entity)throws IllegalArgumentException, ValidatorException;

    /**
     * Function to get all the entities from the repository
     * @return - an iterable containing all the elements from the repository
     */
    Iterable<E> findAll();

    /**
     * Function which returns the size of the repository
     * @return - integer representing number of elements from the repository
     */
    Integer size();
}
