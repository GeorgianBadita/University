//
// Created by geo on 17.06.2020.
//

#ifndef EXECICES_SUBIECT2013_H
#define EXECICES_SUBIECT2013_H

#include <string>
#include <iostream>
#include <utility>
#include <list>

class Produs {
private:
    std::string denumire;
public:

    explicit Produs(std::string d) : denumire(std::move(d)) {}

    void afisareDenumire() {
        std::cout << "Denumire: " << this->denumire << '\n';
    }

    const std::string &getDenumire() const {
        return this->denumire;
    }

    virtual ~Produs() = default;
};

class ProdusPerisabil : public Produs {
private:
    int valabilitate;
public:
    ProdusPerisabil(std::string denumire, int valabilitate) : Produs(std::move(denumire)), valabilitate(valabilitate) {}

    void afisareDate() {
        Produs::afisareDenumire();
        std::cout << "Valabilitate: " << this->valabilitate << '\n';
    }

    ~ProdusPerisabil() override = default;
};





#endif //EXECICES_SUBIECT2013_H
