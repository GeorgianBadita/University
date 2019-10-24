#include "lista.cpp"


class Collection {
    lista lst = lista();
public:

    void add(int elem) {
        this->lst.append(elem);
    }
    bool find(int elem) {
        return this->lst.search(elem);
    }
    void del(int elem) {
        this->lst.remove(elem);
    }
    int len() {
        return this->lst.dim();
    }
    void empty() {
        this->lst.vid();
    }
    int acces_elem(int index) {
        return this->lst.get(index);
    }

};

class Iterator{
    Collection collection = Collection();
    int current;
public:
    Iterator(Collection c) {
        this->collection = c;
        this->current = 0;
    }

    bool valid() {
        return this->current < this->collection.len();
    }

    void next() {
        this->current ++;
    }

    int element() {

        return this->collection.acces_elem(this->current);
    }
};
