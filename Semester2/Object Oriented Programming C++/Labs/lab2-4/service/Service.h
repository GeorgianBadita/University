//
// Created by geo on 3/16/18.
//

#ifndef LAB2_GENERIC_DYN_SERVICE_H
#define LAB2_GENERIC_DYN_SERVICE_H

#include "../repository/Repository.h"
#include "../utils/undo.h"

typedef struct{
    TransRepo* repo;
    Undo* undoL;
}Service;


/*
 * Function that creates a service
 * :param TransRepo: the repository associated with the service
 * :return: a new service
 */
Service* createService(TransRepo*, Undo*);

/*
 * Function that destroys a service
 * :param Service: the service to destroy
 * :post: the memory held by the service will be freed
 */
void destroyService(Service*);

/*
 * Function that adds a new Transaction
 * :param Service: the Service which manages the operation
 * :param Transaction: the transaction to be added
 * :post: the transaction will be added into the repository
 * :return: 1 if we could add the transaction, 0 otherwise
 */
int addTrService(Service*, int, int, char*);

/*
 * Function that searches for a Transaction
 * :param Service: The service to look into
 * :param Transaction: the transaction to search for
 * :return: the position where we found the element, -1 otherwise
 */
int searchTrService(Service* srv, int day, int sum, char* type);

/*
 * Function that deletes a given transaction
 * :param Service: the Service to delete element from
 * :param Transaction: the transaction to be deleted
 * return: 1 if we could delete the transaction, 0 otherwise
 */
int deleteTrService(Service* srv, int day, int sum, char* type);

/*
* Function that updates a transaction in the Service
* :param Service: the service where we have to change an element
* :param Transaction: the old transaction
* :param Transaction: the new transaction
* :post: the old transaction will be replaced with the new one
* :return: 1 if we could modify the transaction, 0 otherwise
*/
int modifyTrService(Service* srv, int day1, int sum1, char* type1, int day2, int sum2, char* type2);

/*
 * Function that filters all Transaction from the service by type
 * :param Service: the Service where to filter from
 * :param int: the type to filter by 1 for intrare, 0 for iesire
 * :return: a Dynamic Vector containing all the Transaction that have asked type
 */
DynamicVector* filterByType(Service*, int);

/*
 * Function that filters all Transaction from the service by sums bigger than a introduced sum
 * :param Service: the service where to filter
 * :param int: the sum to compare
 * :return: a Dynamic Vector containing all the Transaction that have sum > than asked sum
 */
DynamicVector* filterBySumH(Service*, int);

/*
 * Function that filters all Transaction from the service by sums lower than a introduced sum
 * :param Service: the service where to fileter
 * :param int: the sum to compare
 * :return: a Dynamic Vector containing all the Transaction that have sum < than asked sum
 */
DynamicVector* filterBySumL(Service*, int);


/*
 * Function that sorts the list of transactions by sum ascending or descending
 * :param Service: the service where to sort
 * :param int: integer number that tells to sort ascending or descending 1 for ascending 0 for descending
 */
DynamicVector* sortBySum(Service*, int);

/*
 * Function that sorts the list of transactions by day ascending or descending
 * :param Service: the service where to sort
 * :param int: integer number that tells to sort ascending or descending 1 for ascending 0 for descending
 */
DynamicVector* sortByDay(Service*, int);

/*
 * Function that prints all transactions from the Service
 * :param DynamicVector: the vector to print
 * :post: all Transactions will be printed
 */
void printAllServ(DynamicVector*);

/*
 * Function that destroys all Transactions from the service
 * :param Service: the repository we want to delete
 * :post: All transactions will be deleted
 */
void destroyAllSrv(Service*);

/*
 * Function that adds a new Service to the undo list
 * :param Undo: the undo list we want to update
 * :param Service: the service we want to add
 */
void addRepo(Undo* last, DynamicVector* lst);

/*
 * Function that pops the last service from the list
 * :param Undo: the unde we want to pop its head
 */
DynamicVector* popServ(Undo* lst);

/*
 *
 */
void testCreateService();

/*
 *
 */
void testAddTrService();

/*
 *
 */
void testDeleteTrService();

/*
 *
 */
void testSearchService();

/*
 *
 */
void testModifyTrService();

/*
 *
 */
void testFilterByType();

/*
 *
 */
void testFilterbySum();

/*
 *
 */
void testSortDay();

/*
 *
 */
void testSortSum();

/*
 *
 */
void testPopServ();

/*
 *
 */
void testAddRepo();
#endif //LAB2_GENERIC_DYN_SERVICE_H
