//
// Created by geo on 23.06.2020.
//

#ifndef EXECICES_SUBIECT2016SEPT_H
#define EXECICES_SUBIECT2016SEPT_H

#include<string>

class Entitate {
private:
    std::string oras;

public:
    explicit Entitate(const std::string &oras) {
        if (oras.empty()) {
            throw std::exception();
        }
        this->oras = oras;
    }

    const std::string &getOras() const {
        return this->oras;
    }

    virtual double sumaIncasata() = 0;

    std::string toString() {
        return this->oras + " " + std::to_string(this->sumaIncasata());
    }

};

class Student : public Entitate {
private:
    double bursa;
public:
    Student(std::string oras, double buras) : Entitate(oras), bursa(buras) {}

    double sumaIncasata() override {
        return bursa;
    }
};

class Profesor : public Entitate {
private:
    double salar;
public:
    Profesor(std::string oras, double salar) : Entitate(oras), salar(salar) {};

    double sumaIncasata() override {
        return salar;
    }
};


#endif //EXECICES_SUBIECT2016SEPT_H
