//
// Created by geo on 3/28/18.
//

#ifndef LAB6_USER_INTERFACE_H
#define LAB6_USER_INTERFACE_H

#include "service.h"

//Class for defining our user interface
class UI{
private:
    Service srv;

    //Function that prints the user's menu
    void print_menu();

    //Function that reads a command from the keyboard and returns it
    int read_cmd();

    //Function that prints all movies
    void print_all_movies();

    //Function that adds a new movie
    void add_movie();

    //Function that deletes a movie
    void del_movie();

    //Function that updates a movie
    void update_movie();

    //Function that populates the application with data
    void populate();

    //Function that filters the list
    void filter_movies();

    //Function that sorts the list
    void sort_movies();

    //Function for cart options
    void manage_cart();

    //Function to add a movie to a cart
    void add_to_cart_ui();

    //Function to delete all movies from a cart
    void delete_all_cart_ui();

    //Function to generate a random cart of movies
    void generate_cart_ui();

    //Function which displays the number of movies in the cart
    void disply_num_cart();

    //Function which does an undo action
    void make_undo();

public:
    //UI constructor
    explicit UI(Service& srv);

    //Function that controls the users actions
    void show_ui();
};

#endif //LAB6_USER_INTERFACE_H
