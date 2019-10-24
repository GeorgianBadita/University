//
// Created by geo on 3/16/18.
//

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Service.h"
#include "../utils/undo.h"
#include "../repository/Repository.h"
#include "../utils/DynamicVector.h"


/*
 * Function that creates a service
 * :param TransRepo: the repository associated with the service
 * :return: a new service
 */
Service* createService(TransRepo* repo, Undo* undoL){
    Service* srv = (Service*)malloc(sizeof(Service));
    srv->repo = repo;
    srv->undoL = undoL;
    return srv;
}

/*
 * Function that destroys a service
 * :param Service: the service to destroy
 * :post: the memory held by the service will be freed
 */
void destroyService(Service* srv){
    destroyRepository(srv->repo);
    destroyUndoList(srv->undoL);
    free(srv);
}

/*
 * Function that adds a new Transaction
 * :param Service: the Service which manages the operation
 * :param Transaction: the transaction to be added
 * :post: the transaction will be added into the repository
 * :return: 1 if we could add the transaction, 0 otherwise
 */
int addTrService(Service* srv, int day, int sum, char* type){
    Transaction* tr = createTransaction(day, sum, type);
    addRepo(srv->undoL, srv->repo->transactions);
    return appendTrans(srv->repo, tr);
}

/*
 * Function that searches for a Transaction
 * :param Service: The service to look into
 * :param Transaction: the transaction to search for
 * :return: the position where we found the element, -1 otherwise
 */
int searchTrService(Service* srv, int day, int sum, char* type) {
    Transaction* tr = createTransaction(day, sum, type);
    int val = searchRepository(srv->repo, tr);
    destroyTransaction(tr);
    return val;
}

/*
 * Function that deletes a given transaction
 * :param Service: the Service to delete element from
 * :param Transaction: the transaction to be deleted
 * return: 1 if we could delete the transaction, 0 otherwise
 */
int deleteTrService(Service* srv, int day, int sum, char* type){
    Transaction* tr = createTransaction(day, sum, type);
    addRepo(srv->undoL, srv->repo->transactions);
    Transaction* tr1 =  deleteTransaction(srv->repo, tr);
    destroyTransaction(tr);
    if(tr1 == 0){
        return 0;
    }
    else{
        addElement(srv->undoL->toDelete, tr1);
        return 1;
    }
}

/*
 * Function that adds a new Service to the undo list
 * :param Undo: the undo list we want to update
 * :param Service: the service we want to add
 */
void addRepo(Undo* last, DynamicVector* lst){
    addElement(last->undoLst, copyDyn(lst));
}

/*
 * Function that pops the last service from the list
 * :param Undo: the unde we want to pop its head
 * :return: the Service
 */
DynamicVector* popServ(Undo* lst){
    DynamicVector* ret = (DynamicVector*)popVector(lst->undoLst);
    return ret;
}

/*
* Function that updates a transaction in the Service
* :param Service: the service where we have to change an element
* :param Transaction: the old transaction
* :param Transaction: the new transaction
* :post: the old transaction will be replaced with the new one
* :return: 1 if we could modify the transaction, 0 otherwise
*/
int modifyTrService(Service* srv, int day1, int sum1, char* type1, int day2, int sum2, char* type2){
    Transaction* tr = createTransaction(day1, sum1, type1);
    Transaction* newTr = createTransaction(day2, sum2, type2);
    addRepo(srv->undoL, srv->repo->transactions);
    Transaction* tr2 =  modifyTransaction(srv->repo, tr, newTr);
    destroyTransaction(tr);
    if(tr2 == 0){
        destroyTransaction(newTr);
        return 0;
    }
    else{
        addElement(srv->undoL->toDelete, tr2);
        //destroyTransaction(tr2);
        return 1;
    }
}

/*
 * Function that filters all Transaction from the service by type
 * :param Service: the Service where to filter from
 * :param int: the type to filter by 1 for intrare, 0 for iesire
 * :return: a Dynamic Vector containing all the Transaction that have asked type
 */

DynamicVector* filterByType(Service* srv, int type){
    DynamicVector* toFilter = copyDyn(srv->repo->transactions);
    int i = 0;
    char* searchType = (char*)malloc(10* sizeof(char));
    if(type == 1){
        strcpy(searchType, "intrare");
    }
    else if(type == 0){
        strcpy(searchType, "iesire");
    }
    for(; i <toFilter->num; i++){
        Transaction* tr = copyTrans(toFilter->elems[i]);
        if(strcmp(getType(tr), searchType) != 0){
            deleteElement(toFilter, toFilter->elems[i]);
            i --;
        }
        destroyTransaction(tr);
    }
    free(searchType);
    return toFilter;
}

