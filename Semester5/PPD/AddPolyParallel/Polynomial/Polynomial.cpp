//
// Created by georg on 11/22/2019.
//

#include "Polynomial.h"



std::ostream &operator<<(std::ostream &os, const Polynomial &dt) {
    auto* tmp = dt.head;
    bool isFirst = true;
    std::string space = " ";
    std::string xpow = "x^";
    std::string minus = "-";
    std::string plus = "+";
    while(tmp != nullptr){
        int degree = tmp->getDegree();
        int coeff = tmp->getCoefficient();
        if(isFirst){
            os << std::to_string(coeff) << xpow << std::to_string(degree) << space;
            isFirst = !isFirst;
        }
        else if(degree != 0){
            if(coeff < 0){
                os << space <<minus << space<< std::to_string(std::abs(coeff)) << xpow << std::to_string(degree) << space;
            }else{
                os << space <<plus << space<< std::to_string(std::abs(coeff)) << xpow << std::to_string(degree) << space;
            }
        }
        else {
            if (coeff < 0) {
                os << space << minus << space << std::to_string(std::abs(coeff)) << space;
            } else {
                os << space << plus << space << std::to_string(std::abs(coeff)) << space;
            }
        }
        tmp = tmp->next;
    }
    return os;
}



void Polynomial::addMonomial(const int &coeff, const int &degree) {
    auto* newMonomial = new Monomial(coeff, degree);
    if(head == nullptr){
        head = newMonomial;
    }else{
        auto* tmp = head;
        auto* prev = head;
        while(tmp != nullptr && degree < tmp->getDegree()){
            prev = tmp;
            tmp = tmp->next;
        }

        if(tmp == nullptr){
            prev->next = newMonomial;
            newMonomial->next = nullptr;
            return;
        }
        if(degree == tmp->getDegree()){
            tmp->setCoefficient(tmp->getCoefficient() + coeff);
            return;
        }
        if(tmp != prev){
            prev->next = newMonomial;
            newMonomial->next = tmp;
        }else{
            newMonomial->next = prev;
            head = newMonomial;
        }

    }
}



Polynomial::~Polynomial() {
    destroyPoly();
}

void Polynomial::destroyPoly() {
    if(this->head != nullptr){
        auto tmp = this->head;
        this->head = this->head->next;
        destroyPoly();
        delete tmp;
    }
}
