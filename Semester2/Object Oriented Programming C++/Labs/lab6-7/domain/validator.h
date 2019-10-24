//
// Created by geo on 4/14/18.
//

#ifndef LAB6_VALIDATOR_H
#define LAB6_VALIDATOR_H

#include <string>
#include <utility>
#include "movie.h"


/*
 * General exception class
 */
class ValidatorException {
private:
    vector<std::string> exceptions;
public:
    /*
     * Validator class constructor
     * :param exceptions: string - string of errors
     * :return: -
     */
    explicit ValidatorException(vector<std::string> exceptions):exceptions{std::move(exceptions)}{}

    //Getter method
    const vector<std::string> get_errors() const{return this->exceptions;}

};

/*
 * Class which validates a movie entity
 */
class MovieValidator{
public:

    /*
     * Function that checks if a movie is valid
     */
    static void validate(const Movie& mv);
};

#endif //LAB6_VALIDATOR_H
