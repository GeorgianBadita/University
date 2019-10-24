//
// Created by geo on 3/16/18.
//

#ifndef LAB2_GENERIC_DYN_REPOSITORY_H
#define LAB2_GENERIC_DYN_REPOSITORY_H

#include "../utils/DynamicVector.h"
#include "../domain/Transaction.h"

#define INIT_VAL 5

typedef struct{
    DynamicVector* transactions;
}TransRepo;

/*
 * Function that creates a repositroy
 * :param int: initial number of elements
 * :return: a new Repository
 * :post: a new Repository will be created
 */
TransRepo* createRepository(int size);

/*
 * Function that destroys a repository
 * :param TransRepo: repository to be deleted
 * :post: memory occupied by the repository will be freed
 */
void destroyRepository(TransRepo*);

/*
 * Function that adds an element into the repository
 * :param TransRepo: the repository
 * :param Transaction: the transaction to be added
 * :post: the transaction will be added to the repository
 * :return: 1 if the Transaction is unique 0 otherwise
 */
int appendTrans(TransRepo*, Transaction*);

/*
 * Function that searches an element into the repository
 * :param TransRepo: the repository to search into
 * :param Transaction: the transaction to search for
 * :return: the position where we found the element, -1 otherwise
 */
int searchRepository(TransRepo*, Transaction*);

/*
 * Function that deletes a given transaction
 * :param TransRepo: repository to delete element from
 * :param Transaction: the transaction to be deleted
 * return: the transaction if we could delete it NULL otherwise
 */
Transaction* deleteTransaction(TransRepo* repo, Transaction* tr);

/*
 * Function that updates a transaction in the repository
 * :param TransRepo: the repository where we have to change an element
 * :param Transaction: the old transaction
 * :param Transaction: the new transaction
 * :post: the old transaction will be replaced with the new one
 * :return: 1 if we could modify the transaction, 0 otherwise
 */
Transaction* modifyTransaction(TransRepo* repo, Transaction* tr, Transaction* newTr);

/*
 * Function that gets All the elements of a repository
 * :param TransRepo: the repository to be copied
 * :return: a DynamicVector containing all transaction from the repository
 */
DynamicVector getAll(TransRepo*);

/*
 * Function that prints all Transactions from the repository
 * :param DynamicVector: the vector to print
 * :return: none
 */
void printAll(DynamicVector*);

/*
 * Function that destroys all Transactions from the repository
 * :param TransRepo: the repository we want to delete
 * :post: All transactions will be deleted
 */
void destroyAll(TransRepo*);

/*
 *
 */
void testGetAll();

/*
 *
 */
void testCreateRepo();

/*
 *
 */
void testAppend();

/*
 *
 */
void testModifyTrans();

/*
 *
 */
void testDeleteTrans();

/*
 *
 */
void testSearchRepo();

#endif //LAB2_GENERIC_DYN_REPOSITORY_H
