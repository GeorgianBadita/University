//
// Created by geo on 3/27/18.
//

#ifndef LAB6_REPOSITORY_H
#define LAB6_REPOSITORY_H

#include <utility>

#include "../domain/movie.h"
#include "../domain/validator.h"

/*
 * RepositoryException class
 * :::Checks if an object is already in the repository :::
 */
class RepositoryException{

};

/*
 * Class for representing our repository
 */
class Repository{
private:
    vector<Movie> mv_list;
    MovieValidator mv_validator;
public:

    Repository() = default;


    //Repository class constructor
    explicit Repository(const MovieValidator& mv_validator):mv_validator{mv_validator}{}

    //Function to store a movie into the repository
     Movie store_movie_repo(const Movie &mv);

    //Function to delete a movie from the repository
     Movie delete_movie_repo(const Movie &mv);

    //Function to update a movie from the repository
     Movie update_movie_repo(const Movie &mv);

    //Function to get a movie from a certain position
     Movie get_at_pos(int pos);

    //Function to search a movie into the repository
    int search_movie_repo(const Movie &mv);

    //Function that gets all the movies from the repository
    vector<Movie>get_all_repo();

};


#endif //LAB6_REPOSITORY_H