/*
 * Function that filters all Transaction from the service by sums bigger than a introduced sum
 * :param Service: the service where to filter
 * :param int: the sum to compare
 * :return: a Dynamic Vector containing all the Transaction that have sum > than asked sum
 */
DynamicVector* filterBySumH(Service* srv, int sum){
    DynamicVector* toFilter = copyDyn(srv->repo->transactions);
    int i = 0;
    for(; i <toFilter->num; i++){
        Transaction* tr = copyTrans(toFilter->elems[i]);
        if(getSum(tr) <= sum){
            deleteElement(toFilter, toFilter->elems[i]);
            i --;
        }
        destroyTransaction(tr);
    }
    return toFilter;

}

/*
 * Function that filters all Transaction from the service by sums lower than a introduced sum
 * :param Service: the service where to fileter
 * :param int: the sum to compare
 * :return: a Dynamic Vector containing all the Transaction that have sum < than asked sum
 */
DynamicVector* filterBySumL(Service* srv, int sum){
    DynamicVector* toFilter = copyDyn(srv->repo->transactions);
    int i = 0;
    for(; i <toFilter->num; i++){
        Transaction* tr = copyTrans(toFilter->elems[i]);
        if(getSum(tr) >= sum){
            deleteElement(toFilter, toFilter->elems[i]);
            i --;
        }
        destroyTransaction(tr);
    }
    return toFilter;
}


/*
 * Function that sorts the list of transactions by sum ascending or descending
 * :param Service: the service where to sort
 * :param int: integer number that tells to sort ascending or descending 1 for ascending 0 for descending
 */
DynamicVector* sortBySum(Service* srv, int reverse){
    srv->repo->transactions->cmpCrit1 = srv->repo->transactions->cmpCrit2;
    return sortDynamic(srv->repo->transactions, reverse);
}

/*
 * Function that sorts the list of transactions by day ascending or descending
 * :param Service: the service where to sort
 * :param int: integer number that tells to sort ascending or descending 1 for ascending 0 for descending
 */
DynamicVector* sortByDay(Service* srv, int reverse){
    return sortDynamic(srv->repo->transactions, reverse);
}

/*
 * Function that prints all transactions from the Service
 * :param DynamicVector: the vector to print
 * :post: all Transactions will be printed
 */
void printAllServ(DynamicVector* vect){
    printAll(vect);
}
/*
 * Function that destroys all Transactions from the service
 * :param Service: the repository we want to delete
 * :post: All transactions will be deleted
 */
void destroyAllSrv(Service* srv){
    destroyAll(srv->repo);
}


/*
 *
 */
void testCreateService(){
    TransRepo* repo = createRepository(5);
    Undo* undo = createUndo();
    Service* srv = createService(repo, undo);
    assert(srv->repo == repo);
    assert(srv->repo->transactions->maxCap == 5);
    destroyService(srv);
}

/*
 *
 */
void testAddTrService(){
    TransRepo* repo = createRepository(5);
    Undo* undo = createUndo();
    Service* srv = createService(repo, undo);
    Transaction* tr = createTransaction(1, 1, "intrare");
    addTrService(srv, 1, 1, "intrare");
    assert(eq(srv->repo->transactions->elems[0], tr) == 1);
    destroyVector(undo->undoLst->elems[0]);
    destroyAllSrv(srv);
    destroyService(srv);
    destroyTransaction(tr);
}

/*
 *
 */
void testDeleteTrService(){
    TransRepo* repo = createRepository(5);
    Undo* undo = createUndo();
    Service* srv = createService(repo, undo);
    Transaction* tr = createTransaction(1, 1, "intrare");
    addTrService(srv, 1, 1, "intrare");
    int del = deleteTrService(srv, 1, 1, "intrare");
    assert(srv->repo->transactions->num == 0);
    assert(del == 1);
    del = deleteTrService(srv, 1, 1, "intrare");
    assert(del == 0);
    destroyVector(undo->undoLst->elems[0]);
    destroyVector(undo->undoLst->elems[1]);
    destroyVector(undo->undoLst->elems[2]);
    destroyTransaction(undo->toDelete->elems[0]);
    destroyAllSrv(srv);
    destroyService(srv);
    destroyTransaction(tr);
}

