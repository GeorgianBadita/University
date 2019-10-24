//
// Created by geo on 3/27/18.
//

#include "movie.h"

/*
 * Movie class constructor
 * :param title: string the title of the movie
 * :param genre: string the genre of the movie
 * :param year: integer, the year of the movie
 * :param main_actor: string the main actor of the movie
 * :post: there'll be a new movie created
 */
Movie::Movie(const string &title, const string &genre, const int &year, const string &main_actor)
        :title{title}, genre{genre}, year{year}, main_actor{main_actor} {}


/*
 * Trivial destructor
 */
 Movie::~Movie(){

}

/*
 * Setter methods
 */
void Movie::set_year(const int& year) {this->year = year;}
void Movie::set_main_actor(const string& new_actor) {this->main_actor = new_actor;}
void Movie::set_title(const string& new_title) {this->title = new_title;}
void Movie::set_genre(const string& new_genre) {this->genre = new_genre;}

/*
 * Overriding operators
 */
std::ostream& operator<<(std::ostream& os, const Movie& mv){
    os << "\tTitle: " << mv.title << "   Genre: " << mv.genre << "   Year: " << mv.year << "   Main: " << mv.main_actor;
    return os;
}

