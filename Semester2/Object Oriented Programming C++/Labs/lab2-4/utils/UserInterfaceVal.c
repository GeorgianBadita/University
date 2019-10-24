//
// Created by geo on 3/16/18.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "UserInterfaceVal.h"

/*
 * Function that that reads a string from console input
 * :param string: string where will store the input
 * :size: maximum length of input
 * :post: the parameter string will contain the read input
 */
void readString (char* string, int size){
    int n = 0;
    while(n < size) {
        if ((string[n++] = getchar()) == '\n')
            break;
    }
    string[n-1] = '\0';
}

/*
 * Function that checks if a string is made only from digits
 * :param string: the string to check
 * :return: 1 if the string is a number, 0 otherwise
 */
int validateInteger(char* string){
    if(strlen(string) == 0){
        return 0;
    }
    int i = 0;
    for(; i < strlen(string); i++){
        if(!(string[i] >= '0' && string[i] <= '9')){
            return 0;
        }
    }
    return 1;
}

/*
 * Function that extracts the number from a string
 * :param string: the string where we'll get the number from
 * :param n: where we'll store the number
 * :return: the number represented by the string
 */
int getInteger(char* string){
    int n = 0;
    for (int i = 0; i < strlen(string); ++i) {
        n = n * 10 + (string[i] - '0');
    }
    return n;
}

/*
 * Function that validates the day
 * :param int: the day to be validated
 * :return: 1 if the day is correct, 0 otherwise
 */
int validateDay(int day){
    return (day >= 1 && day <= 31);
}

/*
 * Function that validates the sum
 * :param int: the sum to be validated
 * :return: 1 if the sum is correct, 0 otherwise
 */
int validateSum(int sum){
    return sum > 0;
}

/*
 * Function that validates the type
 * :param char*: the type to be validated
 * :return: 1 if the type is correct, 0 otherwise
 */
int validateType(char* type){
    return (strcmp(type, "iesire") == 0 || strcmp(type, "intrare") == 0);
}

/*
 *
 */
void testValidateDay(){
    assert(validateDay(12) == 1);
    assert(validateDay(-12) == 0);
    assert(validateDay(0) == 0);
}

/*
 *
 */
void testValidateSum(){
    assert(validateSum(12) == 1);
    assert(validateSum(-12) == 0);
    assert(validateSum(0) == 0);
}

/*
 *
 */
void testValidateType(){
    assert(validateType("iesire") == 1);
    assert(validateType("intrare") == 1);
    assert(validateType("somestr") == 0);
}

/*
 *
 */
void testValidateInteger(){
    assert(validateInteger("maine merg acasa") == 0);
    assert(validateInteger("123141") == 1);
    assert(validateInteger("") == 0);
}

/*
 *
 */
void testGetInteger(){
    char cmd[10] = "124";
    char cmd1[10] = "1";
    assert(getInteger(cmd) == 124);
    assert(getInteger(cmd1) == 1);
}