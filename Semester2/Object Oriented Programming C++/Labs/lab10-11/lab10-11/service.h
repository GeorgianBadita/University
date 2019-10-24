//
// Created by geo on 3/28/18.
//

#ifndef LAB6_SERVICE_H
#define LAB6_SERVICE_H

#include <memory>
#include "repository.h"
#include "cart.h"
#include "undo.h"
#include <observer.h>

/*
 * Class for representing our Service
 */
class Service{
private:
    Repository& repo;
    std::vector<std::unique_ptr<UndoAction>> undos;
public:
    Cart cart;
    /*
     */
    Service() = default;

    /*
     * Service constructor function
     * :param repo: the repository for the current service
     * :post: a new Service will be created
     */
    Service(Repository& repo):repo{repo} {}

    //Function to add a Movie in the service
    Movie add_movie_srv(const string& title, const string& genre,
                        const int& year, const string& main_actor);

    //Function which adds a movie to the cart
    void add_movie_cart(const string& title);

    //Function which deletes all movies from the cart
    void delete_all_cart_srv();

    //Function which generates a random cart of movies
    void generate_random_cart(int number);

    //Function which returns all the movies from a cart
    vector<Movie> get_all_cart();

    //Function to delete a Movie in the service
    Movie del_movie_srv(const string& title, const string& genre,
                        const int& year, const string& main_actor);

    //Function to update a Movie in the service
    Movie update_movie_srv(const string& title, const string& genre,
                           const int& year, const string& main_actor);

    //Function which finds a movie by giving its name
    bool seacrh_movie_srv(const string& title);

    //Function that filters a list of movies by title
    vector<Movie> filter_by_title_srv(const string& title);

    //Function that filters a list of movies by year
    vector<Movie> filter_by_year_srv(const int& year);

    //Function that returns the list of all movies
    vector<Movie> get_all_srv();

    //Function that sorts a list of movies by a given criteria, ascending or descending
    vector<Movie> sort_by_criteria(const int& criteria, const bool& reverse);

    //Function which exports all the items in a cart into a cvs file

    void export_cart_cvs(const string& f_name);

    //Function which exports all the itesm in a cart into a html file
    void export_cart_html(const string& f_name);

    //Function which does an undo action
    void undo();
};

#endif //LAB6_SERVICE_H
