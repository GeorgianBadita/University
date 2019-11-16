//
// Created by georg on 10/9/2019.
//

#ifndef LAB1_CPP_BIGNUM_H
#define LAB1_CPP_BIGNUM_H
#include <vector>
#include <string>
#include <algorithm>
#include <ostream>


class Polynomial {
private:
    std::vector<int> poly;
    static std::vector<int> vectorToPoly(std::vector<int>& poly){
        std::reverse(poly.begin(), poly.end());
        return poly;
    }

public:

    /**
      * Constructor for Polynomial class
      * @param numStr - string representing the polynomial
      */
    Polynomial(std::vector<int>& numVec): poly{vectorToPoly(numVec)} {}

    /**
     * Declaring ostream class as friend
     * @param os - ostream object
     * @param dt - Polynomial object
     */
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& dt);

    /**
     * Getter for num parameter
     * @return: int vector containing the polynomial coefficients
     */
    const std::vector<int>& getPoly() const {
        return this->poly;
    }

    /**
     * Function to set the polynomial coefficients
     * @param newPoly - vector of coefficients
     */
    void setPoly(std::vector<int>& newPoly) {
        this->poly = newPoly;
    }

    /**
     * Overloading * operator
     * @param other: Polynomial object
     * @return: a Polynomial object
     */
    Polynomial operator *(const Polynomial& other);
};


#endif //LAB1_CPP_BIGNUM_H