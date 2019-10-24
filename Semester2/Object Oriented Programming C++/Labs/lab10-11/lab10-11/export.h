//
// Created by geo on 5/5/18.
//

#ifndef LAB6_EXPORT_H
#define LAB6_EXPORT_H

#include <string>
#include <vector>
#include "movie.h"

/*
 * Function which writes in a list of movies in CVS format
 * :param f_name: string -the file to write in
 * :param mv_lst: vector of movies
 * :post: throws ValidatorException if the file can't be opened
 */
void export_cvs(const std::string& f_name, const vector<Movie>& mv_lst);

/*
 * Function which writes in a list of movies in HTML format
 * :param f_name: string -the file to write in
 * :param mv_lst: vector of movies
 * :post: throws ValidatorException if the file can't be opened
 */
void export_html(const std::string& f_name, const vector<Movie>& mv_lst);

#endif //LAB6_EXPORT_H
