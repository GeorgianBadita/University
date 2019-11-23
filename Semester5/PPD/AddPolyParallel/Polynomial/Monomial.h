//
// Created by georg on 11/22/2019.
//

#ifndef ADDPOLYPARALLEL_MONOMIAL_H
#define ADDPOLYPARALLEL_MONOMIAL_H


class Monomial {
private:
    int coeff;
    int degree;

public:
    Monomial* next;
    /**
     * Constructor for monomial class
     * @param val  - Monomial coefficient
     * @param degree - Monomial's degree
     */
    Monomial(const int& val, const int& degree): coeff{val}, degree{degree}, next{nullptr} {}

    /**
     * Default constructor for monomial class
     */
    Monomial():coeff{-1}, degree{-1}, next{nullptr}{}

    /**
     * Getters
     */
    int getCoefficient() const {return this->coeff;}
    int getDegree() const {return this->degree; }

    /**
     * Setters
     */
     void setCoefficient(const int& newCoeff) {this->coeff = newCoeff;}
     void setDegree(const int& deg) {this->degree = deg;}
};


#endif //ADDPOLYPARALLEL_MONOMIAL_H
