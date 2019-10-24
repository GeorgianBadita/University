//
// Created by geo on 3/28/18.
//

#include "user_interface.h"
#include "helper.h"


/*
 * Constructor function for the user interface
 * :param srv: the UI's service
 * :post: a new UI will be created
 */
UI::UI(Service& srv):srv{std::move(srv)}{}

/*
 * Function that prints a list of errors
 * :param vector: list of errors
 */
void print_errs(vector<std::string>& errs){
    std::cout << '\n';
    for(const auto& elem: errs){
        std::cout << elem << '\n';
    }
}

/*
 * Function that prints the user menu
 * :post: a string containing the menu options will be printed to the screen
 */
void UI::print_menu(){
    string menu;
    menu += "\t 0. To print all the movies\n"
            "\t 1. To add a new movie\n"
            "\t 2. To delete a movie\n"
            "\t 3. To modify a movie\n"
            "\t 4. To filter the movies\n"
            "\t 5. To sort the movies by criteria\n"
            "\t 6. To access cart options\n"
            "\t 7. To make an undo\n"
            "\t 8. To exit the app\n";
    std::cout << menu;
}

/*
 * Function that reads a command from the std input
 * :param: -
 * :return: the command read from the keyboard
 */
int UI::read_cmd(){
    int cmd = read_int("Please give a command: ");
    return cmd;
}

/*
 * Function that prints all the movies
 * :param: -
 * :post: all the movies will be printed to the screen
 */
void UI::print_all_movies() {
    std::cout<<"\n\n";
    vector<Movie> to_print = this->srv.get_all_srv();
    for(const auto& movie:to_print){
        std::cout << movie << "\n";
    }
    std::cout<<"\n\n";
}

/*
 * Function that populates the application with data
 * :return: -
 * :post: application will be populated with data
 */
void UI::populate(){
    this->srv.add_movie_srv("Titanic", "Drama", 1993, "Leonardo DiCaprio");
    this->srv.add_movie_srv("The Godfather I", "Action", 1972, "Al Pacino");
    this->srv.add_movie_srv("The Godfather II", "Action", 1974, "Al Pacino");
    this->srv.add_movie_srv("The man who knew infinity", "Drama", 2013, "Dev Patel");
    this->srv.add_movie_srv("The martian", "Sci-Fi", 2016, "Matt Damon");

}

/*
 * Function that reads a movie from the standard input
 * :param title: the title of the movie
 * :param genre: the genre of the movie
 * :param year: the year when the movie was released
 * :param main_actor: the main actor of the movie
 */
void read_movie(string& title, string& genre, int& year, string& main_actor){
    std::cout << "\nPlease give the title of the movie: ";
    getline(std::cin, title);
    std::cout << "\nPlease give the genre of the movie: ";
    getline(std::cin, genre);
    year = read_int("\nPlease give the year of release: ");
    std::cout << "\nPlease give the main actor:  ";
    getline(std::cin, main_actor);
}

/*
 * Function that adds a new movie to the application
 * :return: -
 * :post: a new movie will be added to the application
 */
void UI::add_movie() {
    string title, genre, main_actor;
    int year={0};
    read_movie(title, genre, year, main_actor);
    try {
        auto mv = this->srv.add_movie_srv(title, genre, year, main_actor);
        std::cout << "\nThe movie " + title + " was added!\n\n";
    }catch (ValidatorException& ex){
        auto errors = ex.get_errors();
        print_errs(errors);
    }catch (RepositoryException& ex){
        std::cout << "\nThe movie already exits!\n\n";
    }
}

/*
 * Function that deletes a movie from the application
 * :return: -
 * :post: the movie will be deleted
 */
void UI::del_movie() {
    string title, genre, main_actor;
    int year={0};
    read_movie(title, genre, year, main_actor);
    try {
        auto mv = this->srv.del_movie_srv(title, genre, year, main_actor);
        if(mv.get_year() < 0){
            std::cout << "\nThe movie doesn't exist!\n";
        }
        else{
            std::cout << "\nThe movie " << mv.get_title() << " was deleted!\n";
        }
    }catch (ValidatorException& ex){
        auto errors = ex.get_errors();
        print_errs(errors);
    }
}

/*
 * Function that updates a movie
 * :return: -
 * :pre: the name of the movie will be the key
 * :post: the movie will be updated
 */
void UI::update_movie() {
    string title, genre, main_actor;
    int year={0};
    read_movie(title, genre, year, main_actor);
    try {
        auto mv = this->srv.update_movie_srv(title, genre, year, main_actor);
        if (mv.get_year() < 0) {
            std::cout << "\nThe movie doesn't exist!\n";
        } else {
            std::cout << "\nThe movie " << mv.get_title() << " was updated!\n";
        }
    }catch (ValidatorException& ex){
        auto errors = ex.get_errors();
        print_errs(errors);
    }
}


/*
 * Function that filters movies by type and by year of release
 * :param: -
 * :return: -
 * :post: will display a list of movies containing the given type, or the given year of release
 */
