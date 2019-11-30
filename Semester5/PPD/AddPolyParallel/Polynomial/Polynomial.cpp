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



void Polynomial::addMonomialListLock(const int &coeff, const int &degree) {
    this->listLock->lock();
    auto* newMonomial = new Monomial(coeff, degree);
    if(head == nullptr){
        head = newMonomial;
        this->listLock->unlock();
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
            this->listLock->unlock();
            return;
        }
        if(degree == tmp->getDegree()){
            tmp->setCoefficient(tmp->getCoefficient() + coeff);
            this->listLock->unlock();
            return;
        }
        if(tmp != prev){
            prev->next = newMonomial;
            newMonomial->next = tmp;
            this->listLock->unlock();
        }else{
            newMonomial->next = prev;
            head = newMonomial;
            this->listLock->unlock();
        }

    }
    this->listLock->unlock();
}



Polynomial::~Polynomial() {

}


void Polynomial::addMonomialNodeLock(const int &coeff, const int& degree) {
    this->listLock->lock(); //needed in case of head null
    auto* newMonomial = new Monomial(coeff, degree);
    if(head == nullptr){
        head = newMonomial;
        this->listLock->unlock();
        return;
    }else{
        listLock->unlock();
        auto* tmp = head;
        auto* prev = head;
        while(tmp != nullptr && degree < tmp->getDegree()){
            prev = tmp;
            tmp = tmp->next;
        }
        prev->nodeLock->lock();
        if(tmp == nullptr){
            prev->next = newMonomial;
            newMonomial->next = nullptr;
            prev->nodeLock->unlock();
            return;
        }else{
            prev->nodeLock->unlock();
        }
        tmp->nodeLock->lock();
        if(degree == tmp->getDegree()){
            tmp->setCoefficient(tmp->getCoefficient() + coeff);
            tmp->nodeLock->unlock();
            return;
        }else{
            tmp->nodeLock->unlock();
        }
        tmp->nodeLock->lock();
        prev->nodeLock->lock();
        if(tmp != prev){
            prev->next = newMonomial;
            newMonomial->next = tmp;
            prev->nodeLock->unlock();
            tmp->nodeLock->unlock();
        }else{
            newMonomial->next = prev;
            head = newMonomial;
            prev->nodeLock->unlock();
            tmp->nodeLock->unlock();
        }

    }
}
