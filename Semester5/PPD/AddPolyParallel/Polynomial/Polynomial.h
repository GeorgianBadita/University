//
// Created by georg on 11/22/2019.
//

#ifndef ADDPOLYPARALLEL_POLYNOMIAL_H
#define ADDPOLYPARALLEL_POLYNOMIAL_H

#include <mutex>
#include "Monomial.h"

class Polynomial {
private:
    Monomial* head;
public:
    /**
     * Constructor for polynomial class
     */
    Polynomial(): head{nullptr} {}

    /**
     * Function to add a monmomial to a polynomial
     * @param coeff - coefficient
     * @param degree - degree of monomial
     * @result - if there is alraedy a monomial with the given degree add the coefficient to it, else add the new mnimial
     * to the polynomial
     */
    void addMonomial(const int& coeff, const int& degree);

    /**
    * Declaring ostream class as friend
    * @param os - ostream object
    * @param dt - Polynomial object
    */
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& dt);

    /**
     * Getters
     */
     Monomial* getHead() {return this->head;}
};


#endif //ADDPOLYPARALLEL_POLYNOMIAL_H