void UI::filter_movies(){
    string to_filter;
    int by{0}, year{0};
    printf("\t 1. To filter by name\n"
           "\t 2. To filter by year of release\n");
    by = read_int("Please give a command: ");
    switch (by){
        case 1: {
            printf("Please give the name of movie you want: ");
            std::cin.ignore();
            getline(std::cin, to_filter);
            auto lst_name = this->srv.filter_by_title_srv(to_filter);
            std::cout << "\n";
            for(const auto& mv : lst_name){
                std::cout << mv << '\n';
            }
            std::cout << "\n\n";
            break;
        }
        case 2: {
            year = read_int("Please give the year you want to filter by: ");
            auto lst_year = this->srv.filter_by_year_srv(year);
            std::cout << "\n";
            for(const auto& mv : lst_year){
                std::cout << mv << '\n';
            }
            std::cout << "\n\n";
            break;
        }
        default:
            std::cout << "\nWrong command!\n";
            break;
    }
}

/*
 * Function that sorts the list of movies by all criterisa
 * :param: -
 * :post: will print the list sorted by a given criteria
 */
void UI::sort_movies() {
    int criteria{0}, to_reverse{0};
    bool reverse = false;
    printf("\t 1. To sort by title\n"
           "\t 2. To sort by genre\n"
           "\t 3. To sort by year of release\n"
           "\t 4. To sort by main actor\n");
    criteria = read_int("Please give a command: ");
    printf("\t 1. To sort ascending\n"
           "\t 2. To sort descending\n");
    to_reverse = read_int("Please give a command: ");

    reverse = to_reverse == 2;
    auto to_print = this->srv.sort_by_criteria(criteria, reverse);
    std::cout << "\n";
    for(const auto& mv : to_print){
        std::cout << mv << '\n';
    }
    std::cout << "\n\n";
}

/*
 * Function which adds a new movie to the cart by name
 */
void UI::add_to_cart_ui(){
    string title;
    std::cout << "Please give the title of the movie: ";
    getline(std::cin, title);
    switch (this->srv.seacrh_movie_srv(title)){
        case true:{
            this->srv.add_movie_cart(title);
            std::cout << "\nMovie " + title + " was added!\n\n";
            break;
        }
        case false:{
            std::cout << "\nThere is no movie named " + title + "!\n\n";
        }
        default:
            break;
    }
}

/*
 * Function which deletes all movies from a cart
 */
void UI::delete_all_cart_ui(){
    this->srv.delete_all_cart_srv();
    std::cout << "\nThe cart was deleted!\n\n";
}

/*
 * Function to generate a random cart
 */

void UI::generate_cart_ui() {
    int number = read_int("Please give the number of movies to be added: ");
    if(number > this->srv.get_all_srv().size()){
        std::cout << "\nThere are not enough movies in the list!\n\n";
        return;
    }
    this->srv.generate_random_cart(number);
    std::cout << "\nThe cart was successfully generated!\n\n";
}

/*
 * Function which manages cart operations
 */
void UI::manage_cart(){
    string cart_menu;
    cart_menu += "\t 1. To add a movie to the cart\n"
                 "\t 2. To delete all the movies from the cart\n"
                 "\t 3. To generate a random cart\n"
                 "\t 4. To save the cart in CVS format\n"
                 "\t 5. To save the cart in HTML format\n";

    std::cout << cart_menu;
    int cmd = read_cmd();
    switch (cmd){
        case 1: {
            this->add_to_cart_ui();
            break;
        }
        case 2: {
            this->delete_all_cart_ui();
            break;
        }
        case 3: {
            this->generate_cart_ui();
            break;
        }
        case 4:{
            try {
                this->srv.export_cart_cvs("file_cvs.cvs");

            }catch(ValidatorException& ex){
                auto errs = ex.get_errors();
                print_errs(errs);
            }
            break;
        }
        case 5:{
            try {
                this->srv.export_cart_html("file_html.html");
            }catch(ValidatorException& ex){
                auto errs = ex.get_errors();
                print_errs(errs);
            }
            break;
        }
        default:
            std:: cout << "\nWrong command!!\n\n";
            break;
    }
}

/*
 * Function which displays the number of movies in the cart
 */
void UI::disply_num_cart(){
    std::cout << "\nThe number of movies in the cart is " << this->srv.get_all_cart().size() << "\n\n";
}

/*
 * Function which does an undo action
 */
void UI::make_undo(){
    try {
        this->srv.undo();
    }catch(UndoException& ex){
        std::cout << "\n\nCan't do more undo!!\n";
    }
}

/*
 * Function that controls the user's input
 * :param: -none
 */
void UI::show_ui(){
    int cmd;
    this->populate();
    while(true){
        this->disply_num_cart();
        this->print_menu();
        cmd = this->read_cmd();
        switch (cmd){
            case 0:
                this->print_all_movies();
                break;
            case 1:
                this->add_movie();
                break;
            case 2:
                this->del_movie();
                break;
            case 3:
                this->update_movie();
                break;
            case 4:
                this->filter_movies();
                break;
            case 5:
                this->sort_movies();
                break;
            case 6:
                this->manage_cart();
                break;
            case 7:
                this->make_undo();
                break;
            case 8:
                return;
            default:
                std::cout << "\nWrong command, try again!\n\n";
        }
    }
}
