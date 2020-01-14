package repository;

import domain.entities.IEntity;

import java.util.HashMap;
import java.util.Map;

public class AbstractRepository<E extends IEntity<ID>, ID> implements IRepository<ID, E>{
    private Map<ID, E> map;
    public AbstractRepository(){
        map = new HashMap<>();
    }

    @Override
    public E findOne(ID id) {
        if(id == null){
            return null;
        }
        return map.get(id);
    }

    @Override
    public Iterable<E> findAll() {
        return map.values();
    }

    @Override
    public E save(E ent) {
        if(ent == null){
            return null;
        }
        E elem = findOne(ent.getId());
        map.put(ent.getId(), ent);
        return elem;
    }

    @Override
    public E delete(ID id) {
        if(id == null){
            return null;
        }
        E elem = findOne(id);
        if(elem == null){
            return null;
        }
        map.remove(id);
        return elem;
    }

    @Override
    public E update(E e) {
        E elem = map.get(e.getId());
        if(elem == null){
            return null;
        }
        this.save(e);
        return elem;
    }

    @Override
    public int size() {
        return map.values().size();
    }
}
