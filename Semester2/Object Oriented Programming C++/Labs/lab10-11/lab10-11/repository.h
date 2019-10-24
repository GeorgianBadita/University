//
// Created by geo on 3/27/18.
//

#ifndef LAB6_REPOSITORY_H
#define LAB6_REPOSITORY_H

#include <utility>

#include "movie.h"
#include "validator.h"
#include <map>

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
    //vector<Movie> mv_list;
    std::map<std::string, Movie> mv_list;
    MovieValidator mv_validator;
public:

    Repository() = default;


    //Repository class constructor
    explicit Repository(const MovieValidator& mv_validator):mv_validator{mv_validator}{}

    //Function to store a movie into the repository
    virtual Movie store_movie_repo(const Movie &mv);

    //Function to delete a movie from the repository
    virtual Movie delete_movie_repo(const Movie &mv);

    //Function to update a movie from the repository
    virtual Movie update_movie_repo(const Movie &mv);

    //Function to search a movie into the repository
    int search_movie_repo(const Movie &mv);

    //Function that gets all the movies from the repository
    vector<Movie>get_all_repo();

};


class RepoFile: public Repository{
private:
    std::string file_name;
    void load_from_file();
    void store_to_file();
public:
     RepoFile(const MovieValidator& mv_validator, const std::string f_name): Repository(mv_validator), file_name{f_name}{
         this->load_from_file();
     }
     Movie store_movie_repo(const Movie& mv) override{
         auto ret = Repository::store_movie_repo(mv);
         this->store_to_file();
         return ret;
     }
     Movie delete_movie_repo(const Movie& mv) override{
         auto ret = Repository::delete_movie_repo(mv);
         this->store_to_file();
         return ret;
     }
     Movie update_movie_repo(const Movie& mv) override{
         auto ret = Repository::update_movie_repo(mv);
         this->store_to_file();
         return ret;
     }
};

#endif //LAB6_REPOSITORY_H
