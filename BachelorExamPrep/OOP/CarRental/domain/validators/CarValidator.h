//
// Created by geo on 15.06.2020.
//

#ifndef CARRENTAL_CARVALIDATOR_H
#define CARRENTAL_CARVALIDATOR_H

#include "../entities/Car.h"
#include "../exceptions/invalidCarException/InvalidCarException.h"
#include <vector>
#include <string>

class CarValidator {
public:
    /**
     * Function to validate a car object
     * @param car - car to be validated
     * @throws: InvalidCarException if the care does not respect the requirements
     */
    void validate(const Car &car);
};


#endif //CARRENTAL_CARVALIDATOR_H
