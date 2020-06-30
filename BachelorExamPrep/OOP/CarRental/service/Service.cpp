//
// Created by geo on 16.06.2020.
//

#include "Service.h"


bool Service::addCar(int id, std::string &producer, std::string &model, std::string &type) {
    auto car = Car(id, producer, model, type);
    return this->repo.addEntity(car);
}

bool Service::updateCar(int id, std::string &producer, std::string &model, std::string &type) {
    auto car = Car(id, producer, model, type);
    return this->repo.updateEntity(car);
}

bool Service::deleteCar(int id) {
    return this->repo.deleteEntity(id);
}

std::vector<Car> Service::retrieveCars() {
    return this->repo.findAll();
}

Car Service::findCar(int id) {
    std::string placeholder = "";
    auto car = Car(id, placeholder, placeholder, placeholder);
    if (this->repo.exists(car)) {
        return this->repo.getOne(id);
    }
    car.setID(-1);
    return car;
}

std::vector<Car> Service::filterByProducer(std::string &producer) {
    auto allCars = this->retrieveCars();
    std::vector<Car> filteredCars;
    std::copy_if(allCars.begin(), allCars.end(), std::back_inserter(filteredCars), [&](const Car &car) {
        return car.getProducer() == producer;
    });

    return filteredCars;
}

std::vector<Car> Service::filterByType(std::string &type) {
    auto allCars = this->retrieveCars();
    std::vector<Car> filteredCars;
    std::copy_if(allCars.begin(), allCars.end(), std::back_inserter(filteredCars), [&](const Car &car) {
        return car.getProducer() == type;
    });

    return filteredCars;
}

std::vector<Car> Service::sortByType() {
    auto allCars = this->retrieveCars();
    std::sort(allCars.begin(), allCars.end(), [=](const Car &car1, const Car &car2) {
        return car1.getType() <= car2.getType();
    });
    return allCars;
}

std::vector<Car> Service::sortByID() {
    auto allCars = this->retrieveCars();
    std::sort(allCars.begin(), allCars.end(), [=](const Car &car1, const Car &car2) {
        return car1.getID() <= car2.getID();
    });
    return allCars;
}
