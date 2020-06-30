//
// Created by geo on 16.06.2020.
//

#ifndef EXECICES_EX1_H
#define EXECICES_EX1_H

#include <iostream>
#include <string>

class B { //a
private:
    int b;
public:
    explicit B(int b) : b(b) {}

    virtual void afisare() const {
        std::cout << "Atribut B: " << this->b << '\n';
    }

    int getB() {
        return this->b;
    }

    virtual ~B() = default;
};

class D : public B { //b
private:
    std::string d;
public:
    D(int b, std::string d) : B(b), d(std::move(d)) {};

    void afisare() const override {
        B::afisare();
        std::cout << "Atribut D: " << this->d << '\n';
    }

    ~D() override = default;
};


#endif //EXECICES_EX1_H
