//
// Created by geo on 4/14/18.
//

#include "validator.h"

/*
 * Function which checks if a movie is valid
 * :param mv: the movie to be checked
 * :post: raises ValidatorException if the movie is not correct
 */
void MovieValidator::validate(const Movie& mv){
    vector<std::string> errs;
    auto title = mv.get_title();
    auto genre = mv.get_genre();
    auto year = mv.get_year();
    auto actor = mv.get_main_actor();

    if(title.empty()){
        errs.emplace_back("The title can't be empty!\n");
    }
    if(genre.empty()){
        errs.emplace_back("The genre can't be empty!\n");
    }
    if(year <= 1800){

        errs.emplace_back("The year must be a positive integer > 1800\n");
    }
    if(actor.empty()){
        errs.emplace_back("The main actor field can't be empty!\n");
    }
    if(!errs.empty()){
        throw ValidatorException(errs);
    }
}
