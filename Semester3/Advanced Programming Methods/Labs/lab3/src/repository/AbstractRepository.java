package repository;

import domain.entities.HasID;
import domain.entities.Student;
import domain.validators.IllegalArgumentException;
import domain.validators.Validator;
import domain.validators.ValidatorException;

import java.util.HashMap;
import java.util.Objects;
import java.util.function.Predicate;

public abstract class AbstractRepository<E extends HasID<ID>, ID> implements CrudRepository<ID, E> {

    private Validator<E> val;
    private HashMap<ID, E> map;
    private Predicate<E> nullEelement = Objects::isNull;
    private Predicate<ID> nullID = Objects::isNull;

    AbstractRepository(Validator<E> v){
        this.val = v;
        map = new HashMap<>();
    }

    /**
     *
     * @param id -the id of the entity to be returned
     * id must not be null
     * @return null if the element does not exists, otherwise, the element
     * @throws IllegalArgumentException - if the id is null
     */
    public E findOne(ID id) throws IllegalArgumentException {
        if(nullID.test(id)){
            throw new IllegalArgumentException("Id-ul nu poate fi null!");
        }
        return map.get(id);
    }

    /**
     * @return all entities
     */
    public Iterable<E> findAll() {
        return map.values();
    }

    /**
     * @param entity entity must be not null
     * @return null- if the given entity is saved
     * otherwise returns the entity (id already exists)
     * @throws ValidatorException    if the entity is not valid
     * @throws IllegalArgumentException if the given entity is null. *
     */
    public E save(E entity) throws ValidatorException, IllegalArgumentException {
        val.validate(entity);
        E elem = findOne(entity.getID());
        map.put(entity.getID(), entity);
        return elem;
    }

    /**
     * removes the entity with the specified id
     *
     * @param id id must be not null
     * @return the removed entity or null if there is no entity with the given id
     * @throws IllegalArgumentException if the given id is null.
     */
    public E delete(ID id) throws IllegalArgumentException {
        if(nullID.test(id)){
            throw new IllegalArgumentException("Id-ul nu poate fi null!");
        }
        E elem = map.get(id);
        if(nullEelement.test(elem)){
            return null;
        }
        map.remove(id);
        return elem;
    }

    /**
     * @param entity entity must not be null
     * @return null - if the entity is updated,
     * otherwise returns the entity - (e.g id does not exist).
     * @throws IllegalArgumentException if the given entity is null.
     * @throws ValidatorException      if the entity is not valid.
     */
    public E update(E entity) throws ValidatorException, IllegalArgumentException {
        if(nullEelement.test(entity)){
            throw new IllegalArgumentException("Element can't be null!");
        }
        E elem = map.get(entity.getID());

        if(!nullEelement.test(entity)){
            this.save(entity);
            return null;
        }
        this.save(entity);
        return entity;
    }


    /**
     * no parameters
     * @return the size of the repository
     */
    public int size(){
        return map.size();
    }

}
