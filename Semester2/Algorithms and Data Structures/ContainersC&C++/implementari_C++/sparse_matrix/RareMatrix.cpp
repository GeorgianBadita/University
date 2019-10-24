//
// Created by geo on 4/29/18.
//

#include <omp.h>
#include "RareMatrix.h"

RareMatrix::RareMatrix(): first{nullptr}, last{nullptr} {}


bool rel(Triplet& t1, Triplet& t2){
    if(t1.line < t2.line){
        return true;
    }
    else if(t1.line == t2.line){
        if(t1.column <= t2.column){
            return true;
        }
    }
    return false;
}

/*
* Function to add a new triplet into the matrix
* :param tr: the triplet to be added
*/
void RareMatrix::add_new_elem(Triplet tr){
    auto current_node = this->first;
    while(current_node != nullptr && !rel(tr, current_node->value)){
        current_node = current_node->next;
    }

    if(current_node != nullptr && current_node->value.column == tr.column && current_node->value.line == tr.line){
        return;
    }

    if(current_node == this->first){
        auto to_add = new Node(tr);
        to_add->next = this->first;
        this -> first->prev = to_add;
        this ->first = to_add;
    }
    else if(current_node == nullptr){
        auto to_add = new Node(tr);
        this->last->next = to_add;
        to_add->prev = this->last;
        this->last = to_add;
        this->last->next = nullptr;

    }
    else{
        auto prev_node = current_node->prev;
        auto to_add = new Node(tr);
        to_add->next = current_node;
        prev_node->next = to_add;
        to_add->prev = prev_node;
        current_node->prev = to_add;
    }
}

Iterator RareMatrix::iterator() const{
    return Iterator(*this);
}

/*
 * Iterator function
 */
Iterator::Iterator (const RareMatrix& mt):mat{mt}{
    this->current = mat.first;
}

void Iterator::next() {
    this->current = this->current->next;

}

bool Iterator::valid() {
    return this->current != nullptr;
}

Triplet Iterator::get_elem(){
    return this->current->value;
}