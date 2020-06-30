//
// Created by geo on 15.06.2020.
//

#include "Car.h"

Car::Car(int number, std::string &producer, std::string &model, std::string &type) : producer(producer),
                                                                                     model(model), type(type) {
    this->ID = number;
}