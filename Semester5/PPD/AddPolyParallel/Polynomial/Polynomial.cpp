//
// Created by georg on 11/22/2019.
//

#include "Polynomial.h"


std::ostream &operator<<(std::ostream &os, const Polynomial &dt) {
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