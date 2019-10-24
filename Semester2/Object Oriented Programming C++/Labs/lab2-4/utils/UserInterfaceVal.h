//
// Created by geo on 3/16/18.
//

#ifndef LAB2_GENERIC_DYN_USERINTERFACEVAL_H
#define LAB2_GENERIC_DYN_USERINTERFACEVAL_H

//Methods for validating and reading input given by user
/*
 * Function that that reads a string from console input
 * :param string: string where will store the input
 * :size: maximum length of input
 * :post: the parameter string will contain the read input
 */
void readString (char* string, int size);

/*
 * Function that checks if a string is made only from digits
 * :param string: the string to check
 * :return: 1 if the string is a number, 0 otherwise
 */
int validateInteger(char* string);

/*
 * Function that extracts the number from a string
 * :return: the number represented by the string
 * :param n: where we'll store the number
 * :param string: the string where we'll get the number from
 */
int getInteger(char* string);

/*
* Function that validates the day
* :param int: the day to be validated
* :return:..
*/
int validateDay(int);

/*
 * Function that validates the sum
 * :param int: the sum to be validated
 * :return:..
 */
int validateSum(int);

/*
 * Function that validates the type
 * :param char*: the type to be validated
 * :return:..
 */
int validateType(char*);

/*
 *
 */
void testValidateDay();

/*
 *
 */
void testValidateSum();

/*
 *
 */
void testValidateType();

/*
 *
 */
void testValidateInteger();

/*
 *
 */
void testGetInteger();

#endif //LAB2_GENERIC_DYN_USERINTERFACEVAL_H
