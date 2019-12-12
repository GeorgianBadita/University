//
// Created by georg on 11/22/2019.
//

#include "Friendships.h"

#include <map>

void Friendships::addNodeListLock(const std::string & personName, const std::string & friendName){
    this->listLock->lock();
    char firstLetter = personName[0];
    std::map<std::string, std::vector<std::string>> my_map;
    std::vector<std::string> nameLst;
    nameLst.push_back(friendName);
    my_map.insert( std::make_pair(personName, nameLst) );
    auto* newMonomial = new Node(firstLetter, my_map);
    if(head == nullptr){
        head = newMonomial;
        this->listLock->unlock();
    }else{
        auto* tmp = head;
        auto* prev = head;
        while(tmp != nullptr && firstLetter < tmp->getLetter()){
            prev = tmp;
            tmp = tmp->next;
        }

        if(tmp == nullptr){
            prev->next = newMonomial;
            newMonomial->next = nullptr;
            this->listLock->unlock();
            return;
        }
        if(firstLetter == tmp->getLetter()){
            auto map = tmp->getPeople();
            bool already_in = false;
            for(const auto& elem : map){
                auto name = elem.first;
                if(name == personName){
                    std::vector<std::string> names = elem.second;
                    names.push_back(friendName);
                    map[personName] = names;
                    already_in = true;
                    break;
                }
            }
            if(!already_in){
                std::vector<std::string> names;
                names.push_back(friendName);
                map.insert( std::make_pair(personName, names) );

            }
            tmp->setMap(map);
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



Friendships::~Friendships() {

}

