//
// Created by geo on 4/29/18.
//

#ifndef DOUBLE_LINKED_LST_TABLE_LINK_DLINKEDLIST_H
#define DOUBLE_LINKED_LST_TABLE_LINK_DLINKEDLIST_H
#define CAPACITY 100

typedef int TElem;
class Iterator; //predeclaring Iterator class

/*
 * Double Linked List with table links class implementation
 */
class DLinkedList {
private:
    /*
     * The capacity of the linked lsit
     */
    static const int cp = CAPACITY;

    /*
     * Vector to store our elements
     */
    TElem e[cp];

    /*
     * Where we'll store the next node of the current node
     */
    int next[cp];

    /*
     * Where we'll store the previous node of the current node
     */
    int prev[cp];

    /*
     * First free element of the list
     */
    int first_free;

    /*
     * First occupied element
     */
    int first;

    /*
     * Last occupied element
     */
    int last;

public:

    /*
     * We mark Iterator class as friend class, so that Iterator can access DLinkedList attributes
     */
    friend class Iterator;

    /*
     * Function to allocate a free space
     * :return: node index
     */
    int allocate();

    /*
     * Function to deallocate a space
     * :param i: the node indexed with i will be dealocated
     */
    void deallocate(int i);

    /*
     * Function which creates a new node
     */
    int create_node(TElem el);

    /*
     * Linked list class constructor
     */
    DLinkedList();

    /*
     * Destructor of the class
     */
    ~DLinkedList() = default;

    /*
     * Function to add an element into the list at the beginning
     */
    void add_elem_front(TElem el);

    /*
     * Function to get the length of the list
     */
    int size();

    /*
     * Function to delete the element indexed at i
     * :param i: the element to be deleted
     */
    void delete_elem(int i);

    /*
     * Function to delete the first node of the list
     */
    void delete_front();

    /*
     * Function to delete the last element of the list
     */
    void delete_last();

    /*
     * Function to search an element into the list
     * :param el: TElem object to be searched
     * :preturn: the position of the element if it exists, -1 otherwise
     */
    int search_elem(TElem el);


    /*
     * Function to add an element after a given position
     */
    void add_element_after(int i, TElem el);

    /*
     * Iterator methods
     */
    Iterator iterator() const;
};

/*
 * Our iterator class
 */
class Iterator{
private:
    /*
     * Iterator constructor
     */
    explicit Iterator(const DLinkedList& lst);

    /*
     * Current position in DlinkedList
     */
    int current;

    /*
     * Reference to the linked list
     */
    const DLinkedList& lst;

public:
    /*
     * Declaring DLinkedList as friend class of the iterator
     */
    friend class DLinkedList;

    /*
     * Function to set the iterator on the first position
     */
    void begin();

    /*
     * Function to set the iterator in the last position
     */
    void end();

    /*
     * Function to go on the next element
     */
    void next();

    /*
     * Function to go on the previous element
     */
    void prev();

    /*
     * Checks if the iterator is still valid
     */
    bool valid();

    /*
     * Function which returns the current element
     */
    TElem get_elem();
};

#endif //DOUBLE_LINKED_LST_TABLE_LINK_DLINKEDLIST_H
