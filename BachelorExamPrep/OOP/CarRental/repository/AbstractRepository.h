//
// Created by geo on 16.06.2020.
//

#ifndef CARRENTAL_ABSTRACTREPOSITORY_H
#define CARRENTAL_ABSTRACTREPOSITORY_H

#include <vector>
#include <algorithm>

template<class T, class D>
class AbstractRepository {
private:
    std::vector<T> objects;
public:

    /**
     * Constructor for AbstractRepository
     */
    AbstractRepository() = default;

    /**
     *
     * @param newObj - object to be added
     * @return - true if the obj was added, false otherwise
     */
    bool addEntity(const T &newObj) {
        //TODO do validation this
        if (this->exists(newObj)) {
            return false;
        }
        this->objects.push_back(newObj);
        return true;
    }

    /**
     *
     * @param obj - object to be found
     * @return true if the object exists, false otherwise
     */
    bool exists(const T &obj) {
        return std::find(objects.begin(), objects.end(), obj) != objects.end();
    }

    /**
     *
     * @param id - function to retrieve an object
     * @return - the object to be retrieved
     * @attention! it is assumed that the element with the given id exists
     */
    T getOne(const D &id) {
        for (const auto &elem : objects) {
            if (elem.getID() == id) {
                return elem;
            }
        }
    }


    /**
     * Function to delete an object
     * @param id - id of object to be deleted
     * @return: true if the object was deleted, false otherwise
     */
    bool deleteEntity(const D &id) {
        int sz = objects.size();
        auto it = objects.begin();
        for (; it != objects.end(); it++) {
            if ((*it).getID() == id) {
                break;
            }
        }
        if (it != objects.end()) {
            objects.erase(it);
        }
        return sz != objects.size();
    }

    bool updateEntity(const T &obj) {
        if (this->exists(obj)) {
            for (auto &elem: this->objects) {
                if (elem.getID() == obj.getID()) {
                    elem = obj;
                    break;
                }
            }
            return true;
        }

        return false;
    }

    /**
     * Function to retrieve all entities from the repository
     * @return list containing all entities from the repository
     */
    std::vector<T> findAll() const {
        return this->objects;
    }

    /**
     * Function to return the number of objects in the repository
     * @return
     */
    int size() {
        return objects.size();
    }
};


#endif //CARRENTAL_ABSTRACTREPOSITORY_H