/*
 *
 */
void testSearchService(){
    TransRepo* repo = createRepository(5);
    Undo* undo = createUndo();
    Service* srv = createService(repo, undo);
    Transaction* tr = createTransaction(1, 12, "intrare");
    Transaction* tr1 = createTransaction(1, 123, "iesire");
    Transaction* tr2 = createTransaction(2, 11, "iesire");
    addTrService(srv, 1, 12, "intrare");
    addTrService(srv, 1, 123, "iesire");
    int search = searchTrService(srv, 1, 12, "intrare");
    assert(search == 0);
    search = searchTrService(srv, 1, 123, "iesire");
    assert(search == 1);
    search = searchTrService(srv, 2, 11, "iesire");
    assert(search == -1);
    destroyVector(undo->undoLst->elems[0]);
    destroyVector(undo->undoLst->elems[1]);
    destroyAllSrv(srv);
    destroyTransaction(tr);
    destroyTransaction(tr1);
    destroyTransaction(tr2);
    destroyService(srv);
}

/*
 *
 */
void testModifyTrService(){
    TransRepo* repo = createRepository(5);
    Undo* undo = createUndo();
    Service* srv = createService(repo, undo);
    Transaction* tr = createTransaction(1, 12, "intrare");
    Transaction* tr1 = createTransaction(1, 123, "iesire");
    Transaction* tr2 = createTransaction(2, 11, "iesire");
    addTrService(srv, 1, 12, "intrare");
    addTrService(srv, 1, 123, "iesire");
    int modif = modifyTrService(srv, 1, 123, "iesire", 2, 11, "iesire");
    assert(modif == 1);
    assert(eq(srv->repo->transactions->elems[1], tr2) == 1);
    modif = modifyTrService(srv, 1, 121, "intrare", 2, 11, "iesire");
    assert(modif == 0);
    destroyVector(undo->undoLst->elems[0]);
    destroyVector(undo->undoLst->elems[1]);
    destroyVector(undo->undoLst->elems[2]);
    destroyVector(undo->undoLst->elems[3]);
    destroyTransaction(undo->toDelete->elems[0]);
    destroyAllSrv(srv);
    destroyTransaction(tr);
    destroyTransaction(tr1);
    destroyTransaction(tr2);
    destroyService(srv);
}


/*
 *
 */
void testFilterByType(){
    TransRepo* repo = createRepository(5);
    Undo* undo = createUndo();
    Service* srv = createService(repo, undo);
    Transaction* tr = createTransaction(1, 12, "intrare");
    Transaction* tr1 = createTransaction(1, 123, "iesire");
    Transaction* tr2 = createTransaction(2, 11, "iesire");
    addTrService(srv, 1, 12, "intrare");
    addTrService(srv, 1, 123, "iesire");
    addTrService(srv, 2, 11, "iesire");
    DynamicVector* filter1 = filterByType(srv, 1);
    assert(filter1->num == 1);
    assert(eq(filter1->elems[0], tr) == 1);
    assert(filter1->num != repo->transactions->num);
    destroyVector(filter1);
    DynamicVector* filter2 = filterByType(srv, 0);
    assert(filter2->num == 2);
    assert(eq(filter2->elems[0], tr1) == 1);
    assert(eq(filter2->elems[1], tr2) == 1);
    destroyTransaction(undo->undoLst->elems[0]);
    destroyTransaction(undo->undoLst->elems[1]);
    destroyTransaction(undo->undoLst->elems[2]);
    destroyAllSrv(srv);
    destroyTransaction(tr);
    destroyTransaction(tr1);
    destroyTransaction(tr2);
    destroyService(srv);
    destroyVector(filter2);

}

/*
 *
 */
