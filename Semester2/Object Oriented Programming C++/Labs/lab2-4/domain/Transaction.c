//
// Created by geo on 3/16/18.
//

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Transaction.h"
#include "strings.h"
#define LENTYPE 10

/*
* Function that will create a transaction
* :param int: the day of transaction
* :param sum: the sum of the transaction
* :param char*: the type of the operation
*/
Transaction* createTransaction(int day, int sum, char* type){
    Transaction* tr = (Transaction*)malloc(sizeof(Transaction));
    tr->day = day;
    tr->sum = sum;
    tr->type = (char*)malloc(LENTYPE*sizeof(char));
    strcpy(tr->type, type);
    return tr;
}

/*
 * Function that destroys a transaction
 * :param: a transaction
 * :post: frees the memory occupied by type
 */
void destroyTransaction(Transaction* tr){
    free(tr->type);
    free(tr);
}

/*
 * Getter method
 */
int getDay(Transaction *tr){
    return tr->day;
}

/*
 * Getter method
 */
int getSum(Transaction *tr){
    return tr->sum;
}

/*
 * Getter method
 */
char* getType(Transaction *tr){
    return tr->type;
}

/*
 * Function that compares 2 Transactions by day
 * :param Transaction: first transaction
 * :param Transaction: second transaction
 * return 0 if A < B, 1 if A > B and -1 if A = B
 */
int cmpDay(Transaction* A, Transaction *B){
    if(A->day < B->day){
        return 0;
    }
    else if(A->day > B->day){
        return  1;
    }
    return -1;
}

/*
 * Function that compares 2 Transactions by sum
 * :param Transaction: first transaction
 * :param Transaction: second transaction
 * return 0 if A < B, 1 if A > B and -1 if A = B
 */
int cmpSum(Transaction* A, Transaction *B){
    if(A->sum < B->sum){
        return 0;
    }
    else if(A->sum > B->sum){
        return  1;
    }
    return -1;
}

/*
 * Function that tells if two Transactions are are equals
 * :param Transaction: first transaction
 * :param Transaction second transaction
 * :return: 1 if the transactions are equal 0 otherwise
 */
int eq(Transaction* A, Transaction* B){
    return A->sum == B->sum && A->day == B->day && strcmp(A->type, B->type) == 0;
}

/*
 * Function that copies a Transaction
 * :param Transaction: the transaction to be copied
 * :return: the copied transaction
 */
Transaction* copyTrans(Transaction* tr){
    Transaction* newTr = createTransaction(tr->day, tr->sum, tr->type);
    return newTr;
}

/*
 * Function that tests the transaction methods
 * :post: Program will stop the execution if test is not passed
 */
void testTransaction(){
    Transaction* tr = createTransaction(10, 20, "iesire");
    assert(getDay(tr) == 10);
    assert(getSum(tr) == 20);
    char* type = getType(tr);
    assert(strcmp(type, "iesire") == 0);
    destroyTransaction(tr);
}

/*
 *
 */
void testCmps(){
    Transaction *tr1 = createTransaction(10, 20, "iesire");
    Transaction *tr2 = createTransaction(9, 25, "intrare");
    Transaction *tr3 = createTransaction(10, 20, "iesire");
    assert(cmpDay(tr1, tr2) == 1);
    assert(cmpDay(tr2, tr1) == 0);
    assert(cmpDay(tr1, tr3) == -1);
    assert(cmpSum(tr1, tr2) == 0);
    assert(cmpSum(tr2, tr1) == 1);
    assert(cmpSum(tr1, tr3) == -1);
    assert(eq(tr1, tr3) == 1);
    assert(eq(tr1, tr2) == 0);
    destroyTransaction(tr1);
    destroyTransaction(tr2);
    destroyTransaction(tr3);
}