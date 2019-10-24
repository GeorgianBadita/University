//
// Created by geo on 3/27/18.
//

#include <cassert>
#include "tests.h"
#include "repository.h"
#include "service.h"
#include <sstream>
#include <fstream>
#include "helper.h"
#include "export.h"


void Tests::run_tests(){
    this->test_movie();
    this->test_repo();
    this->test_service();
    this->test_helper_methods();
    this->test_cart();
    this->test_export();
}

//******* MOVIE CLASS TESTS *******//
void Tests::test_movie(){
    test_create_movie();
    test_setters_movie();
    test_print_operator();
    test_movie_validator();
}

//******* REPOSITORY CLASS TESTS *****//
void Tests::test_repo(){
    test_store_movie_repo();
    test_search_movie_repo();
    test_delete_movie_repo();
    test_get_all_repo();
    test_update_movie_repo();

}

//***** SERVICE CLASS TESTS ******//
void Tests::test_service(){
    test_add_serv();
    test_del_serV();
    test_upd_serV();
    test_filter_title_srv();
    test_filter_year_srv();
    test_sorts_srv();
    test_add_movie_cart();
    test_delete_all_cart_srv();
    test_generate_random_cart();
    test_undo();
}


//***** HELPER METHODS TESTS **********//
void Tests::test_helper_methods(){
    test_make_integer();
    test_is_integer();
}

//***** CART CLASS TESTS **********//
void Tests::test_cart(){
    test_delete_all_cart();
    test_add_cart();
    test_get_all_cart();
    test_generate_cart();
}
//***** EXPORT TESTS **********//
void Tests::test_export() {
    test_exports();
}

/*
 *
 */
void test_exports(){
    Repository repo{MovieValidator()};
    Service srv = Service{repo};
    srv.add_movie_srv("Deadpool", "Action", 2016, "Ryan Reynolds");
    srv.add_movie_srv("Catch me if you can", "Action", 2002, "Leonardo DiCaprio");
    srv.generate_random_cart(2);
    srv.export_cart_cvs("text_cvs.csv");
    std::ifstream in("text_cvs.csv");
    assert(in.is_open());
    auto count_line = 0;
    while(!in.eof()){
        std::string line;
        getline(in, line);
        count_line ++;
    }
    assert(count_line == 3);
    in.close();

    srv.export_cart_html("text_html.html");
    in.open("text_html.html");
    assert(in.is_open());

    try{
        srv.export_cart_cvs("/utils/text_cvs.cvs");
        assert(false);
    }catch (ValidatorException& ex){
        static_assert(true, "");
    }

    try{
        srv.export_cart_html("/utils/text_html.html");
        assert(false);
    }catch (ValidatorException& ex){
        static_assert(true, "");
    }
}




/*
 *
 */
void test_delete_all_cart(){
    auto cart = Cart();
    auto mv = Movie("asd", "aqweq", 1982, "123");
    cart.add_to_cart(mv);
    mv = Movie("asd", "qweq", 2008, "123");
    cart.add_to_cart(mv);
    assert(cart.get_all_from_cart().size() == 2);
    cart.delete_all_cart();
    assert(cart.get_all_from_cart().empty());
}

/*
 *
 */
void test_generate_cart(){
    vector<Movie>lst;
    auto mv = Movie("asd", "aqweq", 1982, "123");
    lst.push_back(mv);
    mv = Movie("asd", "qweq", 2008, "123");
    lst.push_back(mv);
    Cart cart;
    cart.generate_cart(lst);
    assert(cart.get_all_from_cart().size() == 2);
}

/*
 *
 */
void test_add_cart(){
    auto cart = Cart();
    auto mv = Movie("asd", "aqweq", 1982, "123");
    cart.add_to_cart(mv);
    auto lst = cart.get_all_from_cart();
    assert(lst.size() == 1);
    assert(lst[0] == mv);
    try{
        cart.add_to_cart(mv);
        assert(false);
    }catch(CartException& ex){
        static_assert(true, "");
    }
}

/*
 *
 */
void test_get_all_cart(){
    auto cart = Cart();
    auto mv = Movie("asd", "aqweq", 1982, "123");
    cart.add_to_cart(mv);
    auto lst = cart.get_all_from_cart();
    assert(lst.size() == 1);
}


/*
 *
 */
