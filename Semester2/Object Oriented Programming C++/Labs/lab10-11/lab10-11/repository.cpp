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

    std::map<std::string, Movie>::iterator it;

    for(it = this->mv_list.begin(); it != this->mv_list.end(); it++){
        if(it->second == mv){
            return  1;
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
        //this->mv_list.push_back(mv);
        this->mv_list.insert(std::pair<std::string, Movie>(mv.get_title(), mv));
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
        Movie to_ret = mv;
        this->mv_list.erase(mv.get_title());
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

    if(this->mv_list.find(mv.get_title()) == this->mv_list.end()){
        return Movie("A", "A", -1, "A");
    }
    else{
        Movie to_ret = delete_movie_repo(this->mv_list[mv.get_title()]);
        store_movie_repo(mv);
        return to_ret;
    }
}


/*
 * Function that gets all the movies from the lsit
 * :param: - none;
 * :return: a vector type containing all the movies from the repository list
 */
vector<Movie> Repository:: get_all_repo(){
    vector<Movie> res;
    std::map<std::string, Movie>::iterator it;
    for(it = this->mv_list.begin(); it != this->mv_list.end(); it++){
        res.push_back(it->second);
    }
    return res;
}



void RepoFile::load_from_file(){
    std::ifstream in(this->file_name);

    if(!in.is_open()){
        throw RepositoryException();
    }

    while(!in.eof()){
        std::string title;
        getline(in, title);

        std::string genre;

        getline(in, genre);

        int year;
        in >> year;

        std::string actor;
        getline(in, actor);

        if(!in.eof()){
            break;
        }

        /*std::cout << title << '\n' << genre << '\n' << year << '\n' << actor << '\n';

        auto  mv = Movie(title, genre, year, actor);
        Repository::store_movie_repo(mv);*/
    }

    in.close();
}

void RepoFile::store_to_file(){
    std::ofstream out(this->file_name);

    if(!out.is_open()){
        throw RepositoryException();
    }

    for(const auto& mv : this->get_all_repo()){
        out << mv.get_title();
        out << std::endl;
        out << mv.get_genre();
        out << std::endl;
        out << mv.get_year();
        out << std::endl;
        out << mv.get_main_actor();
        out << std::endl;

    }
    out.close();
}
