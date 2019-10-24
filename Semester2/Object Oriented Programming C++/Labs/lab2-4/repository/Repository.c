//
// Created by geo on 3/16/18.
//

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "Repository.h"
#include "../utils/DynamicVector.h"


/*
 * Function that creates a repository
 * :param int: initial number of elements
 * :param int *(cmp1): compare function for first criteria
 * :param int *(cmp2): compare function for second criteria
 * :return: a new Repository
 * :post: a new Repository will be created
 */
TransRepo* createRepository(int size){
    TransRepo* repo = (TransRepo*)malloc(sizeof(TransRepo));
    repo->transactions = createDynamicVector(size, cmpDay, cmpSum, eq, destroyTransaction);
    return repo;
}

/*
 * Function that destroys a repository
 * :param TransRepo: repository to be deleted
 * :post: memory occupied by the repository will be freed
 */
void destroyRepository(TransRepo* repo){
    destroyVector(repo->transactions);
    free(repo);
}

/*
 * Function that adds an element into the repository
 * :param TransRepo: the repository
 * :param Transaction: the transaction to be added
 * :post: the transaction will be added to the repository
 * :return: 1 if the Transaction is unique 0 otherwise
 */
int appendTrans(TransRepo* repo, Transaction* tr){
    int pos = searchRepository(repo, tr);
    if(pos < 0){
        addElement(repo->transactions, tr);
        return 1;
    }
    return 0;
}


/*
 * Function that searches an element into the repository
 * :param TransRepo: the repository to search into
 * :param Transaction: the transaction to search for
 * :returun: the position where we found the element, -1 otherwise
 */
int searchRepository(TransRepo* repo, Transaction* tr){
    int pos = searchElement(repo->transactions, tr);
    return pos;
}

/*
 * Function that destroys all Transactions from the repository
 * :param TransRepo: the repository we want to delete
 * :post: All transactions will be deleted
 */
void destroyAll(TransRepo* repo){
    int i = 0;
    for(; i < repo->transactions->num; i++){
        if(repo->transactions->elems[i] != NULL) {
            destroyTransaction(repo->transactions->elems[i]);
            repo->transactions->elems[i] = NULL;
        }

    }
}

/*
 * Function that deletes a given transaction
 * :param TransRepo: repository to delete element from
 * :param Transaction: the transaction to be deleted
 * return: the transaction if we could delete it NULL otherwise
 */
Transaction* deleteTransaction(TransRepo* repo, Transaction* tr){
    int pos = searchRepository(repo, tr);
    if(pos < 0){
        return 0;
    }
    else{
        Transaction *tr1 = repo->transactions->elems[pos];
        deleteElement(repo->transactions, tr);
        return tr1;
    }
}

/*
 * Function that updates a transaction in the repository
 * :param TransRepo: the repository where we have to change an element
 * :param Transaction: the old transaction
 * :param Transaction: the new transaction
 * :post: the old transaction will be replaced with the new one
 * :return: The modifyied transaction, NULL otherwise
 */
Transaction* modifyTransaction(TransRepo* repo, Transaction* tr, Transaction* newTr){
    int pos = searchRepository(repo, tr);
    if(pos < 0) {
        return 0;
    }
    else{
        Transaction* tr1 = repo->transactions->elems[pos];
        modifyElement(repo->transactions, tr, newTr);
        return tr1;

    }
}

/*
 * Function that gets All the elements of a repository
 * :param TransRepo: the repository to be copied
 * :return: a DynamicVector containg all transaction from the repository
 */
DynamicVector getAll(TransRepo* repo){
    return copy(repo->transactions);
}

/*
 * Function that prints all Transactions from the repository
 * :param DynamicVector: the vector to print
 * :return: none
 */
void printAll(DynamicVector* vect){
    int i = 0;
    DynamicVector all = copy(vect);
    for(; i < all.num; i++){
        Transaction* tr = copyTrans(all.elems[i]);
        printf("%d\t Ziua: %d\t Suma: %d\t Tipul: %s\n", i+1, tr->day, tr->sum, tr->type);
        destroyTransaction(tr);
    }
    destroyElems(&all);
}


/*
 *
 */
void testGetAll(){
    TransRepo* repo = createRepository(5);
    Transaction* tr = createTransaction(1, 1, "iesire");
    Transaction* tr1 = createTransaction(12, 31, "intrare");
    appendTrans(repo, tr);
    appendTrans(repo, tr1);
    DynamicVector all = getAll(repo);
    assert(all.num == 2);
    destroyElems(&all);
    destroyTransaction(tr);
    destroyTransaction(tr1);
    destroyRepository(repo);
}

/*
 *
 */
void testCreateRepo(){
    TransRepo* repo = createRepository(5);
    assert(repo->transactions->maxCap == 5);
    assert(repo->transactions->num == 0);
    destroyRepository(repo);
}


/*
 *
 */
void testAppend(){
    TransRepo* repo = createRepository(5);
    Transaction* tr = createTransaction(1, 1, "iesire");
    Transaction* tr1 = createTransaction(12, 31, "intrare");
    appendTrans(repo, tr);
    appendTrans(repo, tr1);
    assert(repo->transactions->num == 2);
    assert(repo->transactions->maxCap == 5);
    assert(eq(repo->transactions->elems[0], tr) == 1);
    assert(eq(repo->transactions->elems[1], tr1) == 1);
    destroyTransaction(tr);
    destroyTransaction(tr1);
    destroyRepository(repo);

}

/*
 *
 */
void testModifyTrans(){
    TransRepo* repo = createRepository(5);
    Transaction* tr = createTransaction(1, 1, "iesire");
    Transaction* tr1 = createTransaction(12, 31, "intrare");
    Transaction* tr2 = createTransaction(10, 20, "intrare");
    appendTrans(repo, tr);
    appendTrans(repo, tr1);
    int res = modifyTransaction(repo, tr, tr2);
    assert(repo->transactions->cmpEq(repo->transactions->elems[0], tr2) == 1);
    res = modifyTransaction(repo, tr, tr1);
    assert(res == 0);
    destroyRepository(repo);
    destroyTransaction(tr1);
    destroyTransaction(tr2);
    destroyTransaction(tr);

}

/*
 *
 */
void testDeleteTrans(){
    TransRepo* repo = createRepository(5);
    Transaction* tr = createTransaction(1, 1, "iesire");
    Transaction* tr1 = createTransaction(12, 31, "intrare");
    Transaction* tr2 = createTransaction(-1, -1, "string");
    appendTrans(repo, tr);
    appendTrans(repo, tr1);
    int del = deleteTransaction(repo, tr);
    assert(eq(repo->transactions->elems[0], tr1) == 1);
    del = deleteTransaction(repo, tr2);
    assert(del == 0);
    destroyTransaction(tr2);
    destroyTransaction(tr1);
    destroyTransaction(tr);
    destroyRepository(repo);
}

/*
 *
 */
void testSearchRepo(){
    TransRepo* repo = createRepository(5);
    Transaction* tr = createTransaction(1, 1, "iesire");
    Transaction* tr1 = createTransaction(12, 31, "intrare");
    Transaction* tr2 = createTransaction(-1, -1, "string");
    appendTrans(repo, tr);
    appendTrans(repo, tr1);
    int res = searchRepository(repo, tr);
    assert(res == 0);
    res = searchRepository(repo, tr1);
    assert(res == 1);
    res = searchRepository(repo, tr2);
    assert(res == -1);
    destroyTransaction(tr);
    destroyTransaction(tr1);
    destroyTransaction(tr2);
    destroyRepository(repo);
}

