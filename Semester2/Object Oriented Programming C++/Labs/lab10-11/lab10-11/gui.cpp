#include "gui.h"
#include "helper.h"
#include <iostream>



/*
 * Function for doing undo
 */
void GUI::on_undo_click(){
    connect(this->undo_btn, &QPushButton::clicked, this, [=](){
        QMessageBox* msg = new QMessageBox(0);
        msg->setWindowTitle("Alert!");
        try {
            this->srv.undo();
            //this->list_entries(this->mvlst, this->srv.get_all_srv());
            this->model->setMovies(this->srv.get_all_srv());
        }catch(UndoException& ex){
            msg->setText("Can't do more undo!");
            msg->exec();
        }
    });
}


/*
 * Function for dislaying info in form when clicking list view rows
 */
void GUI::on_list_view_click(){
     connect(this->mvlst, &QListView::clicked, this, [=](){
         QModelIndex index = this->mvlst->currentIndex();

         int row = index.row();
         if(row < 0){
             //this->del_btn->setText("Delete");
             return;
         }
         std::string movie_str = index.sibling(row, 0).data().toString().toStdString();
         auto mv_lst = this->srv.get_all_srv();
         Movie mv;
         for(const auto& mmv : mv_lst){
             if(mmv.get_title() == movie_str){
                 mv = mmv;
                 break;
             }
         }
         QString title = QString::fromStdString(mv.get_title());
         QString genre = QString::fromStdString(mv.get_genre());
         QString year = QString::number(mv.get_year());
         QString actor = QString::fromStdString(mv.get_main_actor());
         this->title_txt->setText(title);
         this->genre_txt->setText(genre);
         this->year_txt->setText(year);
         this->actor_txt->setText(actor);
         this->del_btn->setText("Delete " + title);

     });
}


/*
 * Function to movie update handler
 */
void GUI::on_update_click(){
    QMessageBox* msg = new QMessageBox(0);
    msg->setWindowTitle("Alert");
    connect(this->updt_btn, &QPushButton::clicked, this, [=](){
        std::string title = this->title_txt->text().toStdString();
        std::string genre = this->genre_txt->text().toStdString();
        int year = this->year_txt->text().toInt();
        std::string main_actor = this->actor_txt->text().toStdString();

        try {
            auto mv = this->srv.update_movie_srv(title, genre, year, main_actor);
            if (mv.get_year() < 0) {
                msg->setText("The movie doesn't exist!");
                msg->exec();
                std::cout << "\nThe movie doesn't exist!\n";
            } else {
                msg->setText("The movie " + QString::fromStdString(mv.get_title()) + " was updated!");
                msg->exec();
            }
        }catch (ValidatorException& ex){
            auto errors = ex.get_errors();
            std::string str;
            for(const auto& err :errors){
                str += err;
            }
            msg->setText(QString::fromStdString(str));
            msg->exec();
        }

    });
}

/*
 * Function which adds a movie
 */
void GUI::on_add_click(){
    QMessageBox* msg = new QMessageBox(0);
    msg->setWindowTitle("Alert");
    connect(this->add_btn, &QPushButton::clicked, this, [=](){
        std::string title = this->title_txt->text().toStdString();
        std::string genre = this->genre_txt->text().toStdString();
        int year = this->year_txt->text().toInt();
        std::string actor = this->actor_txt->text().toStdString();
        try {
            this->srv.add_movie_srv(title, genre, year, actor);
            //this->list_entries(this->mvlst, this->srv.get_all_srv());
            this->model->setMovies(this->srv.get_all_srv());
        }catch (ValidatorException& ex){
            auto errors = ex.get_errors();
            std::string str;
            for(const auto& elem : errors){
                str += elem;
            }
            msg->setText(QString::fromStdString(str));
            msg->exec();
        }catch (RepositoryException& ex){
            msg->setText("The movie already exits!");
            msg->exec();
        }
    });
}


/*
 * Function to delete a movie
 */
