//
// Created by geo on 4/29/18.
//

#ifndef MULTI_MAP_MULTIMAP_H
#define MULTI_MAP_MULTIMAP_H
#define CAPACITY 100;

#include <string>

typedef std::string TKey;
typedef std::string TValue;

class Pair;

typedef Pair TPair;

class Iterator; //Predefining iterator class

class Pair{
public:
    TKey key;
    TValue value;
    Pair(TKey key, TValue value);
    Pair() = default;

    bool operator==(const Pair& ot){
        return ot.value == this->value && ot.key == this->key;
    }
};


class MultiMap {
private:
    static const int cp = CAPACITY;
    /*
     * Vector to store the pairs
     */
    TPair e[cp];

    /*
     * Vector to store the next element of a node
     */
    int next[cp];

    /*
     * Vector to store the previous element of a node
     */
    int prev[cp];

    /*
     * Reference to the first element in the list
     */
    int first;


    /*
     * Reference to the first free element of the list
     */
    int first_free;
public:
    /*
     * MultiMap constructor
     */
    MultiMap();

    /*
     * Function to allocate a new space
     * :return: the reference to allocated node
     */
    int allocate();

    /*
    * Function to deallocate a new space
    * :param: i the space to deallocate
    */
    void deallocate(int i);

    /*
     * Function which returns the first position where a key occurs
     * :param key:
     */
    int search_key(const TKey& key);

    /*
     * Function to create a new node
     * :param pr: value to be added in the node
     */
    int create_new_node(const TPair& pr);

    /*
     * Function which adds a new pair into the multi-map
     * :param pair: the TPair to be added
     */
    void add_new_pair(const TPair& pair);

    /*
     *  Function which deletes a given pair
     *  :param pair: the pair to delete
     */
    void delete_pair(const TPair& pair);

    /*
     * Function to search for a given pair
     * :param pair: the pair to search
     * :return: reference to the pair if it exists, -1 otherwise
     */
    int search_pair(const TPair& pair);

    friend class Iterator;
    Iterator iterator() const;
};

/*
 * Our Iterator class
 */
class Iterator{
private:
    explicit Iterator(const MultiMap& map);
    const MultiMap& map;
    int current; //reference to the current element

public:

    friend class MultiMap;

    /*
     * Function to set our iterator on the first position
     */
    void begin();

    /*
     * Function to set our iterator on the next position
     */
    void next();

    /*
     * Function to check if our iterator is still valid
     */
    bool is_valid();

    /*
     * Function to get our current TPair
     */
    TPair get_pair();

};
#endif //MULTI_MAP_MULTIMAP_H
