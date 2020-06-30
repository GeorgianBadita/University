//
// Created by geo on 16.06.2020.
//

#ifndef CARRENTAL_CARREPOSITORY_H
#define CARRENTAL_CARREPOSITORY_H


#include "../domain/entities/Car.h"
#include "AbstractRepository.h"

class CarRepository : public AbstractRepository<Car, int> {
public:
    CarRepository() = default;
};


#endif //CARRENTAL_CARREPOSITORY_H
