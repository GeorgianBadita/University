//
// Created by geo on 16.06.2020.
//

#ifndef CARRENTAL_TESTSERVICE_H
#define CARRENTAL_TESTSERVICE_H


#include <cassert>
#include "../testsMain/Test.h"
#include "../../domain/entities/Car.h"
#include "../../repository/CarRepository.h"
#include "../../service/Service.h"

class TestService : public Test {
private:
    Car getGeneratedCar() {
        std::string producer = "Tesla";
        std::string model = "Model S";
        std::string newModel = "Model E";
        std::string type = "Roadster";
        int number = 1;
        Car car = Car(number, producer, model, type);
        return car;
    }

    void testFindCar() {
        auto repo = CarRepository();
        auto service = Service(repo);
        auto car = this->getGeneratedCar();
        assert(service.findCar(1).getID() == -1);
        std::string producer = car.getProducer();
        std::string model = car.getModel();
        std::string type = car.getType();
        service.addCar(car.getID(), producer, model, type);
        assert(service.findCar(1) == car);
    }

    void testFilterByProducer() {
        auto repo = CarRepository();
        auto service = Service(repo);
        auto car = this->getGeneratedCar();
        std::string newProducer = "Mercedes";
        assert(service.filterByProducer(newProducer).empty());
        repo.addEntity(car);
        car.setID(2);
        car.setProducer(newProducer);
        repo.addEntity(car);
        assert(service.filterByProducer(newProducer).size() == 1);
        assert(service.filterByProducer(newProducer)[0].getID() == 2);
    }

    void testSortById() {
        auto repo = CarRepository();
        auto service = Service(repo);
        auto car = this->getGeneratedCar();
        repo.addEntity(car);
        car.setID(0);
        repo.addEntity(car);
        assert(service.sortByID().size() == 2);
        assert(service.sortByID()[0].getID() < service.sortByID()[1].getID());
    }

public:
    void runTest() override {
        this->testFindCar();
        this->testFilterByProducer();
        this->testSortById();
    }
};


#endif //CARRENTAL_TESTSERVICE_H
