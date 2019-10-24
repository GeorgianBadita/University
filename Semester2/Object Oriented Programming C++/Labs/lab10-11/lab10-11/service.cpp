//
// Created by geo on 3/28/18.
//

#include "service.h"
#include "export.h"
#include <algorithm>
#include <chrono>
#include <random>


/*
 * Function to add a movie to the service
 * :param title: string the title of the movie
 * :param genre: the genre of the movie
 * :param year: integer, the year of the movie
 * :param main_actor: string the main actor of the movie
 * :return: The movie if we could add it
 * :raise: RepositoryException if the movie already exists
 * :raise: ValidatorException if the movie is not correct
 */
Movie Service::add_movie_srv(const string& title, const string& genre,
                            const int& year, const string& main_actor){
    auto mv = Movie(title, genre, year, main_actor);
    this->undos.push_back(std::make_unique<UndoAdd>(this->repo, mv));
    auto rez = this->repo.store_movie_repo(mv);
    return rez;
}

/*
 * Function to delete a movie from the service
 * :param title: string the title of the movie
 * :param genre: the genre of the movie
 * :param year: integer, the year of the movie
 * :param main_actor: string the main actor of the movie
 * :return: The movie if we could add it, a movie with negative day otherwise
 */
Movie Service::del_movie_srv(const string& title, const string& genre,
                   const int& year, const string& main_actor){
    auto mv = Movie(title, genre, year, main_actor);
    this->undos.push_back(std::make_unique<UndoDel>(this->repo, mv));
    auto rez = this->repo.delete_movie_repo(mv);
    return rez;
}


/*
 * Function that returns a list with all the movies from the repository
 * :param: -
 * :return: a list with all the movies from the repository
 */
vector<Movie> Service::get_all_srv(){
    return this->repo.get_all_repo();
}

/*
 * Function to update a movie from the service
 * :param title: string the title of the movie
 * :param genre: the genre of the movie
 * :param year: integer, the year of the movie
 * :param main_actor: string the main actor of the movie
 * :return: The movie if we could add it, a movie with negative day otherwise
 */
Movie Service::update_movie_srv(const string& title, const string& genre,
                      const int& year, const string& main_actor){
    auto mv = Movie(title, genre, year, main_actor);
    auto rez = this->repo.update_movie_repo(mv);
    this->undos.push_back(std::make_unique<UndoModif>(this->repo, rez));
    return rez;
}

/*
 * Function that filters a list of movies by title
 * :param title: the title to filter by
 * :return: the movies which matches the title given as parameter
 */
vector<Movie> Service::filter_by_title_srv(const string& title){
    vector<Movie>to_ret;
    vector<Movie> all_movies = this->repo.get_all_repo();
    for(const auto& mv : all_movies){
        string mv_title = mv.get_title();
        if(mv_title.find(title) != string::npos){
            to_ret.push_back(mv);
        }
    }
    return to_ret;
}

/*
 * Function that filters a list of movies by title
 * :param title: the title to filter by
 * :return: the movies which matches the title given as parameter
 */
vector<Movie> Service::filter_by_year_srv(const int& year){
    vector<Movie> to_ret;
    vector<Movie> all_movies = this->repo.get_all_repo();
    for(const auto& mv : all_movies){
        if(mv.get_year() == year){
            to_ret.push_back(mv);
        }
    }
    return to_ret;
}


/*
 * Function which searches a movie by title
 * :param title: string - the title of the movie
 * :return: true if we could find the movie, false otherwise
 */
bool Service::seacrh_movie_srv(const string& title){
    auto lst = this->get_all_srv();
    for(const auto& mv: lst){
        if(mv.get_title() == title){
            return true;
        }
    }
    return false;
}


/*
 * Function that sorts a list of movies by a certain criteria
 * :param criteria: the criteria we're sorting by 1 - name, 2 - genre, 3 - year, 4 - main_actor
 * :param reverse: tells if the order should be ascending or descending - true ascending, false - desc
 */
vector<Movie> Service::sort_by_criteria(const int& criteria, const bool& reverse){
    vector<Movie> to_sort = this->repo.get_all_repo();
    switch (criteria){
        case 1:

           sort(to_sort.begin(), to_sort.end(),[](const Movie& mv1, const Movie& mv2){
                auto title1 = mv1.get_title();
                auto title2 = mv2.get_title();
                return title1.compare(title2) <= 0;
            });
            break;
        case 2:
            sort(to_sort.begin(), to_sort.end(),[](const Movie& mv1, const Movie& mv2){
                auto genre1 = mv1.get_genre();
                auto genre2 = mv2.get_genre();
                return genre1.compare(genre2) <= 0;
            });
            break;
        case 3:
            sort(to_sort.begin(), to_sort.end(),[](const Movie& mv1, const Movie& mv2){
                auto year1 = mv1.get_year();
                auto year2 = mv2.get_year();
                return year1 <= year2;
            });
            break;
        case 4:
            sort(to_sort.begin(), to_sort.end(),[](const Movie& mv1, const Movie& mv2){
                auto actor1 = mv1.get_main_actor();
                auto actor2 = mv2.get_main_actor();
                return actor1.compare(actor2) <= 0;
            });
            break;
        default:
            break;
    }
    if(reverse){
        std::reverse(to_sort.begin(), to_sort.end());
    }
    return to_sort;
}


/*
 * Function which adds a new movie to the cart by title
 * :param title: the name of the movie
 */
void Service::add_movie_cart(const string& title){
    auto lst = this->get_all_srv();
    Movie to_add;
    for(const auto& mv : lst){
        if(mv.get_title() == title){
            to_add = mv;
            break;
        }
    }
    //std::cout << title << " " << to_add << '\n';
    this->cart.add_to_cart(to_add);
   // this->notify();
}

/*
 * Function which deletes all movies from the services's cart
 * :post: all the movies from the cart will be deleted
 */
void Service::delete_all_cart_srv(){
    this->cart.delete_all_cart();
    //this->notify();
}

/*
 * Function which generates a random cart of movies
 * :param number: the number of movies to be generated
 */
void Service::generate_random_cart(int number){
    auto lst = this->get_all_srv();
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(lst.begin(), lst.end(), std::default_random_engine(seed)); //amesteca vectorul v
    vector<Movie> to_add;
    for(int i = 0; i<number; i++){
        to_add.push_back(lst[i]);
    }
    this->cart.generate_cart(to_add);
    //this->notify();
}


/*
 * Function which returns all the movies from a cart
 */
vector<Movie> Service::get_all_cart(){
    return this->cart.get_all_from_cart();
}

/*
 * Function which exports items from a cart into a cvs file
 * :param f_name: the name of the file
 */
void Service::export_cart_cvs(const std::string& f_name){
    export_cvs(f_name, this->cart.get_all_from_cart());
}

/*
 * Function which exports items from a cart into a html file
 * :param f_name: the name of the file
 */
void Service::export_cart_html(const std::string& f_name){
    export_html(f_name, this->cart.get_all_from_cart());
}


/*
 * Function which does an undo action
 * :post: an undo action will be done
 * :throw: throws UndoException if the undo list is empty
 */
void Service::undo(){
    if(this->undos.empty()){
        throw UndoException();
    }
    this->undos.back()->do_undo();
    this->undos.pop_back();
}
