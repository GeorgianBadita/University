//
// Created by geo on 15.06.2020.
//

#ifndef CARRENTAL_TESTCAR_H
#define CARRENTAL_TESTCAR_H


#include <cassert>
#include "../../testsMain/Test.h"
#include "../../../domain/entities/Car.h"
#include<iostream>

class TestCar : public Test {
public:
    void runTest() override {
        std::string producer = "Tesla";
        std::string model = "Model S";
        std::string newModel = "Model E";
        std::string type = "Roadster";
        int number = 1;
        int newNumber = 2;
        Car car = Car(number, producer, model, type);
        assert(car.getID() == number);
        assert(car.getModel() == model);
        assert(car.getProducer() == producer);
        assert(car.getType() == type);
        car.setProducer(newModel);
        assert(car.getProducer() == newModel);
        car.setID(newNumber);
        assert(car.getID() == newNumber);
        Car car2 = car;
        car2.setProducer("new Producer");
        assert(car2 == car);
        car2.setID(10);
        assert(car2 != car);
    }

    ~TestCar() override = default;
};


#endif //CARRENTAL_TESTCAR_H
