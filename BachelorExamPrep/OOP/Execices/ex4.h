//
// Created by geo on 16.06.2020.
//

#ifndef EXECICES_EX4_H
#define EXECICES_EX4_H

#include <exception>
#include <iostream>

class Integer {
private:
    int value;
public:
    Integer() {
        this->value = 0;
    }

    explicit Integer(int val) : value(val) {}

    int getValue() const {
        return this->value;
    }

    friend std::ostream &operator<<(std::ostream &os, const Integer &i) {
        os << i.getValue();
        return os;
    }
};

class Stack {
private:
    Integer *values = new Integer[16];
    int size = 16;
    int currPos = 0;
public:

    Stack() = default;

    void push(Integer value) {
        if (currPos < size) {
            this->values[currPos] = value;
            currPos += 1;
        } else {
            throw std::exception();
        }
    }

    Integer pop() {
        if (currPos > 0) {
            this->currPos--;
            return this->values[currPos];
        } else {
            throw std::exception();
        }
    }

    bool empty() {
        return this->currPos == 0;
    }

    ~Stack() {
        delete[] values;
    }
};


#endif //EXECICES_EX4_H
