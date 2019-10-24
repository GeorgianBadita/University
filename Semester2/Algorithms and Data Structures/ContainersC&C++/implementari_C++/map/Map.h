//
// Created by geo on 4/29/18.
//

#ifndef MAP_MAP_H
#define MAP_MAP_H
#include <string>
#include <utility>

typedef std::string TKey;
typedef int TValue;

class Iterator; //Predefining iterator   class

class Pair{
public:
    TValue value;
    TKey  key;
    bool operator==(const Pair& ot){
        return ot.key == this->key;
    }
    /*
     * Pair constructor
     */
    Pair(TKey key, TValue value):key{std::move(key)}, value{value}{}
};

class Node{
public:
    Pair pair;
    Node* next;
    explicit Node(const Pair& pair);

};
/*
 * Map implementation as a simple linked list
 */
class Map {
private:
    Node* first;
public:
    /*
     * Map constructor
     * :post: creates an empty map
     */
    Map();

    /*
     * Map class destructor
     */
    ~Map();

    /*
     * Function which adds an element into the map
     * :param pr: Pair to be added
     */
    void add_element(const Pair& pr);

    /*
     * Function which searches for a key in the map
     * :return: the value if the key is in map, an invalid key otherwise
     */
    TValue search(const TKey& key);

    /*
     * Function which deletes a pair (TKey, TValue) from the map
     * :param key: the Tkey to be deleted
     * :return: will return the Pair (TKey, TValue) which has been deleted if it exits,
     * return an invalid Pair
     */
    TValue delete_key(const TKey& key);

    /*
     * Function which returns the dimension of the map
     */
    int size();

    /*
     * Overloading [] operator
     */
    TValue operator[] (const TKey& key){
        return search(key);
    };


    friend class Iterator;
    Iterator iterator() const;

};

/*
 * Iterator class for map
 */
class Iterator{
private:
    explicit Iterator(const Map& map);
    const Map& map;
    Node* current;
public:
    friend class Map;

    /*
     * Function which sets the iterator on the first position
     */
    void begin();

    /*
     * Function which sets the iterator into the next pair
     */
    void next();

    /*
     * Function which checks if the iterator is valid
     */
    bool valid();

    /*
     * Function which gets the current pair in the map
     */
    Pair get_pair();
};


#endif //MAP_MAP_H
