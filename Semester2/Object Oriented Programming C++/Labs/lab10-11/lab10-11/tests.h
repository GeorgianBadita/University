//
// Created by geo on 3/27/18.
//

#ifndef LAB6_TESTS_H
#define LAB6_TESTS_H

#include "movie.h"
#include "cart.h"


class Tests{
public:
    void run_tests();
private:
    //******* MOVIE CLASS TESTS *******//
    void test_movie();

    //******* REPOSITORY CLASS TESTS *****//
    void test_repo();

    //***** SERVICE CLASS TESTS ******//
    void test_service();

    //***** HELPER METHODS TESTS **********//
    void test_helper_methods();

    //***** CART CLASS TESTS **********//
    void test_cart();

    //***** EXPORT TESTS **********//
    void test_export();
};


/*
 *
 */
void test_create_movie();

/*
 *
 */
void test_setters_movie();

/*
 *
 */
void test_print_operator();

/*
 *
 */
void test_movie_validator();




/*
 *
 */
void test_store_movie_repo();

/*
 *
 */
void test_search_movie_repo();

/*
 *
 */
void test_delete_movie_repo();

/*
 *
 */
void test_get_at_pos();

/*
 *
 */
void test_get_all_repo();

/*
 *
 */
void test_update_movie_repo();







/*
 *
 */
void test_add_serv();

/*
 *
 */
void test_del_serV();

/*
 *
 */
void test_upd_serV();

/*
 *
 */
void test_filter_title_srv();

/*
 *
 */
void test_filter_year_srv();

/*
 *
 */
void test_sorts_srv();

/*
 *
 */
void test_add_movie_cart();

/*
 *
 */
void test_delete_all_cart_srv();

/*
 *
 */
void test_generate_random_cart();



/*
 *
 */
void test_make_integer();

/*
 *
 */
void test_is_integer();



/*
 *
 */
void test_delete_all_cart();

/*
 *
 */
void test_add_cart();

/*
 *
 */
void test_get_all_cart();

/*
 *
 */
void test_generate_cart();


/*
 *
 */
void test_exports();

/*
 *
 */
void test_undo();

#endif //LAB6_TESTS_H
