//
// Created by geo on 4/29/18.
//

#include <iostream>
#include "Map.h"

/*
 * Node constructor
 */
Node::Node(const Pair& pair) :pair{pair}{
    this->next = nullptr;
}

/*
 * Map constructor
 */
Map::Map():first{nullptr}{}



/*
 * Map destructor
 */
Map::~Map() {
    auto f_node = this->first;
    while(f_node != nullptr){
        auto next = f_node->next;
        delete f_node;
        f_node = next;
    }
    delete f_node;
}

/*
 * Function which searches for a key in the map
 * :return: the value if the key is in map, an invalid key otherwise
 */
TValue Map::search(const TKey& key){
    auto first_node = this->first;
    while(first_node != nullptr){
        if(first_node->pair.key == key){
            return first_node->pair.value;
        }
        first_node = first_node->next;
    }
    return -1; //invalid value
}


/*
  * Function which adds an element into the map
  * :param pr: Pair to be added
  */
void Map::add_element(const Pair& pr){
    if(search(pr.key) != -1){
        return;
    }
    if(this->first == nullptr){
        this->first = new Node(pr);
    }
    else {
        auto node = new Node(pr);
        node->next = this->first;
        this->first = node;
    }
}

/*
 * Function which deletes a pair (TKey, TValue) from the map
 * :param key: the Tkey to be deleted
 * :return: will return the Pair (TKey, TValue) which has been deleted if it exits,
 * return an invalid Pair
 */
TValue Map::delete_key(const TKey& key){
    if(search(key) == -1){
        return -1;
    }
    TValue value_rt;
    auto f_node = this->first;
    if(f_node->pair.key == key){
        auto to_del = this->first;
        value_rt = to_del->pair.value;
        this->first = this->first->next;

       // std::cout << this->first->pair.key << " -> " << this->first->pair.value << '\n';
        delete to_del;
    }
    else {
        while (f_node->next != nullptr && f_node->next->pair.key != key) {
            f_node = f_node->next;
        }
        auto to_bond = f_node->next->next;
        value_rt = f_node->next->pair.value;
        delete f_node->next;
        f_node->next = to_bond;
    }
    return value_rt;

}

/*
 * Function which returns the dimension of the map
 */
int Map::size(){
    int sz = 0;
    if(this->first == nullptr){
        return 0;
    }
    auto f_node = this->first;
    while(f_node != nullptr){
        sz ++;
        f_node = f_node->next;
    }
    return sz;
}

/*
 * Iterator constructor
 */
Iterator Map::iterator() const {
    return Iterator(*this);
}

Iterator::Iterator(const Map &map): map{map}{
    this->current = map.first;
}

/*
 * Function which sets the iterator on the first position
 */
void Iterator::begin(){
    this->current = map.first;
}

/*
 * Function which sets the iterator into the next pair
 */
void Iterator::next(){
    this->current = this->current->next;
}

/*
 * Function which checks if the iterator is valid
 */
bool Iterator::valid(){
    return this->current != nullptr;
}

/*
 * Function which gets the current pair in the map
 */
Pair Iterator::get_pair(){
    return this->current->pair;
}
