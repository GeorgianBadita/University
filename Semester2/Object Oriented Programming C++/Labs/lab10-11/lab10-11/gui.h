#ifndef GUI_H
#define GUI_H
#include <QCoreApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QStringListModel>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QListWidget>
#include "service.h"
#include <QObject>
#include <QPainter>
#include "mylistmodel.h"
#include <observer.h>
#include <random>
#include <ctime>
#include <cstdlib>

class CartRdOnly : public QWidget, public Observer{
private:
    int num;
    Cart& cart;
public:
    explicit CartRdOnly(Cart& cart): cart{cart} {
        this->cart.add_observer(this);
        srand(time(NULL));
        this->setWindowTitle("Cart Read Only");
    }

protected:
    void paintEvent(QPaintEvent*) override{
       QPainter p{this};
       for(int i = 0; i<this->num; i++){
            int rand_fig = rand() % 3;
            int r_x1, r_y1, r_x2, r_y2;
            if(rand_fig == 0){

                r_x1 = rand() % 100;
                r_y1 = rand() % 100;
                r_x2 = rand() % 300;
                r_y2 = rand() % 300;
                p.drawLine(r_x1, r_y1, r_x2, r_y2);
            }else if(rand_fig == 1){
                r_x1 = rand() % 200;
                r_y1 = rand() % 200;
                r_x2 = rand() % 400;
                r_y2 = rand() % 400;
                p.drawEllipse(r_x1, r_y1, r_x2, r_y2);
            }else if(rand_fig == 2){
                r_x1 = rand() % 200;
                r_y1 = rand() % 200;
                r_x2 = rand() % 400;
                r_y2 = rand() % 400;
                p.drawRect(r_x1, r_y1, r_x2, r_y2);
            }
       }
    }

    void update() override{
        this->num = this->cart.get_all_from_cart().size();
        this->repaint();
    }
};


/*
 * Our GUI class
 */
class GUI : public QWidget, public Observer {
    Q_OBJECT
private:
    Service srv;
    QWidget* filter_type = new QWidget(); //filter widget
    QWidget* sort_type = new QWidget(); //sort widget
    QWidget* cart = new QWidget();      //cart widget
    QWidget* cart_add = new QWidget();      //cart add widget
    QWidget* cart_gen = new QWidget(); //cart gen widget
    QWidget* lst_widg = new QWidget();
    QListView* mvlst = new QListView();
    MyListModel* model;
    QListWidget* cart_lst = new QListWidget();
    QListWidget* lst = new QListWidget();
    QFormLayout* add_form = new QFormLayout();
    QPushButton* add_btn = new QPushButton("Add");
    QPushButton* del_btn = new QPushButton("Delete");
    QPushButton* updt_btn = new QPushButton("Update");
    QPushButton* undo_btn = new QPushButton("Undo");
    QPushButton* filter_btn = new QPushButton("Filter");
    QPushButton* sort_btn = new QPushButton("Sort");
    QPushButton* by_name_btn = new QPushButton("By name");
    QPushButton* by_year_btn = new QPushButton("By year");
    QPushButton* by_name_btn_srt = new QPushButton("By name");
    QPushButton* by_year_btn_srt = new QPushButton("By year");
    QPushButton* by_genre_btn = new QPushButton("By genre");
    QPushButton* by_actor_btn = new QPushButton("By actor");
    QPushButton* cart_btn = new QPushButton("Cart");
    QPushButton* add_cart_btn = new QPushButton("Add to Cart");
    QPushButton* delete_cart_btn = new QPushButton("Delete Cart");
    QPushButton* generate_cart_btn = new QPushButton("Generate cart");
    QPushButton* save_CVS_btn = new QPushButton("Save to CVS");
    QPushButton* save_HTML_btn = new QPushButton("Save to HTML");
    QPushButton* next_btn = new QPushButton("Next");
    QPushButton* gen_btn = new QPushButton("Generate");
    QPushButton* rd_only_cart = new QPushButton("Read only cart");
    QLineEdit* title_txt = new QLineEdit();
    QLineEdit* genre_txt = new QLineEdit();
    QLineEdit* year_txt = new QLineEdit();
    QLineEdit* actor_txt = new QLineEdit();
    QLineEdit* fltr_txt = new QLineEdit();
    QLineEdit* add_cart_txt = new QLineEdit();
    QLineEdit* gen_cart_txt = new QLineEdit();
    QLineEdit* cart_size_txt = new QLineEdit();
    //Function to set our interface
    void set_interface();

    /*
     * Function to draw the right side of the window
     */
    QWidget* make_right();

    /*
     * Function to draw the left side of the window
     */
    QWidget* make_left();

    /*
     * Function to add data to the app
     */
    void populate_data();

    /*
     * Function to show entries in the start of the application
     */
    void list_entries(QListWidget* lst, const vector<Movie>& mv_lst);

    /*
     * Function which handles the actions
     */
    void handle_actions();

    /*
     * Function to movie add handler
     */
    void on_add_click();

    /*
     * Function to movie delete handler
     */
    void on_delete_click();

    /*
     * Function for dislaying info in form when clicking list view rows
     */
    void on_list_view_click();

    /*
     * Function to movie update handler
     */
    void on_update_click();

    /*
     * Function which adds a new row
     */
    void add_new_row(QListWidget* lst, const Movie&);

    /*
     * Function for doing undo
     */
    void on_undo_click();

    /*
     * Function to filter rows
     */
    void on_filter_click();

    /*
     * Function to sort rows
     */
    void on_sort_click();

    /*
     * Function to filter by name
     */
    void on_by_name_f_click();

    /*
     * Function to filter by year
     */
    void on_by_year_f_click();

    /*
     * Function to set filter window
     */
    void set_filter_window();

    /*
     * Function to set filter list
     */
    void set_filter_list();

    /*
     * Function to set sorting window
     */
    void set_sort_window();

    /*
     * Function to sort by name
     */
    void on_by_name_s_click();

    /*
     * Function to sort by year
     */
    void on_by_year_s_click();

    /*
     * Function to sort by genre
     */
    void on_by_genre_s_click();

    /*
     * Function to sort by actor
     */
    void on_by_actor_s_click();

    /*
     * Function to open cart menu
     */
    void on_cart_click();

    /*
     * Function to set cart window
     */
    void set_cart();

    /*
     * Function to add a movie into the cart
     */
    void on_add_cart_click();

    /*
     * Function to delete a cart
     */
    void on_delete_cart_click();

    /*
     * Fimction to generate a random cart
     */
    void on_generate_cart_click();

    /*
     * Function to save cart in CVS file
     */
    void on_save_cvs_click();

    /*
     * Function to save cart in HTML file
     */
    void on_save_html_click();

    /*
     * Function to complete cart adding
     */
    void on_next_click();

    /*
     * Function to set cart generator interface
     */
    void set_cart_gen();

    /*
     * Function to generate a random cart
     */
    void on_gen_click();

    /*
     * Function to control cart size change
     */
    void on_cart_size_change();

    /*
     * Function to control rdOnlyCart
     */
    void on_rd_only_click();

    void update() override{
        this->list_entries(this->cart_lst, this->srv.get_all_cart());
    }

public:
    explicit GUI(Service& srv): srv{std::move(srv)}{
        this->srv.cart.add_observer(this);
        this->set_interface();
        this->populate_data();
        //this->list_entries(this->mvlst, this->srv.get_all_srv());
        this->handle_actions();
        this->model->setMovies(this->srv.get_all_srv());
    }


signals:
    void cart_value_changed(int new_size);
};


#endif // GUI_H
