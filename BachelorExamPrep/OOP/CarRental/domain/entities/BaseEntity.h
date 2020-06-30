//
// Created by geo on 16.06.2020.
//

#ifndef CARRENTAL_BASEENTITY_H
#define CARRENTAL_BASEENTITY_H

template<class T>
class BaseEntity {
protected:
    T ID;
public:
    /**
     * Id Getter
     * @return T
     */
    T getID() const {
        return this->ID;
    }

    /**
     * ID Setter
     * @param newID - new ID of type T
     */
    void setID(const T &newID) {
        this->ID = newID;
    }

    /**
     * Overload == operator
     * @param rhs
     * @return
     */
    bool operator==(BaseEntity<T> &rhs) {
        return rhs.getID() == this->getID();
    }

    /**
     * Overload == operator for const
     * @param rhs
     * @return
     */
    bool operator==(const BaseEntity<T> &rhs) {
        return rhs.getID() == this->getID();
    }

    /**
     * Overload != operator
     * @param rhs
     * @return
     */
    bool operator!=(BaseEntity<T> &rhs) {
        return this->getID() != rhs.getID();
    }
};


#endif //CARRENTAL_BASEENTITY_H
