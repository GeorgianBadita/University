package repository;

public interface IRepository<ID, E> {
    E findOne(ID id);
    Iterable<E> findAll();
    E save(E ent);
    E delete(ID id);
    E update(E e);
    int size();
}