void GUI::on_delete_click(){
    QMessageBox* msg = new QMessageBox(0);
    msg->setWindowTitle("Alert");
    connect(this->del_btn, &QPushButton::clicked, this, [=](){
        QModelIndex index = this->mvlst->currentIndex();
        int row = index.row();
        if(row < 0){
            return;
        }
        std::string movie_str = index.sibling(row, 0).data().toString().toStdString();
        auto mv_lst = this->srv.get_all_srv();
        Movie mv;
        for(const auto& mmv : mv_lst){
            if(mmv.get_title() == movie_str){
                mv = mmv;
                break;
            }
        }
        std::string title = mv.get_title();
        std::string genre = mv.get_genre();
        int year = mv.get_year();
        std::string actor = mv.get_main_actor();
        try {
            auto mv = this->srv.del_movie_srv(title, genre, year, actor);
            if(mv.get_year() < 0){
                msg->setText("The movie doesn't exist!");
                msg->exec();
            }else{
                //this->list_entries(this->mvlst, this->srv.get_all_srv());
                  this->model->setMovies(this->srv.get_all_srv());
 //               this->del_btn->setText("Delete");
            }
        }catch (ValidatorException& ex){
            auto errors = ex.get_errors();
            std::string str;
            for(const auto& elem : errors){
                str += elem;
            }
            msg->setText(QString::fromStdString(str));
            msg->exec();
        }
    });
}


/*
 * Function to filter rows
 */
void GUI::on_filter_click(){
    connect(this->filter_btn, &QPushButton::clicked, this, [=](){
        this->filter_type->show();
    });
}

/*
 * Function to filter by name
 */

void GUI::on_by_name_f_click(){
    connect(this->by_name_btn, &QPushButton::clicked, this, [=](){
        this->filter_type->close();
        std::string fltr_text = this->fltr_txt->text().toStdString();
        auto mv_lst = this->srv.filter_by_title_srv(fltr_text);
        this->list_entries(this->lst, mv_lst);
        this->lst_widg->show();
    });
}

/*
 * Function to filter by year
 */
void GUI::on_by_year_f_click(){
    connect(this->by_year_btn, &QPushButton::clicked, this, [=](){
       this->filter_type->close();
        int year = this->fltr_txt->text().toInt();
        auto mv_lst = this->srv.filter_by_year_srv(year);
        this->list_entries(this->lst, mv_lst);
        this->lst_widg->show();
    });
}


/*
 * Function to sort rows
 */
void GUI::on_sort_click(){
    connect(this->sort_btn, &QPushButton::clicked, this, [=](){
        this->sort_type->show();
    });
}

/*
 * Function to sort by name
 */
void GUI::on_by_name_s_click(){
    connect(this->by_name_btn_srt, &QPushButton::clicked, this, [=](){
        this->sort_type->close();
        int ret = QMessageBox::information(this->sort_type, "Sorting order?", "Do you want to sort descending?",
                                           QMessageBox::Yes | QMessageBox::No);
        if(ret == QMessageBox::Yes){
            auto mv_lst = this->srv.sort_by_criteria(1, 1);
            this->list_entries(this->lst, mv_lst);
            this->lst_widg->show();
        }
        else{
            auto mv_lst = this->srv.sort_by_criteria(1, 0);
            this->list_entries(this->lst, mv_lst);
            this->lst_widg->show();
        }
    });
}

/*
 * Function to sort by year
 */
void GUI::on_by_year_s_click(){
    connect(this->by_year_btn_srt, &QPushButton::clicked, this, [=](){
        this->sort_type->close();
        int ret = QMessageBox::information(this->sort_type, "Sorting order?", "Do you want to sort descending?",
                                           QMessageBox::Yes | QMessageBox::No);
        if(ret == QMessageBox::Yes){
            auto mv_lst = this->srv.sort_by_criteria(3, 1);
            this->list_entries(this->lst, mv_lst);
            this->lst_widg->show();
        }
        else{
            auto mv_lst = this->srv.sort_by_criteria(3, 0);
            this->list_entries(this->lst, mv_lst);
            this->lst_widg->show();
        }
    });
}

/*
 * Function to sort by genre
 */
void GUI::on_by_genre_s_click(){
    connect(this->by_genre_btn, &QPushButton::clicked, this, [=](){
        this->sort_type->close();
        int ret = QMessageBox::information(this->sort_type, "Sorting order?", "Do you want to sort descending?",
                                           QMessageBox::Yes | QMessageBox::No);
        if(ret == QMessageBox::Yes){
            auto mv_lst = this->srv.sort_by_criteria(2, 1);
            this->list_entries(this->lst, mv_lst);
            this->lst_widg->show();
        }
        else{
            auto mv_lst = this->srv.sort_by_criteria(2, 0);
            this->list_entries(this->lst, mv_lst);
            this->lst_widg->show();
        }
    });
}

/*
 * Function to sort by actor
 */
