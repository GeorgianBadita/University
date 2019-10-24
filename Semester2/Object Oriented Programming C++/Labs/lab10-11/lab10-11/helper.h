//
// Created by geo on 4/14/18.
//

#ifndef LAB6_HELPER_H
#define LAB6_HELPER_H

#include <string>
#include <cstring>
#include <vector>
#include <sstream>

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

/*
 * Function which splits a string in substrings using a delimiter
 * :param str: the string to be split
 * :param delim: char, the caracter to spliy by
 */
std::vector<std::string> split_delim(std::string str, char delim);

#endif //LAB6_HELPER_H
