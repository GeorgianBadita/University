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
    std::mutex* listLock;

public:
    /**
     * Constructor for polynomial class
     */
    Polynomial(): head{nullptr}, listLock{new std::mutex} {}

    /**
     * Function to add a monomial to a polynomial locking the whole list
     * @param coeff - coefficient
     * @param degree - degree of monomial
     * @result - if there is already a monomial with the given degree add the coefficient to it, else add the new monomial
     * to the polynomial
     */
    void addMonomialListLock(const int& coeff, const int& degree);

    /**
     * Function to add a monomial to a polynomial locking only one node
     * @param coeff - coefficient of the monomial
     * @param degree - degree of the monomial
     * @result - if there is already a monomial with the given degree add the coefficient to it, else add the new monomial
     * to the polynomial
     */
    void addMonomialNodeLock(const int& coeff, const int& degree);

    /**
     * Function to add a monomial to a polynomial
     * @param coeff - coefficient of the monomial
     * @param degree  - degree of the monomial
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

     /**
      * Destructor for Polynomial class
      */
     ~Polynomial();
};


#endif //ADDPOLYPARALLEL_POLYNOMIAL_H