void GUI::on_by_actor_s_click(){
    connect(this->by_actor_btn, &QPushButton::clicked, this, [=](){
        this->sort_type->close();
        int ret = QMessageBox::information(this->sort_type, "Sorting order?", "Do you want to sort descending?",
                                           QMessageBox::Yes | QMessageBox::No);
        if(ret == QMessageBox::Yes){
            auto mv_lst = this->srv.sort_by_criteria(4, 1);
            this->list_entries(this->lst, mv_lst);
            this->lst_widg->show();
        }
        else{
            auto mv_lst = this->srv.sort_by_criteria(4, 0);
            this->list_entries(this->lst, mv_lst);
            this->lst_widg->show();
        }
    });
}

/*
 * Function which handles the actions
 */
void GUI::handle_actions(){
    on_list_view_click();
    on_add_click();
    on_delete_click();
    on_update_click();
    on_undo_click();
    on_filter_click();
    on_sort_click();
    on_by_name_f_click();
    on_by_year_f_click();
    on_by_name_s_click();
    on_by_year_s_click();
    on_by_genre_s_click();
    on_by_actor_s_click();
    on_cart_click();
    on_add_cart_click();
    on_delete_cart_click();
    on_generate_cart_click();
    on_save_cvs_click();
    on_save_html_click();
    on_next_click();
    on_gen_click();
    on_cart_size_change();
    on_rd_only_click();
}

/*
 * Function to control rdOnlyCart
 */
void GUI::on_rd_only_click(){
    connect(this->rd_only_cart, &QPushButton::clicked, this, [&](){
        CartRdOnly* cart = new CartRdOnly(this->srv.cart);
        cart->show();
    });
}

/*
 * Function to construct the right side of the window
 */
QWidget* GUI::make_right(){
    QWidget* details = new QWidget();
    details->setLayout(this->add_form);
    QLabel* lbl_title = new QLabel("Title:");
    QLabel* lbl_genre = new QLabel("Genre:");
    QLabel* lbl_year = new QLabel("Year:");
    QLabel* lbl_actor = new QLabel("Main Actor:");

    this->add_form->addRow(lbl_title, this->title_txt);
    this->add_form->addRow(lbl_genre, this->genre_txt);
    this->add_form->addRow(lbl_year, this->year_txt);
    this->add_form->addRow(lbl_actor, this->actor_txt);

    QVBoxLayout* vL = new QVBoxLayout();
    QHBoxLayout* hL = new QHBoxLayout();
    QWidget* sub_form_btns = new QWidget();
    sub_form_btns->setLayout(hL);
    hL->addWidget(this->add_btn);
    hL->addWidget(this->updt_btn);
    hL->addWidget(this->cart_btn);
    hL->addWidget(this->rd_only_cart);
    vL->addWidget(details);
    vL->addWidget(sub_form_btns);

    QWidget* right_side = new QWidget();
    right_side->setLayout(vL);

    /*
     * setting buttons
     */
    return right_side;
}

/*
 * Function to construct the left side of the window
 */
QWidget* GUI::make_left(){
    QWidget* left_side = new QWidget();
    QHBoxLayout* hL = new QHBoxLayout();
    QVBoxLayout* vL = new QVBoxLayout();
    QWidget* sub_lst_btns = new QWidget();
    QLabel* cart_size_lbl = new QLabel("Number of items in cart:");
    sub_lst_btns->setLayout(hL);
    hL->addWidget(this->del_btn);
    hL->addWidget(this->undo_btn);
    hL->addWidget(this->filter_btn);
    hL->addWidget(this->sort_btn);
    hL->addWidget(cart_size_lbl);
    hL->addWidget(this->cart_size_txt);
    this->cart_size_txt->setReadOnly(true);
    this->cart_size_txt->setText("0");
    left_side->setLayout(vL);
    vL->addWidget(this->mvlst);
    vL->addWidget(sub_lst_btns);


    /*
     * Setting buttons and properties
     */
    this->mvlst->setEditTriggers(QAbstractItemView::NoEditTriggers);

    return left_side;
}

/*
 * Function to set filter window
 */
void GUI::set_filter_window(){
    QWidget* my_widg = new QWidget();   //intermediate widget
    QLabel* lbl  = new QLabel("Chose filter type:"); //text label
    QHBoxLayout* hL = new QHBoxLayout();    //horizontal Layout
    QVBoxLayout* vL = new QVBoxLayout();    //vertical Layout
    hL->addWidget(this->by_name_btn);       //name button on hLayout
    hL->addWidget(this->by_year_btn);       //year button on hLayout
    this->filter_type->setWindowTitle("Filter type"); //set wdiget title as "Filter type"
    my_widg->setLayout(hL);
    vL->addWidget(lbl);             //unite components
    vL->addWidget(this->fltr_txt);
    vL->addWidget(my_widg);
    this->filter_type->setLayout(vL);
}

