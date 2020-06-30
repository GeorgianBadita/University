//
// Created by geo on 16.06.2020.
//

#ifndef CARRENTAL_TESTREPOSITORY_H
#define CARRENTAL_TESTREPOSITORY_H


#include <cassert>
#include "../testsMain/Test.h"
#include "../../repository/CarRepository.h"

class TestRepository : public Test {
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

    void testAdd() {
        auto carRepo = CarRepository();
        assert(carRepo.size() == 0);
        auto car = this->getGeneratedCar();
        carRepo.addEntity(car);
        assert(carRepo.size() == 1);

        assert(!carRepo.addEntity(car));
        assert(carRepo.size() == 1);
        car.setID(20);
        assert(carRepo.addEntity(car));
        assert(carRepo.size() == 2);
        assert(carRepo.findAll()[0].getID() == 1);
        assert(carRepo.findAll()[1].getID() == 20);
    }

    void testExists() {
        auto carRepo = CarRepository();
        auto car = this->getGeneratedCar();
        assert(!carRepo.exists(car));
        carRepo.addEntity(car);
        assert(carRepo.exists(car));
        car.setID(20);
        assert(!carRepo.exists(car));
    }

    void testGetOne() {
        auto carRepo = CarRepository();
        auto car = this->getGeneratedCar();
        carRepo.addEntity(car);
        assert(carRepo.getOne(1) == car);
    }

    void testDelete() {
        auto carRepo = CarRepository();
        auto car = this->getGeneratedCar();
        assert(!carRepo.deleteEntity(20));
        assert(carRepo.size() == 0);
        carRepo.addEntity(car);
        assert(carRepo.size() == 1);
        assert(carRepo.deleteEntity(1));
        assert(carRepo.size() == 0);
    }

    void testFindAll() {
        auto carRepo = CarRepository();
        auto car = this->getGeneratedCar();
        auto car1 = this->getGeneratedCar();
        car1.setID(2);
        assert(carRepo.findAll().empty());
        carRepo.addEntity(car);
        carRepo.addEntity(car1);
        assert(carRepo.findAll().size() == 2);
        assert(carRepo.findAll()[0].getID() == 1);
        assert(carRepo.findAll()[1].getID() == 2);
    }

    void testUpdate() {
        auto carRepo = CarRepository();
        auto car = this->getGeneratedCar();
        auto car1 = this->getGeneratedCar();
        assert(!carRepo.updateEntity(car1));
        carRepo.addEntity(car);
        car1.setModel("New Model");
        assert(carRepo.updateEntity(car1));
        assert(carRepo.getOne(1).getModel() == "New Model");
    }

public:
    void runTest() override {
        this->testAdd();
        this->testExists();
        this->testDelete();
        this->testFindAll();
        this->testUpdate();
    }
};


#endif //CARRENTAL_TESTREPOSITORY_H
