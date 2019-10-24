//
// Created by geo on 4/28/18.
//

#ifndef SIMPLE_LINKED_LST_TABLE_LINK_LINKEDLIST_H
#define SIMPLE_LINKED_LST_TABLE_LINK_LINKEDLIST_H
#define CAPACITY 100
typedef int TElem;


class Iterator;

class LinkedList {
private:
    static const int cp=CAPACITY;

    /*
     * Static vector for elements
     */
    TElem e[cp];

    /*
     * Linking vector
     */
    int next[cp];

    /*
     * Reference to the first element of the list
     */
    int first;

    /*
     * Reference to the first unoccupied element from the list
     */
    int first_free;

    /*
     * Function which allocates a free space
     * :returns: integer free position in list
     */
    int allocate();

    /*
     * Function which deletes a free space
     * :param i: the space to deallocate
     */
    void deallocate(int i);

    /*
     * Function which creates a new node in the linked list
     */
    int create_node(TElem e);

public:
    /*
     * Iterator class must be friend class with LinkedList class
     * in order to have access to its elements
     */
    friend class Iterator;

    /*
     * Constructor for LinkedList class
     */
    LinkedList();

    /*
     * Function which adds an element into the list
     * :param elem: TElem object to be added
     */
    void add_elem(TElem elem);

    /*
     * Function which searches for an element into the lsit
     * :param elem: the element to be searched
     * :return: true if the element exists, false otherwise
     */
    bool search_elem(TElem elem);

    /*
     * Function which gets the dimension of the linked list
     * :return: the length of the list
     */
    int size();

    /*
     * Function which deletes an element from the list
     * :param i: the element to be deleted
     * :return: returns the deleted element
     */
    TElem delete_elem(int i);

    /*
     * TODO: add operations such as, search, delete, dimension etc..
     */

    /*
     * Iterator for unidirectional traversal of the lsit
     */
    Iterator iterator() const;

    /*
     * List destructor
     */
    ~LinkedList() = default;
};


class Iterator{
private:
    /*
     * To construct an iterator for the linked list, we need a reference to it
     * :param lst: reference to a list
     */
    explicit Iterator(const LinkedList& lst);

    /*
     * Reference to the list
     */
    const LinkedList& linked_list;

    /*
     * Retains the current position of inside the colection
     */
    int current;

public:
    friend class LinkedList;

    /*
     * Function which sests the iterator to the first element of the LinkedList
     */
    void begin();

    /*
     * Function which goes with the iterator on the next element of the list
     */
    void next();

    /*
     * Verifies if the iterator is valid
     */
    bool valid() const;

    /*
     * Function which returns the current value of the iterator
     */
    TElem get_element() const;
};

#endif //SIMPLE_LINKED_LST_TABLE_LINK_LINKEDLIST_H
