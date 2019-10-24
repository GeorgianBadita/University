
#ifndef LAB6_MY_VECTOR_H
#define LAB6_MY_VECTOR_H


#include <iostream>
#include <functional>


template <typename ElementT>
class IteratorVector;

//Representing our node structure for the linked list

template <typename ElementT>
class Node{
public:
    ElementT value;
    Node* next;
    /*
     * Function which constructs a new node
     * :param val: the value of the node
     * :post: the next node after the created node is nullptr
     */
    //creeaza
    explicit Node(const ElementT& val):value{val}, next{nullptr}{}

};


/*
 * Class for representing our iterator
 */
template <typename ElementT>
class IteratorVector{
private:
    Node<ElementT>* iter_node;
public:

    /*
     * Function which constructs a new iterator for a linked list
     * :param: node - the linked list node
     * :post: a new iterator will be created
     */
    //creeaza
    explicit IteratorVector(Node<ElementT>* node): iter_node{node} {}
    IteratorVector():iter_node{nullptr}{}
    ~IteratorVector(){
        iter_node = nullptr;
    }

    //Overiding opearators
    bool valid() const { return iter_node != nullptr;}
    bool operator==(const IteratorVector& other) noexcept { return iter_node == other.iter_node;}
    bool operator!=(const IteratorVector& other) noexcept { return iter_node != other.iter_node;}

    //Next operator
    //urmator
    IteratorVector& operator++(){
        if(iter_node != nullptr){
            iter_node = iter_node->next;
        }
        return *this;
    }
    //
    IteratorVector& operator++(int){

        if(iter_node != nullptr){
            iter_node = iter_node->next;
        }
        return *this;
    }

    //Dereference
    //element
    ElementT& operator*(){
        return iter_node->value;
    }


    //defining iterator + with integers
    IteratorVector& operator+(int times){
        while(this->valid() && times){
            this->iter_node = this->iter_node->next;
            times --;
        }
        return *this;
    }
};

//Representing our vector class
template <typename ElementT>
class TVector {
private:
    Node<ElementT>* head;
public:

    /*
     * Constructor of an empty list
     */
    //creeaza
    TVector():head{nullptr}{}

    /*
     * Destructor of a vector
     * RULE OF 3
     */
    //distruge
    ~TVector(){
        Node<ElementT>* start = this->head;
        while(start != nullptr){
            Node<ElementT>* next = start->next;
            delete start;
            start = next;
        }
    }

    /*
     * Copy constructor
     * RULE OF 3
     */
    TVector(const TVector& ot){
        auto new_head = new Node<ElementT>(ot.head->value);
        this->head = new_head;
        Node<ElementT>* counter = ot.head ->next;
        while(counter != nullptr){
            auto to_add = new Node<ElementT>(counter->value);
            new_head->next = to_add;
            new_head = new_head->next;
            counter = counter->next;

        }
    }

    /*
     * Assignment operator
     * RULE OF 3
     */
    TVector& operator=(const TVector& ot){
        if(this == &ot){
            return *this; //list=list
        }

        Node<ElementT>* start = this->head;
        while(start != nullptr){
            Node<ElementT>* next = start->next;
            delete start;
            start = next;
        }

        auto new_head = new Node<ElementT>(ot.head->value);
        this->head = new_head;
        Node<ElementT>* counter = ot.head ->next;
        while(counter != nullptr){
            auto to_add = new Node<ElementT>(counter->value);
            new_head->next = to_add;
            new_head = new_head->next;
            counter = counter->next;
        }
        return *this;
    }

    /*
     * Move constructor
     * RULE OF 5
     */
    TVector(TVector&& ot) noexcept:head(nullptr) {
        this->head = ot.head;
        ot.head = nullptr;
    }

    /*
     * Move assignment
     * RULE OF 5
     */
    TVector& operator=(TVector&& ot) noexcept {
        if(this != &ot){
            Node<ElementT>* start = this->head;
            while(start != nullptr){
                Node<ElementT>* next = start->next;
                delete start;
                start = next;
            }

            this->head = ot.head;
            ot.head = nullptr;
        }
        return *this;
    }


    /*
     * Function which adds an element on the last position
     * :param elem: the element we want to add
     */
    void push_back(const ElementT& elem){

        auto node = new Node<ElementT>(elem);

        if(this->head == nullptr){  //If we don't have any elements in list
            head = node;
        }
        else{
            Node<ElementT>* search = this->head;
            while(search -> next != nullptr){
                search = search->next;
            }
            search->next = node;
        }
    }

    ElementT& operator[](int i){
        int n = 0;
        Node<ElementT>* count = this->head;
        while(n < i && count != nullptr){
            count = count -> next;
            n ++;
        }
        if(count != nullptr){
            return count->value;
        }
    }
    /*
     * Function that counts how many elements are in a vector
     */
    int size() const noexcept {
        if(this->head == nullptr){
            return 0;
        }
        int n = 1;
        Node<ElementT>* node = this->head;
        while(node -> next != nullptr){
            n ++;
            node = node -> next;
        }
        return n;
    }

    /*
     * Function that tells if a vector is emptry
     */
    bool empty(){
        return this->size() == 0;
    }

    friend class IteratorVector<ElementT>;


    IteratorVector<ElementT> begin(){
        return IteratorVector<ElementT>(this->head);
    }

    IteratorVector<ElementT> end(){
        return IteratorVector<ElementT>(nullptr);
    }

    //Function that deletes an element by giving the iterator  + position
    void erase(IteratorVector<ElementT> it){
        auto to_del = *it;
        if(!it.valid()){
            return;
        }
        auto node = this->head;

        if(to_del == node->value){
            auto remind = this->head;
            this->head = this->head->next;
            delete remind;
            return;
        }

        while(node->next->value != to_del){
            node = node->next;
        }
        auto remind = node->next;
        node->next = node->next->next;
        delete remind;
    }
};


#endif //LAB6_MY_VECTOR_H
