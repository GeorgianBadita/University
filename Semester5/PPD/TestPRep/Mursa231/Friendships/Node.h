//
// Created by georg on 11/22/2019.
//

#ifndef ADDPOLYPARALLEL_MONOMIAL_H
#define ADDPOLYPARALLEL_MONOMIAL_H

#include <map>
#include <mutex>
#include <string>
#include <utility>
#include <vector>
class Node {
private:
    char letter;
    std::map<std::string, std::vector<std::string>> friendsMap;

public:
    std::mutex* nodeLock;
    Node* next;
    /**
     * Constructor for monomial class
     * @param val  - Node coefficient
     * @param degree - Node's friendsMap
     */
    Node(const char& val, std::map<std::string, std::vector<std::string>> friendsMap): letter{val}, friendsMap{std::move(friendsMap)}, next{nullptr}, nodeLock{new std::mutex} {}

    /**
     * Default constructor for monomial class
     */
    Node(): letter{-1}, next{nullptr}, nodeLock{new std::mutex}{}

    /**
     * Getters
     */
    char getLetter() const {return this->letter;}
    std::map<std::string, std::vector<std::string>> getPeople() const {return this->friendsMap; }

    /**
     * Setters
     */
     void setLetter(const char& newCoeff) {this->letter = newCoeff;}
     void setMap(const std::map<std::string, std::vector<std::string>>& map) {this->friendsMap = map;}

     ~Node(){
         //delete nodeLock;
     }
};


#endif //ADDPOLYPARALLEL_MONOMIAL_H
