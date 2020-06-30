//
// Created by geo on 15.06.2020.
//

#include "CarValidator.h"

void CarValidator::validate(const Car &car) {
    std::vector<std::string> carErrors;
    if (car.getID() < 0) {
        carErrors.emplace_back("Car number must be a positive integer!");
    }
    if (car.getProducer().empty()) {
        carErrors.emplace_back("Producer cannot be empty!");
    }
    if (car.getType().empty()) {
        carErrors.emplace_back("Car type cannot be empty!");
    }
    if (car.getModel().empty()) {
        carErrors.emplace_back("Car model cannot be empty!");
    }

    if (!carErrors.empty()) {
        throw InvalidCarException(carErrors);
    }
}

