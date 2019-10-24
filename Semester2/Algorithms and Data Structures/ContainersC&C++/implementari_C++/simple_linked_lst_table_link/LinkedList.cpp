//
// Created by geo on 4/28/18.
//

#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
    /*
     * The list is empty
     */
    this->first = -1;

    /*
     * All elements are free
     */
    for(int i = 0; i<this->cp - 1; i++){
        this->next[i] = i + 1;
    }
    this->next[this->cp - 1] = -1;

    /*
     * Reference for the first element which is free
     */
    this->first_free = 0;
}

int LinkedList::allocate() {
    /*
     * We delete the first element from free space list
     */
    int i = this->first_free;
    this->first_free = this->next[this->first_free];

    /*
     * Returns the first free position
     */
    return i;
}

void LinkedList::deallocate(int i) {
    /*
     * We make our node the first free element, and we set its next node
     * as the current first free node
     */
    this->next[i] = this->first_free;
    this->first_free = i;
}


int LinkedList::create_node(TElem e) {
    //TODO: if here we have a dynamic vector, we'd resize it in case we need it
    int i = allocate();
    if(i != -1){ //there is free space in the list
        this->e[i] = e;
        this->next[i] = -1;
    }
    return i;
}

/*
 * Add at the beginning
 */
void LinkedList::add_elem(TElem elem) {
    int node = create_node(elem);
    /*
     * Here we have a newly created node whose's next element is inconsistent (-1)
     */
    if(node != -1){
       //we check for a node = -1, because we use a static vector
        this->next[node] = this->first;
        this->first = node;
    }
}

/*
 * Function for searching an element
 */
bool LinkedList::search_elem(TElem elem) {
    int first_node = this->first;
    if(first_node == -1){
        return false;
    }
    while(first_node != -1){
        if(this->e[first_node] == elem){
            return true;
        }
        first_node = this->next[first_node];
    }
    return false;
}

/*
 * Function for getting the length of the linked list
 */
int LinkedList::size() {
    int len = 0;
    int first_node = this->first;
    if(first_node == -1){
        return len;
    }
    while(first_node != -1){
        len ++;
        first_node = this->next[first_node];
    }
    return len;
}

/*
 * Function for deleting an element
 */
TElem LinkedList::delete_elem(int i) {
    auto elem = this->e[i];
    if(i == this->first){
        this->first = this->next[first];
    }
    else{
        auto j = this->first;
        while(this->next[j] != i){
            j = this->next[j];
        }
        this->next[j] = this->next[i];
        deallocate(i);
    }
    return elem;
}


Iterator LinkedList::iterator() const {
    return Iterator(*this);
}

/*
 * Iterator constructor
 */
Iterator::Iterator(const LinkedList &lst): linked_list{lst}{
    this->current = this->linked_list.first;
}

/*
 * Function which sets an iterator to the first element of the list
 */
void Iterator::begin() {
    this->current = this->linked_list.first;
}

/*
 * Function which goes to the next element
 */
void Iterator::next(){
    this->current = this->linked_list.next[current];
}

/*
 * Function for validating an iterator
 */
bool Iterator::valid() const {
    return this->current != -1;
}

/*
 * Function for getting the current element in the iterator
 */
TElem Iterator::get_element() const {
    return this->linked_list.e[current];
}