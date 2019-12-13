//
// Created by geo on 12.12.2019.
//

#ifndef CATALOG_NODE_H
#define CATALOG_NODE_H


#include <mutex>

template <class K, class V>
class LockableNode {
private:
    LockableNode* nextNode;
    K key;
    V value;
    std::mutex nodeLock;

public:


    LockableNode(K key, V value)
    {
        this->key = key;
        this->value = value;
        this->nextNode = nullptr;
    }

    virtual ~LockableNode()
    {

    }

    K getKey()
    {
        return this->key;
    }

    V getValue()
    {
        return this->value;
    }

    void setKey(K key)
    {
        this->key = key;
    }

    void setValue(V value)
    {
        this->value = value;
    }

    LockableNode* getNext()
    {
        return this->nextNode;
    }

    void setNext(LockableNode *nextNode)
    {
        this->nextNode = nextNode;
    }

    void lockNode()
    {
        this->nodeLock.lock();
    }

    void unlockNode()
    {
        this->nodeLock.unlock();
    }

};


#endif //CATALOG_NODE_H