void test_create_movie(){
    auto movie = Movie("Titanic", "Drama", 1993, "Leonardo Dicaprio");
    assert(movie.get_genre() == "Drama");
    assert(movie.get_main_actor() == "Leonardo Dicaprio");
    assert(movie.get_title() == "Titanic");
    assert(movie.get_year() == 1993);
}

/*
 *
 */
void test_setters_movie(){
    auto movie = Movie("Titanic", "Drama", 1993, "Leonardo Dicaprio");
    string new_actor = "Al Pacino";
    string new_genre = "Action";
    string new_name = "The godfather I";
    int new_year = 1972;
    movie.set_main_actor(new_actor);
    movie.set_genre(new_genre);
    movie.set_title(new_name);
    movie.set_year(new_year);
    assert(movie.get_genre() == new_genre);
    assert(movie.get_main_actor() == new_actor);
    assert(movie.get_title() == new_name);
    assert(movie.get_year() == new_year);
}

void test_print_operator(){
    auto movie = Movie("Titanic", "Drama", 1993, "Leonardo Dicaprio");
    string test;
    string title;
    std::stringstream f(test);
    f << movie;
    f >> title;
    assert(title == "Title:");
}

/*
 *
 */
void test_movie_validator(){
    auto movie = Movie("Titanic", "Drama", 1993, "Leonardo Dicaprio");
    auto validator = MovieValidator();
    try{
        validator.validate(movie);
        static_assert(true, "");
    }catch (ValidatorException& err){
        assert(false);
    }
    movie = Movie("", "", 1592, "");
    try{
        validator.validate(movie);
        assert(false);
    }catch (ValidatorException& err){
        auto errs = err.get_errors();
        assert(errs.size() == 4);
    }
}


/*
 *
 */
void test_store_movie_repo(){
    Repository repo{MovieValidator()};
    auto mv1 = Movie("Deadpool", "Action", 2016, "Ryan Reynolds");
    auto mv2 = repo.store_movie_repo(mv1);
    auto lst = repo.get_all_repo();
    assert(lst.size() == 1);
    assert(mv1 == mv2);
    try {
        repo.store_movie_repo(mv1);
        assert(false);
    }catch(RepositoryException& ex){
        static_assert(true, "");
    }
}

/*
 *
 */
void test_search_movie_repo(){
    Repository repo{MovieValidator()};
    auto mv1 = Movie("Deadpool", "Action", 2016, "Ryan Reynolds");
    auto mv2 = Movie("Catch me if you can", "Action", 2002, "Leonardo DiCaprio");
    repo.store_movie_repo(mv1);
    repo.store_movie_repo(mv2);
    assert(repo.search_movie_repo(mv1) == 1);
    assert(repo.search_movie_repo(mv2) == 1);
    auto mv3 = Movie("The man who knew infinity", "Drama", 2016, "Dev Patel");
    assert(repo.search_movie_repo(mv3) == -1);

}

/*
 *
 */
void test_delete_movie_repo(){
    Repository repo{MovieValidator()};
    auto mv1 = Movie("Deadpool", "Action", 2016, "Ryan Reynolds");
    auto mv2 = Movie("Catch me if you can", "Action", 2002, "Leonardo DiCaprio");
    repo.store_movie_repo(mv1);
    repo.store_movie_repo(mv2);
    auto mv_rez = repo.delete_movie_repo(mv1);
    assert(mv_rez == mv1);
    auto lst = repo.get_all_repo();
    assert(lst.size() == 1);
    auto mv3 = Movie("The man who knew infinity", "Drama", 2016, "Dev Patel");
    mv_rez = repo.delete_movie_repo(mv3);
    assert(mv_rez.get_year() == -1);
}


/*
 *
 */
void test_get_all_repo(){
    Repository repo{MovieValidator()};
    auto mv1 = Movie("Deadpool", "Action", 2016, "Ryan Reynolds");
    auto mv2 = Movie("Catch me if you can", "Action", 2002, "Leonardo DiCaprio");
    repo.store_movie_repo(mv1);
    repo.store_movie_repo(mv2);
    auto lst = repo.get_all_repo();
    assert(lst.size() == 2);
}

/*
 *
 */
