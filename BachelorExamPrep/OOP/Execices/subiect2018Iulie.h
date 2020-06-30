//
// Created by geo on 21.06.2020.
//

#ifndef EXECICES_SUBIECT2018IULIE_H
#define EXECICES_SUBIECT2018IULIE_H

#include<string>

class Vehicle {
private:
    int basePrice;
public:
    explicit Vehicle(int basePrice) : basePrice(basePrice) {};

    virtual std::string getDescription() = 0;

    virtual int getPrice() {
        return this->basePrice;
    }
};

class Car : public Vehicle {
private:
    std::string model;
public:
    Car(int basePrice, std::string model) : Vehicle(basePrice), model(std::move(model)) {};

    std::string getDescription() override {
        return this->model;
    }
};

class AutomaticCar : public Car {
private:
    int aditionalPrice;
public:
    AutomaticCar(int basePrice, std::string model, int aditionalPrice) : Car(basePrice, std::move(model)),
                                                                         aditionalPrice(aditionalPrice) {};

    int getPrice() override {
        return Car::getPrice() + this->aditionalPrice;
    }

    std::string getDescription() override {
        return "Automatic car " + Car::getDescription() + "\n";
    }
};

class CarWithParkingSensor : public Car {
private:
    std::string sensorType;
public:
    CarWithParkingSensor(int basePrice, std::string model, std::string sensorType) : Car(basePrice, std::move(model)),
                                                                                     sensorType(
                                                                                             std::move(sensorType)) {};

    int getPrice() override {
        return Car::getPrice() + 2500;
    }

    std::string getDescription() override {
        return "Car with parking sensor " + this->sensorType + Car::getDescription() + "\n";
    }
};

#endif //EXECICES_SUBIECT2018IULIE_H
