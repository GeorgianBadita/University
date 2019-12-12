//
// Created by geo on 12.12.2019.
//

#ifndef CATALOG_LINKEDLIST_H
#define CATALOG_LINKEDLIST_H

#include <iostream>
#include "Node.h"

template <class K, class V>
class LinkedList
{
protected:
    typedef bool(*vFilterFunctionCall)(V filterObject);
    LockableNode<K, V>* head;
    std::mutex listLock;
public:
    LinkedList()
    {

    }

    virtual ~LinkedList()
    {
        listLock.lock();
        LockableNode<K, V>* currentNode = nullptr;
        LockableNode<K, V>* nextNode = nullptr;

        currentNode = head;

        while (nullptr != currentNode)
        {
            nextNode = currentNode->getNext();
            delete currentNode;
            currentNode = nextNode;
        }


        listLock.unlock();
    }

    void printList()
    {
        listLock.lock();
        LockableNode<K, V>* currentNode = nullptr;
        LockableNode<K, V>* nextNode = nullptr;

        std::cout << "Starting to print the list: " << std::endl;

        currentNode = head;

        while (nullptr != currentNode)
        {
            std::cout << "Key: { " << currentNode->getKey() << " }; Value: { " << currentNode->getValue() << " };" << std::endl;
            //std::cout << "Key: { " << currentNode->getKey() << " }\n";

            nextNode = currentNode->getNext();
            currentNode = nextNode;
        }

        std::cout << "Done printing the list." << std::endl;

        listLock.unlock();
    }

    void printFilteredList(vFilterFunctionCall filterFunction)
    {
        listLock.lock();
        LockableNode<K, V>* currentNode = nullptr;
        LockableNode<K, V>* nextNode = nullptr;

        std::cout << "Starting to print the list: " << std::endl;

        currentNode = head;

        while (nullptr != currentNode)
        {
            if (filterFunction(currentNode->getValue()))
            {
                std::cout << "Key: { " << currentNode->getKey() << " }; Value: { " << currentNode->getValue() << " };" << std::endl;
                //std::cout << "Key: { " << currentNode->getKey() << " }\n";
            }

            nextNode = currentNode->getNext();
            currentNode = nextNode;
        }

        std::cout << "Done printing the list." << std::endl;

        listLock.unlock();
    }

    void pushBack(K key, V value)
    {
        LockableNode<K, V>* currentNode = nullptr;
        LockableNode<K, V>* nextNode = nullptr;

        listLock.lock(); // Needed in case of null head

        if (head == nullptr)
        {
            head = new LockableNode<K, V>(key, value);
            listLock.unlock();
            return;
        }

        currentNode = head;
        currentNode->lockNode();

        listLock.unlock(); // Unlock the 'list-entry' lock

        nextNode = currentNode->getNext();
        if (nextNode != nullptr)
        {
            nextNode->lockNode();
        }

        while (nextNode != nullptr)
        {
            currentNode->unlockNode();
            currentNode = nextNode;

            nextNode = currentNode->getNext();
            if (nextNode != nullptr)
            {
                nextNode->lockNode();
            }
        }

        currentNode->setNext(new LockableNode<K, V>(key, value));
        currentNode->unlockNode();
    }

    void deleteAllWithKey(K key)
    {
        listLock.lock();
        LockableNode<K, V>* currentNode = nullptr;
        LockableNode<K, V>* nextNode = nullptr;

        if (nullptr == head)
        {
            listLock.unlock();
            return;
        }

        currentNode = head;
        currentNode->lockNode();
        nextNode = currentNode->getNext();
        if (nextNode != nullptr)
        {
            nextNode->lockNode();
        }

        while (nextNode != nullptr)
        {
            while (nextNode != nullptr && key == nextNode->getKey())
            {
                currentNode->setNext(nextNode->getNext());
                nextNode->unlockNode();
                delete nextNode;

                nextNode = currentNode->getNext();
                if (nextNode != nullptr)
                {
                    nextNode->lockNode();
                }
            }

            if (nextNode != nullptr)
            {
                currentNode->unlockNode();
                currentNode = nextNode;

                nextNode = currentNode->getNext();
                if (nextNode != nullptr)
                {
                    nextNode->lockNode();
                }
            }
        }
        currentNode->unlockNode();

        if (key == head->getKey())
        {
            if (nullptr == head->getNext())
            {
                delete head;
                head = nullptr;
            }
            else
            {
                nextNode = head->getNext();
                delete head;
                head = nextNode;
            }
        }

        listLock.unlock();
    }

