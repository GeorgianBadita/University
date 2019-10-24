//
// Created by geo on 4/22/18.
//

#include "cart.h"

/*
 * Function which delets all the items in a cart
 * :param: -
 * :return: -
 * :post: all the items from the cart will be deleted
 */
void Cart::delete_all_cart(){
    vector <Movie> v;
    this->my_cart = v;
    this->notify();
}

/*
 * Function which returns a list with all the movies from the cart
 */
vector<Movie> Cart::get_all_from_cart(){
    return this->my_cart;
}

/*
 * Function which tells if a given movie is already in the cart
 * :param mv: movie to be searched
 * :return: true if the movie is in the list, false otherwise
 */
bool Cart::find_in_cart(const Movie& mv){
    auto mv_lst = this->get_all_from_cart();
    for( const auto& mvl : mv_lst){
        if(mvl == mv){
            return true;
        }
    }
    return false;
}

/*
 * Function which adds a movie to a cart
 * :param mv: movie to be added
 * :post: the movie will be added to the cart
 */
void Cart::add_to_cart(const Movie& mv){
    if(this->find_in_cart(mv)){
        throw CartException();
    }
    else{
        this->my_cart.push_back(mv);
        this->notify();
    }
}

/*
 * Function which generates a cart giving a list of movies
 * :param v: list of movies
 */
void Cart::generate_cart(const vector<Movie>& lst){
    this->delete_all_cart();
    for(const auto& mv : lst){
        this->add_to_cart(mv);
        this->notify();
    }
}