/*
 * Function to set sorting window
 */
void GUI::set_sort_window(){
    QWidget* my_widg_srt = new QWidget();   //intermediate widget
    QLabel* lbl_srt  = new QLabel("Choose sorting type:"); //text label
    QHBoxLayout* hL = new QHBoxLayout();    //horizontal Layout
    QVBoxLayout* vL = new QVBoxLayout();    //vertical Layout
    hL->addWidget(this->by_name_btn_srt);       //name button on hLayout
    hL->addWidget(this->by_year_btn_srt);       //year button on hLayout
    hL->addWidget(this->by_genre_btn);
    hL->addWidget(this->by_actor_btn);
    this->sort_type->setWindowTitle("Filter type"); //set wdiget title as "Filter type"
    my_widg_srt->setLayout(hL);
    vL->addWidget(lbl_srt);             //unite components
    vL->addWidget(my_widg_srt);
    this->sort_type->setLayout(vL);
}

/*
 * Function to set the filter list
 */
void GUI::set_filter_list(){
    QHBoxLayout* hL = new QHBoxLayout();
    hL->addWidget(lst);
    this->lst_widg->setWindowTitle("Movie list");
    this->lst_widg->setLayout(hL);
}



/*
 * Function to add data to the app
 */
void GUI::populate_data(){
    this->srv.add_movie_srv("Titanic", "Drama", 1993, "Leonardo DiCaprio");
    this->srv.add_movie_srv("The Godfather I", "Action", 1972, "Al Pacino");
    this->srv.add_movie_srv("The Godfather II", "Action", 1974, "Al Pacino");
    this->srv.add_movie_srv("The man who knew infinity", "Drama", 2013, "Dev Patel");
    this->srv.add_movie_srv("The martian", "Sci-Fi", 2016, "Matt Damon");
}

/*
 * Function to set the initial properties of the interface
 */
void GUI::set_interface(){
    this->model = new MyListModel(this->srv.get_all_srv());
    this->mvlst->setModel(model);
    auto right = this->make_right();
    auto left = this->make_left();
    auto hL = new QHBoxLayout();
    this->setLayout(hL);
    hL->addWidget(left);
    hL->addWidget(right);
    this->setWindowTitle("Movie application");
    this->set_filter_window();
    this->set_filter_list();
    this->set_sort_window();
    this->set_cart();
    this->set_cart_gen();
}


/*
 * Function which adds a new row in the table
 * :param mv: movie to be added in the table
 */
void GUI::add_new_row(QListWidget *lst, const Movie& mv){
    QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(mv.get_title()), lst);
}


/*
 * Function to show entries in the start of the application
 */
void GUI::list_entries(QListWidget *lst, const vector<Movie> &mv_lst){
    lst->clear();
    for(const auto& mv : mv_lst){
        add_new_row(lst, mv);
    }
}

/*
 * Function to open the cart menu
 */
void GUI::on_cart_click(){
    connect(this->cart_btn, &QPushButton::clicked, this, [=](){
        this->cart->show();
    });
}

/*
 * Function to add a movie into the cart
 */
void GUI::on_add_cart_click(){
    connect(this->add_cart_btn, &QPushButton::clicked, this, [=](){
       this->cart_add->show();
    });
}

/*
 *
 */
void GUI::on_next_click(){
    connect(this->next_btn, &QPushButton::clicked, this, [=](){
        std::string title = this->add_cart_txt->text().toStdString();
        switch(this->srv.seacrh_movie_srv(title)){
            case true:
                try{
                    this->srv.add_movie_cart(title);
                    this->list_entries(this->cart_lst, this->srv.get_all_cart());
                    QMessageBox::information(this->cart_add, "Info", "Movie " + QString::fromStdString(title) + " was added!", QMessageBox::Ok);
                    emit(this->cart_value_changed(this->srv.get_all_cart().size()));
                }catch(CartException& ex){
                    QMessageBox::information(this->cart_add, "Alert!", "Movie already in cart", QMessageBox::Ok);
                }
                break;
            case false:
                QMessageBox::information(this->cart_add, "Alert!", "No Movie found", QMessageBox::Ok);
                break;
        }
        this->add_cart_txt->clear();
        this->cart_add->close();
    });
}

/*
 * Function to delete a cart
 */