void test_update_movie_repo(){
    Repository repo{MovieValidator()};
    auto mv1 = Movie("Deadpool", "Action", 2016, "Ryan Reynolds");
    auto mv2 = Movie("Catch me if you can", "Action", 2002, "Leonardo DiCaprio");
    auto mv3 = Movie("Catch me if you can", "Drama", 2016, "Dev Patel");
    auto mv4 = Movie("The man who knew infinity", "Drama", 2016, "Dev Patel");
    repo.store_movie_repo(mv1);
    repo.store_movie_repo(mv2);
    assert(repo.update_movie_repo(mv3) == mv2);
    assert(repo.search_movie_repo(mv3) >= 0);
    auto rez_upd = repo.update_movie_repo(mv4);
    assert(rez_upd.get_year() == -1);

}

/*
 *
 */
void test_add_serv(){
    Repository repo{MovieValidator()};
    Service srv = Service(repo);
    srv.add_movie_srv("Titanic", "Drama", 1993, "Leonardo DiCaprio");
    auto lst = srv.get_all_srv();
    assert(lst.size() == 1);
    assert(lst[0].get_year() == 1993 && lst[0].get_title() == "Titanic");
    try {
        auto rez = srv.add_movie_srv("Titanic", "Drama", 1993, "Leonardo DiCaprio");
        assert(false);
    }catch (RepositoryException& ex){
        static_assert(true, "");
    }

}


/*
 *
 */
void test_del_serV(){
    Repository repo{MovieValidator()};
    Service srv = Service(repo);
    srv.add_movie_srv("Titanic", "Drama", 1993, "Leonardo DiCaprio");
    auto mv3 = Movie("The man who knew infinity", "Drama", 2016, "Dev Patel");
    srv.add_movie_srv(mv3.get_title(), mv3.get_genre(), mv3.get_year(), mv3.get_main_actor());
    srv.del_movie_srv("The man who knew infinity", "Drama", 2016, "Dev Patel");
    auto lst = srv.get_all_srv();
    assert(lst.size() == 1);
    auto rez = srv.del_movie_srv("The man who knew infinity", "Drama", 2016, "Dev Patel");
    assert(rez.get_year() < 0);
}

/*
 *
 */
void test_upd_serV(){
    Repository repo{MovieValidator()};
    Service srv = Service(repo);
    srv.add_movie_srv("Titanic", "Drama", 1993, "Leonardo DiCaprio");
    srv.update_movie_srv("Titanic", "Action", 2000, "Dev Patel");
    auto lst = srv.get_all_srv();
    assert(lst[0].get_year() == 2000);
    assert(lst[0].get_main_actor() == "Dev Patel");
    assert(lst[0].get_genre() == "Action");
    assert(lst[0].get_title() == "Titanic");
    auto rez = srv.update_movie_srv("The Exorcist", "Horror", 2010, "Someone");
    assert(rez.get_year() < 0);
}

/*
 *
 */
void test_filter_title_srv(){
    Repository repo{MovieValidator()};
    Service srv = Service(repo);
    srv.add_movie_srv("The god father I", "Drama", 1972, "Al Pacino");
    srv.add_movie_srv("The god father II", "Drama", 1974, "Al Pacino");
    srv.add_movie_srv("Titanic", "Action", 2000, "Dev Patel");
    auto lst = srv.filter_by_title_srv("The god father");
    assert(lst.size() == 2);
    assert(lst[0].get_title() == "The god father I");
}

/*
 *
 */
void test_filter_year_srv(){
    Repository repo{MovieValidator()};
    Service srv = Service(repo);
    srv.add_movie_srv("The god father I", "Drama", 1972, "Al Pacino");
    srv.add_movie_srv("The god father II", "Drama", 1974, "Al Pacino");
    srv.add_movie_srv("Titanic", "Action", 2000, "Dev Patel");
    auto lst = srv.filter_by_year_srv(1972);
    assert(lst[0].get_title() == "The god father I");
    assert(lst[0].get_year() == 1972);
}

/*
 *
 */
