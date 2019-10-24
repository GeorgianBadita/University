//
// Created by georg on 10/9/2019.
//

#ifndef LAB1_CPP_BIGNUM_H
#define LAB1_CPP_BIGNUM_H
#include <vector>
#include <string>
#include <algorithm>
#include <ostream>

class BigNum {
private:
    std::vector<int> num;

    /**
     * Function to convert a string into a big number
     * @param num: string form of number
     * @return: a vector containing on every position a digit from the number
     */
    std::vector<int> stringToNum(std::string& num);
public:
    /**
     * Constructor for BigNum class
     * @param numStr - string representing the number
     */
    BigNum(std::string& numStr):num{stringToNum(numStr)}{}

    BigNum(std::vector<int>& numVec): num{numVec} {}

    /**
     * Declaring ostream class as friend
     * @param os - ostream object
     * @param dt - BigNum object
     */
    friend std::ostream& operator<<(std::ostream& os, const BigNum& dt);

    /**
     * Getter for num parameter
     * @return: int vector containing the number's digits
     */
    const std::vector<int>& getNum() const {
        return this->num;
    }

    /**
     * Function to set the vector number
     * @param newNum - vector of digits
     */
    void setNum(std::vector<int>& newNum) {
        this->num = newNum;
    }

    /**
     * Overloading + operator
     * @param other: BigNum object
     * @return: reference to a BigNum object
     */
    BigNum operator +(const BigNum& other);
};


#endif //LAB1_CPP_BIGNUM_H
