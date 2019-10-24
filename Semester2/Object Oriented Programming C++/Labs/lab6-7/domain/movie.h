//
// Created by geo on 3/27/18.
//

#ifndef LAB6_MOVIE_H
#define LAB6_MOVIE_H

#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

/*
 * Class for representing a movie
 */
class Movie{
private:
    string title;
    string genre;
    int year;
    string main_actor;

public:

    Movie() = default;

    //Class constructor
    Movie(const string& title, const string& genre, const int& year, const string& main_actor);
    //getters
    int get_year() const {return this->year;}
    string get_main_actor() const {return this->main_actor;}
    string get_genre() const {return this->genre;}
    string get_title() const {return this->title;}

    //setters
    void set_year(const int& year);
    void set_main_actor(const string& new_actor);
    void set_title(const string& new_title);
    void set_genre(const string& new_genre);

    //overloading operator ==
    bool operator ==(const Movie& other) const{
        return this->title == other.title && this->year == other.year &&
               this->main_actor == other.main_actor && this->genre == other.genre;
    }

    //overriding operaror !=
    bool operator !=(const Movie& other) const{
        return !(*this == other);
    }

    //overloading operator <<
    friend std::ostream& operator<<(std::ostream& os, const Movie& mv);

};

#endif //LAB6_MOVIE_H
