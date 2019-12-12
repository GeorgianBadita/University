//
// Created by georg on 11/22/2019.
//

#ifndef ADDPOLYPARALLEL_POLYNOMIAL_H
#define ADDPOLYPARALLEL_POLYNOMIAL_H

#include <mutex>
#include "Node.h"
#include <iostream>

class Friendships {
private:
    Node* head;
    std::mutex* listLock;

public:
    /**
     * Constructor for polynomial class
     */
    Friendships(): head{nullptr}, listLock{new std::mutex} {}

    /**
     * Function to add a monomial to a polynomial locking the whole list
     * @param coeff - coefficient
     * @param degree - friendsMap of monomial
     * @result - if there is already a monomial with the given friendsMap add the coefficient to it, else add the new monomial
     * to the polynomial
     */
    void addNodeListLock(const std::string& personName, const std::string& friendName);


    void printFriendships(){
        auto head = this->getHead();
        while(head != nullptr){
            std::cout << "{\n";
            std::cout << head->getLetter() << ": ";
            for(const auto& x : head->getPeople()){
                std::cout << x.first << "[ ";
                for(const auto& y : x.second){
                    std::cout << y << ' ';
                }
                std::cout << "]\n";
            }
            std::cout << "}\n";
            head = head->next;
        }
    }

    /**
     * Getters
     */
     Node* getHead() {return this->head;}

     /**
      * Destructor for Friendships class
      */
     ~Friendships();
};


#endif //ADDPOLYPARALLEL_POLYNOMIAL_H