    void deleteAllWithValue(V value)
    {
        listLock.lock();
        LockableNode<K, V>* currentNode = nullptr;
        LockableNode<K, V>* nextNode = nullptr;

        if (nullptr == head)
        {
            listLock.unlock();
            return;
        }

        currentNode = head;
        currentNode->lockNode();
        nextNode = currentNode->getNext();
        if (nextNode != nullptr)
        {
            nextNode->lockNode();
        }

        while (nextNode != nullptr)
        {
            while (nextNode != nullptr && value == nextNode->getValue())
            {
                currentNode->setNext(nextNode->getNext());
                nextNode->unlockNode();
                delete nextNode;

                nextNode = currentNode->getNext();
                if (nextNode != nullptr)
                {
                    nextNode->lockNode();
                }
            }

            if (nextNode != nullptr)
            {
                currentNode->unlockNode();
                currentNode = nextNode;

                nextNode = currentNode->getNext();
                if (nextNode != nullptr)
                {
                    nextNode->lockNode();
                }
            }
        }
        currentNode->unlockNode();

        if (value == head->getValue())
        {
            if (nullptr == head->getNext())
            {
                delete head;
                head = nullptr;
            }
            else
            {
                nextNode = head->getNext();
                delete head;
                head = nextNode;
            }
        }

        listLock.unlock();
    }

    void incrementOrPushBack(K key, V value)
    {
        LockableNode<K, V>* currentNode = nullptr;
        LockableNode<K, V>* nextNode = nullptr;

        listLock.lock(); // Needed in case of null head

        if (nullptr == head)
        {
            head = new LockableNode<K, V>(key, value);
            listLock.unlock();
            return;
        }

        currentNode = head;
        currentNode->lockNode();

        listLock.unlock(); // Unlock the 'list-entry' lock

        nextNode = currentNode->getNext();
        if (nextNode != nullptr)
        {
            nextNode->lockNode();
        }

        while (key != currentNode->getKey() && nextNode != nullptr)
        {
            currentNode->unlockNode();
            currentNode = nextNode;

            nextNode = currentNode->getNext();
            if (nextNode != nullptr)
            {
                nextNode->lockNode();
            }
        }

        if (nextNode == nullptr && key == currentNode->getKey())
        {
            V newNodeValue = value + currentNode->getValue();
            currentNode->setValue(newNodeValue);
            //std::cout << "Node incremented last ==> Key: { " << currentNode->getKey() << " }; Value: { " << currentNode->getValue() << " };" << std::endl;

        }
        else if (nullptr == nextNode)
        {
            currentNode->setNext(new LockableNode<K, V>(key, value));
            //std::cout << "Node add ==> Key: { " << currentNode->getKey() << " }; Value: { " << currentNode->getValue() << " }; NextKey: { " << currentNode->getNext()->getKey() << " }; NextValue: { " << currentNode->getNext()->getValue() << " }" << std::endl;

        }
        else
        {
            V newNodeValue = value + currentNode->getValue();
            currentNode->setValue(newNodeValue);

            //std::cout << "Node increment ==> Key: { " << currentNode->getKey() << " }; Value: { " << currentNode->getValue() << " }; NextKey: { " << nextNode->getKey() <<" }; NextValue: { " << nextNode->getValue() << " }" << std::endl;

            nextNode->unlockNode();
        }
        currentNode->unlockNode();
    }

    void incrementOrPushBack_ListLock(K key, V value)
    {
        listLock.lock();

        LockableNode<K, V>* currentNode = nullptr;
        LockableNode<K, V>* nextNode = nullptr;

        if (nullptr == head)
        {
            head = new LockableNode<K, V>(key, value);
            listLock.unlock();
            return;
        }

        currentNode = head;
        while (key != currentNode->getKey() && nullptr != currentNode->getNext())
        {
            currentNode = currentNode->getNext();
        }

        if (key == currentNode->getKey())
        {
            V newNodeValue = value + currentNode->getValue();
            currentNode->setValue(newNodeValue);
        }
        else if (nullptr == currentNode->getNext())
        {
            currentNode->setNext(new LockableNode<K, V>(key, value));
        }

        listLock.unlock();
    }
};

#endif //CATALOG_LINKEDLIST_H
