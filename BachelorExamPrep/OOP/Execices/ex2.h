//
// Created by geo on 16.06.2020.
//

#ifndef EXECICES_EX2_H
#define EXECICES_EX2_H

#include <iostream>

class C {
public:
    C() { std::cout << "C()"; }

    void print() { std::cout << "C"; }

    virtual ~C() { std::cout << "~C()"; }
};

class D : public C {
public:
    D() { std::cout << "D()"; }

    void print() { std::cout << "D"; }

    virtual ~D() { std::cout << "~D()"; }
};


#endif //EXECICES_EX2_H