void test_sorts_srv(){
    Repository repo{MovieValidator()};
    Service srv = Service(repo);
    srv.add_movie_srv("The god father I", "Drama", 1972, "Al Pacino");
    srv.add_movie_srv("Ahe god father II", "Drama", 1974, "Bl Pacino");
    srv.add_movie_srv("Titanic", "Action", 2000, "Dev Patel");
    auto rez = srv.sort_by_criteria(1, false);
    assert(rez[0].get_title() == "Ahe god father II");
    assert(rez[1].get_title() == "The god father I");
    rez = srv.sort_by_criteria(1, true);
    assert(rez[0].get_title() == "Titanic");
    assert(rez[1].get_title() == "The god father I");
    rez = srv.sort_by_criteria(2, false);
    assert(rez[0].get_genre() == "Action");
    assert(rez[1].get_genre() == "Drama");
    rez = srv.sort_by_criteria(2, true);
    assert(rez[0].get_genre() == "Drama");
    assert(rez[2].get_genre() == "Action");
    rez = srv.sort_by_criteria(3, false);
    assert(rez[0].get_year() == 1972);
    assert(rez[2].get_year() == 2000);
    rez = srv.sort_by_criteria(3, true);
    assert(rez[0].get_year() == 2000);
    assert(rez[2].get_year() == 1972);
    rez = srv.sort_by_criteria(4, false);
    assert(rez[0].get_main_actor() == "Al Pacino");
    assert(rez[1].get_main_actor() == "Bl Pacino");
    rez = srv.sort_by_criteria(4, true);
    assert(rez[0].get_main_actor() == "Dev Patel");
    assert(rez[1].get_main_actor() == "Bl Pacino");
    rez = srv.sort_by_criteria(5, true);
}

/*
 *
 */
void test_add_movie_cart(){
    MovieValidator val;
    Repository repo(val);
    Service srv = Service(repo);
    srv.add_movie_srv("The god father I", "Drama", 1972, "Al Pacino");
    srv.add_movie_srv("The god father II", "Drama", 1974, "Bl Pacino");
    srv.add_movie_srv("Titanic", "Action", 2000, "Dev Patel");
    srv.add_movie_cart("The god father I");
    assert(srv.seacrh_movie_srv("Titanic"));
    assert(!srv.seacrh_movie_srv("asd"));
    assert(srv.get_all_cart().size() == 1);
}

/*
 *
 */
void test_delete_all_cart_srv(){
    MovieValidator val;
    Repository repo(val);
    Service srv = Service(repo);
    srv.add_movie_srv("The god father I", "Drama", 1972, "Al Pacino");
    srv.add_movie_srv("Ahe god father II", "Drama", 1974, "Bl Pacino");
    srv.add_movie_srv("Titanic", "Action", 2000, "Dev Patel");
    srv.add_movie_cart("The god father I");
    srv.add_movie_cart("Ahe god father II");
    assert(srv.get_all_cart().size() == 2);
    srv.delete_all_cart_srv();
    assert(srv.get_all_cart().empty());
}

/*
 *
 */
void test_generate_random_cart(){
    MovieValidator val;
    Repository repo(val);
    Service srv = Service(repo);
    srv.add_movie_srv("The god father I", "Drama", 1972, "Al Pacino");
    srv.add_movie_srv("Ahe god father II", "Drama", 1974, "Bl Pacino");
    srv.add_movie_srv("Titanic", "Action", 2000, "Dev Patel");
    srv.generate_random_cart(3);
    assert(srv.get_all_cart().size() == 3);
}




/*
 *
 */
void test_make_integer(){
    assert(make_integer("1231") == 1231);
    assert(make_integer("0") == 0);
    assert(make_integer("2") == 2);
}

/*
 *
 */
void test_is_integer(){
    assert(!is_integer("asdaf"));
    assert(!is_integer("0wdsa"));
    assert(!is_integer("12as"));
    assert(is_integer("0"));
    assert(is_integer("454"));
}

/*
 *
 */
void test_undo(){
    MovieValidator val;
    Repository repo(val);
    Service srv = Service(repo);
    srv.add_movie_srv("The god father I", "Drama", 1972, "Al Pacino");
    srv.add_movie_srv("Ahe god father II", "Drama", 1974, "Bl Pacino");
    srv.add_movie_srv("Titanic", "Action", 2000, "Dev Patel");
    srv.undo();
    assert(srv.get_all_srv().size() == 2);
    srv.del_movie_srv("The god father I", "Drama", 1972, "Al Pacino");
    assert(srv.get_all_srv().size() == 1);
    srv.undo();
    assert(srv.get_all_srv().size() == 2);
    srv.update_movie_srv("Ahe god father II", "Drama", 1974, "Al Pacino");
    auto lst = srv.get_all_srv();
    assert(lst[0].get_main_actor() == "Al Pacino");
    srv.undo();
    lst = srv.get_all_srv();
    assert(lst[0].get_main_actor() == "Bl Pacino");
}