void GUI::on_delete_cart_click(){
    connect(this->delete_cart_btn, &QPushButton::clicked, this, [=](){
        this->srv.delete_all_cart_srv();
        this->list_entries(this->cart_lst, this->srv.get_all_cart());
        QMessageBox::information(this->cart_add, "Info", "All movies from the cart were deleted!", QMessageBox::Ok);
        emit(this->cart_value_changed(0));
    });
}

/*
 * Fimction to generate a random cart
 */
void GUI::on_generate_cart_click(){
    connect(this->generate_cart_btn, &QPushButton::clicked, this, [=](){
        this->cart_gen->show();
    });
}

/*
 * Function to save cart in CVS file
 */
void GUI::on_save_cvs_click(){
    connect(this->save_CVS_btn, &QPushButton::clicked, this, [=](){
        QMessageBox* msg = new QMessageBox();
        try {

            this->srv.export_cart_cvs("file_csv.csv");
            msg->setWindowTitle("Success!");
            msg->setText("The cart was saved as a CVS file!");
            msg->exec();

        }catch(ValidatorException& ex){
            auto errs = ex.get_errors();
            std::string str;
            for(auto& err : errs){
                str += err;
            }
            msg->setWindowTitle("Alert!");
            msg->setText(QString::fromStdString(str));
            msg->exec();
        }
    });
}

/*
 * Function to save cart in HTML file
 */
void GUI::on_save_html_click(){
    connect(this->save_HTML_btn, &QPushButton::clicked, this, [=](){
        QMessageBox* msg = new QMessageBox();
        try {
            this->srv.export_cart_html("file_html.html");
            msg->setWindowTitle("Success!");
            msg->setText("The cart was saved as a HTML file!");
            msg->exec();

        }catch(ValidatorException& ex){
            auto errs = ex.get_errors();
            std::string str;
            for(auto& err : errs){
                str += err;
            }
            msg->setWindowTitle("Alert!");
            msg->setText(QString::fromStdString(str));
            msg->exec();
        }
    });

}


/*
 * Function to set cart window
 */
void GUI::set_cart(){
    QHBoxLayout* hL = new QHBoxLayout();
    QVBoxLayout* vL = new QVBoxLayout();
    QLabel* lbl = new QLabel("Select option:");
    QWidget* inter_widg = new QWidget();
    hL->addWidget(this->add_cart_btn);
    hL->addWidget(this->delete_cart_btn);
    hL->addWidget(this->generate_cart_btn);
    hL->addWidget(this->save_CVS_btn);
    hL->addWidget(this->save_HTML_btn);
    inter_widg->setLayout(hL);
    vL->addWidget(this->cart_lst);
    vL->addWidget(lbl);
    vL->addWidget(inter_widg);
    this->cart->setWindowTitle("Cart Options");
    this->cart->setLayout(vL);
    QVBoxLayout* vL_add = new QVBoxLayout();
    QLabel* lbl_add = new QLabel("Give the title of the movie to be added:");
    vL_add->addWidget(lbl_add);
    vL_add->addWidget(this->add_cart_txt);
    vL_add->addWidget(this->next_btn);
    this->cart_add->setWindowTitle("Cart Add");
    this->cart_add->setLayout(vL_add);
}


/*
 * Function to set cart generator interface
 */
void GUI::set_cart_gen(){
    QVBoxLayout* vL = new QVBoxLayout();
    QLabel* lbl = new QLabel();
    this->cart_gen->setWindowTitle("Cart Generator");
    lbl->setText("Give the number of items from cart");
    vL->addWidget(lbl);
    vL->addWidget(this->gen_cart_txt);
    vL->addWidget(this->gen_btn);
    this->cart_gen->setLayout(vL);
}


/*
 * Function to generate a random cart
 */
void GUI::on_gen_click(){
    connect(this->gen_btn, &QPushButton::clicked, this, [=](){
        QMessageBox* msg = new QMessageBox(0);
        msg->setWindowTitle("Warning!");
        int number = this->gen_cart_txt->text().toInt();
        if(number > this->srv.get_all_srv().size()){
            msg->setText("There are not enough movies in the list!");
            msg->exec();
            return;
        }
        this->srv.generate_random_cart(number);
        this->list_entries(this->cart_lst, this->srv.get_all_cart());
        emit(this->cart_value_changed(this->srv.get_all_cart().size()));
        msg->setText("The cart was successfully generated!");
        msg->exec();
    });
}

/*
 * Function to update cart state
 */
void GUI::on_cart_size_change(){
    connect(this, &GUI::cart_value_changed, this, [=](){
        int size = this->srv.get_all_cart().size();

        this->cart_size_txt->setText(QString::number(size));
    });
}
