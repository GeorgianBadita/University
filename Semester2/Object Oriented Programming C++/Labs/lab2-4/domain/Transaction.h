//
// Created by geo on 3/16/18.
//

#ifndef LAB2_GENERIC_DYN_TRANSACTION_H
#define LAB2_GENERIC_DYN_TRANSACTION_H

typedef struct {
    int day;
    int sum;
    char* type;

}Transaction;

/*
 * Function that will create a transaction
 * :param int: the day of transaction
 * :param sum: the sum of the transaction
 * :param char*: the type of the operation
 */
Transaction* createTransaction(int, int, char*);

/*
 * Function that destroys a transaction
 * :param: a transaction
 * :post: frees the memory occupied by type
 */
void destroyTransaction(Transaction*);

/*
 * Getter method
 */
int getDay(Transaction *);

/*
 * Getter method
 */
int getSum(Transaction *);

/*
 * Getter method
 */
char* getType(Transaction *);

/*
 * Function that compares 2 Transactions by day
 * :param Transaction: first transaction
 * :param Transaction: second transaction
 * return 0 if A < B, 1 if A > B and -1 if A = B
 */
int cmpDay(Transaction* A, Transaction *B);
/*
 * Function that compares 2 Transactions by sum
 * :param Transaction: first transaction
 * :param Transaction: second transaction
 * return 0 if A < B, 1 if A > B and -1 if A = B
 */
int cmpSum(Transaction* A, Transaction *B);

/*
 * Function that tells if two Transactions are are equals
 * :param Transaction: first transaction
 * :param Transaction second transaction
 * :return: 1 if the transactions are equal 0 otherwise
 */
int eq(Transaction* A, Transaction* B);

/*
 * Function that copies a Transaction
 * :param Transaction: the transaction to be copied
 * :return: the copied transaction
 */
Transaction* copyTrans(Transaction*);

/*
 *
 */
void testTransaction();

/*
 *
 */
void testCmps();



#endif //LAB2_GENERIC_DYN_TRANSACTION_H
