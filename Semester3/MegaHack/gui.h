#ifndef GUI_H
#define GUI_H
#include <QCoreApplication>
#include <QWidget>
#include <QPushButton>

class GUI : public QWidget{
private:
    //QPushButton* prt_fizic_btn = new QPushButton(this);
    QPushButton* elect_btn = new QPushButton(this);
    void set_interface();
    void set_connects();

public:
    GUI(){
      //  this->prt_fizic_btn->setText("EMITERE BON");
        this->elect_btn->setText("EMITERE BON FISCAL ELECTRONIC");
        this->set_interface();
        this->set_connects();
    }
protected:
void paintEvent(QPaintEvent *e) override;
};

#endif // GUI_H
