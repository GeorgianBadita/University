//
// Created by geo on 16.06.2020.
//

#ifndef EXECICES_EX6_H
#define EXECICES_EX6_H

#include<iostream>

class H {
public:
    H() { std::cout << "H()"; }

    virtual void f() { std::cout << "H.f"; }

    void g() { f(); }

    virtual void h() { g(); }
};

class I: public H{
public:
    I() { std::cout << "I()";}

    void f() {std::cout << "I.f";}

    void h() {std::cout << "Function h"; H::h();}
};


#endif //EXECICES_EX6_H
