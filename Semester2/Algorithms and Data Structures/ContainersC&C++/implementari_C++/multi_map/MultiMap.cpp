//
// Created by geo on 4/29/18.
//

#include "MultiMap.h"

#include <utility>

/*
 * Pair constructor
 */
Pair::Pair(TKey key, TValue value) :key{std::move(key)}, value{std::move(value)}{}


/*
* MultiMap constructor
*/
MultiMap::MultiMap(){
    this->first = -1;

    for(int i = 0; i<this->cp -1; i++){
        this->next[i] = i + 1;
        this->prev[i] = i - 1;
    }

    this->next[this->cp - 1] = -1;
    this->prev[this->cp - 1] = this->cp - 2;

    this->first_free = 0;
}

/*
 * Function to allocate a new space
 * :return: the reference to allocated node
 */
int MultiMap::allocate(){
    int i = this->first_free;
    this->first_free = this->next[this->first_free];
    return i;
}

/*
* Function to deallocate a new space
* :param: i the space to deallocate
*/
void MultiMap::deallocate(int i){
    this->next[i] = this->first_free;
    this->first_free = i;
}

/*
 * Function to create a new node
 * :param pr: value to be added in the node
 */
int MultiMap::create_new_node(const TPair& pr){
    int i = this->allocate();
    if(i != -1){
        this->e[i] = pr;
        this->next[i] = this->prev[i] = -1;
    }
    return i;
}

/*
 * Function which returns the first position where a key occurs
 * :param key: the key to be searched
 * :return: reference to the first occur of that key, -1 otherwise
 */
int MultiMap::search_key(const TKey& key){
    int pos = -1;
    int node = this->first;
    while(node != -1){
        if(this->e[node].key == key){
            pos = node;
            break;
        }
        node = this->next[node];
    }
    return pos;
}

int MultiMap::search_pair(const TPair& pair){
    int pos = -1;
    int node = this->first;
    while(node != -1){
        if(this->e[node] == pair){
            pos = node;
            break;
        }
        node = this->next[node];
    }
    return pos;
}

/*
 * Function which adds a new pair into the multi-map
 * :param pair: the TPair to be added
 */
void MultiMap::add_new_pair(const TPair& pair){
    int node = this->create_new_node(pair);
    if(node == -1){
        return;
    }
    int pos = this->search_key(pair.key);
    if(pos == -1){
        this->prev[node] = -1;
        this->next[node] = this->first;
        this->prev[this->first] = node;
        this->first = node;
    }
    else{
        this->next[node] = this->next[pos];
        this->prev[pos] = node;
        this->next[pos] = node;
        this->prev[node] = pos;
    }
}

/*
 *  Function which deletes a given pair
 *  :param pair: the pair to delete
 */
void MultiMap::delete_pair(const TPair& pair){
    int pair_pos = search_pair(pair);
    if(pair_pos == -1){
        return;
    }
    if(pair_pos == this->first){
        auto to_del = this->first;
        this->first = this->next[this->first];
        deallocate(to_del);
    }
    else{
        auto to_del = pair_pos;
        auto prev_node = this->prev[pair_pos];
        auto next_node = this->next[pair_pos];
        this->next[prev_node] = next_node;
        this->prev[next_node] = prev_node;
        deallocate(to_del);
    }
}

Iterator MultiMap::iterator() const{
    return Iterator(*this);
}

Iterator::Iterator(const MultiMap& map):map{map}{
    this->current = map.first;
}

void Iterator::begin() {
    this->current = map.first;
}

void Iterator::next(){
    this->current = this->map.next[current];
}

bool Iterator::is_valid() {
    return this->current != -1;
}

TPair Iterator::get_pair() {
    return this->map.e[this->current];
}