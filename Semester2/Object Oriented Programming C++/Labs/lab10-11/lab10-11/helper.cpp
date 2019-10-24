//
// Created by geo on 4/14/18.
//

#include <iostream>
#include "helper.h"
#include <regex>

/*
 * Function that checks if a string is made only from integers
 * :param to_check: the sting to be checked
 */
bool is_integer(const std::string& to_check){
    if(to_check[0] == '0' && to_check.size() != 1){
        return false;
    }
    for(const auto& elem: to_check){
        if(elem < '0' || elem  > '9'){
            return false;
        }
    }
    return true;
}

/*
 * Function that makes a positive integer from a string
 * :param str: the string to make integer from
 */
int make_integer(const std::string& str){
    int num = 0;
    for(const auto& elem: str){
        num = num * 10 + (elem - '0');
    }
    return num;
}

/*
 * Function that reads until an integer is given
 * :param prompt: prompt to the user
 */
int read_int(const std::string& prompt){
    std::string line;
    while(true) {
        std::cout << prompt;
        getline(std::cin, line);
        if(is_integer(line)){
            return make_integer(line);
        }
        std::cout << "\n\nPlease give an integer!\n\n";
    }
}



/*
 * Function which splits a string in substrings using a delimiter
 * :param str: the string to be split
 * :param delim: char, the caracter to spliy by
 */
std::vector<std::string> split_delim(std::string str, char delim){
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream token_stream(str);

    while(std::getline(token_stream, token, delim)){
        token = std::regex_replace(token, std::regex("^ +"), "");
        token = std::regex_replace(token, std::regex(" +$"), "");
        tokens.push_back(token);
    }
    return tokens;

}
