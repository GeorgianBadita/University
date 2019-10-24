//
// Created by geo on 4/29/18.
//

#include <iostream>
#include "DLinkedList.h"

DLinkedList::DLinkedList() {
    this->first = -1;
    this->last = -1;

    for(int i = 0; i < this->cp - 1; i++){
        this->e[i] = 0;
        this->next[i] =  i + 1;
        this->prev[i] = i - 1;
    }
    this->prev[this->cp - 1] = this->cp - 2;
    this->next[this->cp - 1] = -1;
    this->first_free = 0;
    this->e[this->cp - 1] = 0;
}

int DLinkedList::allocate() {
    /*
     * Getting the first free element
     */
    int i = this->first_free;
    this->first_free = this->next[this->first_free];

    /*
     * returning the element
     */
    return i;
}

void DLinkedList::deallocate(int i) {
    /*
     * Adding the i'th node to the free space list
     */
    this->next[i] = this->first_free;
    this->first_free = i;
}

int DLinkedList::create_node(TElem el) {
    int i = allocate();
    if(i != -1){
        this->e[i] = el;
        this->next[i] = -1;
        this->prev[i] = -1;
    }
    return i;
}

void DLinkedList::add_elem_front(TElem el) {
    /*
     * Adding a an element in front of the linked list
     */
    int i = create_node(el);
    if(i == -1) {//we're out of space
        return;
    }
    else if(this->first == -1){
        this->prev[first] = i;
        this->next[i] = this->first;
        this->first = i;
        this->prev[i] = -1;
        this->last = i;
    }else{
        this->prev[first] = i;
        this->next[i] = this->first;
        this->first = i;
        this->prev[i] = -1;
    }
}

int DLinkedList::size() {
    int sz = 0;
    auto new_first = this->first;
    while(new_first != -1){
        new_first = this->next[new_first];
        sz ++;
    }
    return sz;
}

void DLinkedList::add_element_after(int i, TElem el) {
    int j = create_node(el);
    if(j == -1){
        return;
    }
    auto next_node = this->next[i];
    this->prev[next_node] = j;
    this->next[j] = next_node;
    this->next[i] = j;
    this->prev[j] = i;
}

int DLinkedList::search_elem(TElem el) {
    int pos = -1;
    auto node_f = this->first;
    while(node_f != -1){
        if(this->e[node_f] == el){
            pos = node_f;
            break;
        }
        node_f = this->next[node_f];
    }
    return pos;
}


void DLinkedList::delete_front(){
    int i = this->first;
    this->first = this->next[this->first];
    this->prev[this->first] = -1;
    deallocate(i);
}

void DLinkedList::delete_last(){
    int i = this->last;
    this->last = this->prev[this->last];

    this->next[this->last] = -1;
    deallocate(i);
}

void DLinkedList::delete_elem(int i) {
    if(i < 0){
        return;
    }
    if(this->size() == 1){
        this->first = -1;
        this->first_free = 0;
        this->last = -1;
        deallocate(i);
    }
    else if(i == this->first){
        this->delete_front();
    }
    else if(i == this->last){
        this->delete_last();
    }
    else {
        auto prev_node = this->prev[i];
        auto next_node = this->next[i];
        this->next[prev_node] = next_node;
        this->prev[next_node] = prev_node;
        deallocate(i);
    }
}

Iterator DLinkedList::iterator() const {
    return Iterator(*this);
}

Iterator::Iterator(const DLinkedList &lst): lst{lst} {
    this->current = this->lst.first;
}

void Iterator::begin() {
    this->current = this->lst.first;
}

void Iterator::end(){
    this->current = this->lst.last;
}

void Iterator::next() {
    this->current = this->lst.next[current];
}

bool Iterator::valid() {
    return this->current != -1;
}

void Iterator::prev() {
    this->current = this->lst.prev[current];
}

TElem Iterator::get_elem() {
    return this->lst.e[this->current];
}