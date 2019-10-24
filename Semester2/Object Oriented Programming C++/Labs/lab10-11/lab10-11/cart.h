//
// Created by geo on 4/22/18.
//

#ifndef LAB6_CART_H
#define LAB6_CART_H

#include "movie.h"
#include <observer.h>

/*
 * Class for CartException
 */
class CartException{

};

/*
 * Class for representing our shopping cart
 */
class Cart: public Observable{
private:
    vector <Movie> my_cart;
    //Function which searches for a given movie in the list
    bool find_in_cart(const Movie& mv);
public:
    //Function for deleting all the items stored in the sopping cart
    void delete_all_cart();

    //Function for adding an item in the shopping cart
    void add_to_cart(const Movie& mv);

    //Function for generating a random shopping cart
    void generate_cart(const vector<Movie>& lst);

    //Function which returns the list of movies
    vector<Movie> get_all_from_cart();
};


#endif //LAB6_CART_H
