//
// Created by geo on 16.06.2020.
//

#ifndef EXECICES_EX3_H
#define EXECICES_EX3_H

#include <iostream>

class E {
public:
    E() { std::cout << "E()"; }

    virtual void print() { std::cout << "E"; }

    virtual ~E() { std::cout << "~E()"; }
};

class F : public E {
public:
    F() { std::cout << "F()"; }

    void print() { std::cout << "F"; }

    virtual ~F() { std::cout << "~F()"; }
};


#endif //EXECICES_EX3_H
