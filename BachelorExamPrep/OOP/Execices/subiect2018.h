//
// Created by geo on 17.06.2020.
//

#ifndef EXECICES_SUBIECT2018_H
#define EXECICES_SUBIECT2018_H

#include <exception>
#include <string>

class RailCar {
private:
    std::string name;
    RailCar *next;
public:
    explicit RailCar(std::string n) {
        if (n.size() < 2) {
            throw std::exception();
        }
        this->name = std::move(n);
        this->next = nullptr;
    }

    virtual bool isProfitable() = 0;

    virtual std::string toString() {
        return this->name;
    }

    RailCar *getNext() const {
        return this->next;
    }

    void setNext(RailCar *railCar) {
        this->next = railCar;
    }

    virtual RailCar *clone() = 0;

    const std::string &getName() const {
        return this->name;
    }

    virtual ~RailCar() = default;

};

class Locomotive {
private:
    RailCar *first;
public:
    explicit Locomotive(RailCar *rail) : first(rail) {}

    void attachRailCar(RailCar *railCar) {
        if (first == nullptr) {
            first = railCar;
            first->setNext(nullptr);
            return;
        }
        if (railCar->getName() < first->getName()) {
            railCar->setNext(first);
            first = railCar;
            return;
        }
        auto tmpNext = first;
        auto tmp = first;
        tmpNext = tmpNext->getNext();
        while (tmpNext != nullptr && tmpNext->getName() < railCar->getName()) {
            tmp = tmpNext;
            tmpNext = tmpNext->getNext();
        }
        tmp->setNext(railCar);
        railCar->setNext(tmpNext);
    }

    RailCar *getFirstRailCar() const {
        return this->first;
    }

    void setFirstRailCar(RailCar *newFirst) {
        this->first = newFirst;
    }

    ~Locomotive() {
//        auto tmp = this->first;
//        while (tmp != nullptr) {
//            auto curr = tmp;
//            tmp = tmp->getNext();
//            delete curr;
//        }
    }
};


class RestaurantCar : public RailCar {
private:
    int numberOfTables;
public:
    RestaurantCar(std::string name, int numberOfTables) : RailCar(std::move(name)), numberOfTables(numberOfTables) {
        if (numberOfTables < 0) {
            throw std::exception();
        }
    }

    bool isProfitable() override {
        return numberOfTables >= 20;
    }

    std::string toString() override {
        return "Nume: " + RailCar::toString() + "\nNumMese: " + std::to_string(numberOfTables) + "\n";
    }

    RestaurantCar *clone() override {
        auto carCopy = new RestaurantCar(this->getName(), this->numberOfTables);
        return carCopy;
    }

    ~RestaurantCar() override = default;
};

class PassangerCar : public RailCar {
private:
    int capacity;
public:
    PassangerCar(std::string name, int cap) : RailCar(std::move(name)), capacity(cap) {};

    bool isProfitable() override {
        return capacity > 40;
    }

    std::string toString() override {
        return "Nume: " + RailCar::toString() + "\nCapacitate: " + std::to_string(capacity) + "\n";
    }

    PassangerCar *clone() override {
        return new PassangerCar(this->getName(), this->capacity);
    }
};


#endif //EXECICES_SUBIECT2018_H
