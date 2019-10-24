//
// Created by geo on 3/27/18.
//

#include <fstream>
#include "repository.h"

/*
 * Function that searches for a movie in the list
 * :param mv: Movie object that we are searching
 * :return: the movie position if we find it, -1 otherwise
 */
int Repository::search_movie_repo(const Movie &mv){
    for(int i = 0; i< this->mv_list.size(); i++){
        if(this->mv_list[i] == mv){
            return i;
        }
    }
    return -1;
}

/*
 * Function that stores a movie in the repository list
 * :param mv: Movie type object to be stored
 * :return: the newly added movie if we could add it
 * :raise: RepositoryException
 */
Movie Repository::store_movie_repo(const Movie &mv){
    int pos = search_movie_repo(mv);
    if(pos < 0){
        this->mv_validator.validate(mv);
        this->mv_list.push_back(mv);
        return mv;
    }
    else{
        throw RepositoryException();
    }
}

/*
 * Function that deletes a movie in the repository list
 * :param mv: Movie type object to be deleted
 * :return: the deleted movie if we could delete it, a movie with negative year
 * will be returned if we cant delete it
 */
Movie Repository::delete_movie_repo(const Movie &mv){
    this->mv_validator.validate(mv);
    int pos = search_movie_repo(mv);
    if(pos < 0){
        return Movie("A", "A", -1, "A");
    }
    else{
        Movie to_ret = this->mv_list[pos];
        this->mv_list.erase(this->mv_list.begin() + pos);
        return to_ret;

    }
}
/*
 * Function that updates a movie in the repository list
 * :param mv: The movie containing the name - unique key and the fields to be updated
 * :return: the old movie if we could update it, a movie containing a negative year otherwise
 */
Movie Repository::update_movie_repo(const Movie &mv){
    this->mv_validator.validate(mv);
    int pos = -1;
    for(int i = 0; i<this->mv_list.size(); i++){
        if(this->mv_list[i].get_title() == mv.get_title()){
            pos = i;
            break;
        }
    }
    if(pos < 0){
        return Movie("A", "A", -1, "A");
    }
    else{
        Movie to_ret = delete_movie_repo(this->mv_list[pos]);
        store_movie_repo(mv);
        return to_ret;
    }
}
/*
 * Function that gets a movie from a certain position
 * :param pos: the position of the movie we want
 * :return: the movie at position pos if it exits, a movie
 * with negative year otherwise
 */
Movie Repository::get_at_pos(int pos){
    if(pos < this->mv_list.size()){
        return this->mv_list[pos];
    }
    else{
        return Movie("A", "A", -1, "A");
    }
}

/*
 * Function that gets all the movies from the lsit
 * :param: - none;
 * :return: a vector type containing all the movies from the repository list
 */
vector<Movie> Repository:: get_all_repo(){
    return this->mv_list;
}

