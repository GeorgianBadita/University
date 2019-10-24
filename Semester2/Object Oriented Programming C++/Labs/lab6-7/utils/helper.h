//
// Created by geo on 4/14/18.
//

#ifndef LAB6_HELPER_H
#define LAB6_HELPER_H

#include <string>

/*
 * Function that reads until an integer is given
 * :param prompt: prompt to the user
 */
int read_int(const std::string& prompt);

/*
 * Function that checks if a string is made only from integers
 * :param to_check: the sting to be checked
 */
bool is_integer(const std::string& to_check);

/*
 * Function that makes a positive integer from a string
 * :param str: the string to make integer from
 */
int make_integer(const std::string& str);

#endif //LAB6_HELPER_H