void testFilterbySum(){
    TransRepo* repo = createRepository(5);
    Undo* undo = createUndo();
    Service* srv = createService(repo, undo);
    Transaction* tr = createTransaction(1, 12, "intrare");
    Transaction* tr1 = createTransaction(1, 123, "iesire");
    Transaction* tr2 = createTransaction(2, 11, "iesire");
    addTrService(srv, 1, 12, "intrare");
    addTrService(srv, 1, 123, "iesire");
    addTrService(srv, 2, 11, "iesire");
    DynamicVector* filter = filterBySumH(srv, 11);
    assert(filter->num == 2);
    assert(eq(filter->elems[0], tr) == 1);
    assert(eq(filter->elems[1], tr1) == 1);
    DynamicVector* filter1 = filterBySumL(srv, 100);
    assert(filter1->num == 2);
    assert(eq(filter1->elems[0], tr) == 1);
    assert(eq(filter1->elems[1], tr2) == 1);
    destroyTransaction(undo->undoLst->elems[0]);
    destroyTransaction(undo->undoLst->elems[1]);
    destroyTransaction(undo->undoLst->elems[2]);
    destroyTransaction(tr);
    destroyTransaction(tr1);
    destroyTransaction(tr2);
    destroyAllSrv(srv);
    destroyService(srv);
    destroyVector(filter);
    destroyVector(filter1);
}

/*
 *
 */
void testSortDay(){
    TransRepo* repo = createRepository(5);
    Undo* undo = createUndo();
    Service* srv = createService(repo, undo);
    Transaction* tr = createTransaction(1, 12, "intrare");
    Transaction* tr1 = createTransaction(1, 123, "iesire");
    Transaction* tr2 = createTransaction(2, 11, "iesire");
    addTrService(srv, 1, 12, "intrare");
    addTrService(srv, 1, 123, "iesire");
    addTrService(srv, 2, 11, "iesire");
    DynamicVector* sortAsc = sortByDay(srv, 1);
    assert(cmpDay(sortAsc->elems[0], sortAsc->elems[1]) == -1 && cmpDay(sortAsc->elems[1], sortAsc->elems[2]) == 0);
    DynamicVector* sortDesc = sortByDay(srv, 0);
    assert(cmpDay(sortDesc->elems[0], sortDesc->elems[1]) == 1 && cmpDay(sortDesc->elems[1], sortDesc->elems[2]) == -1);
    destroyTransaction(undo->undoLst->elems[0]);
    destroyTransaction(undo->undoLst->elems[1]);
    destroyTransaction(undo->undoLst->elems[2]);
    destroyVector(sortAsc);
    destroyVector(sortDesc);
    destroyTransaction(tr);
    destroyTransaction(tr1);
    destroyTransaction(tr2);
    destroyAllSrv(srv);
    destroyService(srv);
}

/*
 *
 */
void testSortSum(){
    TransRepo* repo = createRepository(5);
    Undo* undo = createUndo();
    Service* srv = createService(repo, undo);
    Transaction* tr = createTransaction(1, 12, "intrare");
    Transaction* tr1 = createTransaction(1, 123, "iesire");
    Transaction* tr2 = createTransaction(2, 11, "iesire");
    addTrService(srv, 1, 12, "intrare");
    addTrService(srv, 1, 123, "iesire");
    addTrService(srv, 2, 11, "iesire");
    DynamicVector* sortAsc = sortBySum(srv, 0);
    assert(cmpSum(sortAsc->elems[0], sortAsc->elems[1]) == 1 && cmpSum(sortAsc->elems[1], sortAsc->elems[2]) == 1);
    DynamicVector* sortDesc = sortBySum(srv, 1);
    assert(cmpSum(sortDesc->elems[0], sortDesc->elems[1]) == 0 && cmpSum(sortDesc->elems[1], sortDesc->elems[2]) == 0);
    destroyTransaction(undo->undoLst->elems[0]);
    destroyTransaction(undo->undoLst->elems[1]);
    destroyTransaction(undo->undoLst->elems[2]);
    destroyVector(sortAsc);
    destroyVector(sortDesc);
    destroyTransaction(tr);
    destroyTransaction(tr1);
    destroyTransaction(tr2);
    destroyAllSrv(srv);
    destroyService(srv);
}

/*
 *
 */
void testAddRepo(){
    TransRepo* repo = createRepository(5);
    Undo* undo = createUndo();
    Service* srv = createService(repo, undo);
    addRepo(undo, srv->repo->transactions);
    assert(undo->undoLst->num == 1);
    destroyVector(undo->undoLst->elems[0]);
    destroyAllSrv(srv);
    destroyService(srv);
}

/*
 *
 */
void testPopServ(){
    TransRepo* repo = createRepository(5);
    Undo* undo = createUndo();
    Service* srv = createService(repo, undo);
    addRepo(undo, srv->repo->transactions);
    DynamicVector* lst = popServ(undo);
    assert(undo->undoLst->num == 0);
    destroyVector(lst);
    destroyAllSrv(srv);
    destroyService(srv);
}

