#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#include "gui.h"
#include <QPixmap>
#include <QPalette>
#include <QPainter>
#include <QWidget>
#include <QVBoxLayout>
#include <QLayout>
#include <QFont>
#include <QDebug>
#include <stdlib.h>
#include <windows.h>
#include <tchar.h>

void GUI::set_interface(){
 //   SuperBackgroundPainter blah(":/res/background.jpg");
    this->setWindowState(Qt::WindowFullScreen);
    QPixmap bkgd("C:\\Users\\Geo\\Desktop\\MegaHack\\interfata.jpg");
    bkgd = bkgd.scaled(this->size(), Qt::KeepAspectRatioByExpanding);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgd);
    this->setPalette(palette);

    //auto lyt = new QGridLayout();
    //lyt->addWidget(this->prt_fizic_btn);
    //lyt->addWidget(this->elect_btn);

    //this->prt_fizic_btn->setGeometry(100, 100, 10, 10);

    //this->elect_btn->setGeometry(200, 100, 100, 100);
    //this->setLayout(lyt);
    //lyt->addWidget(this->prt_fizic_btn,1,1,1,1);
   // this->prt_fizic_btn->move(780,600);
   // this->prt_fizic_btn->resize(340,50);

    this->elect_btn->move(780, 530);
    this->elect_btn->resize(340, 50);

    //this->prt_fizic_btn->setStyleSheet("background-color: rgb(0, 149, 96); color: rgb(255, 255, 255);");
    this->elect_btn->setStyleSheet("background-color: rgb(0, 149, 96); color: rgb(255, 255, 255);");

    QFont font = this->elect_btn->font();
    font.setPointSize(14);
    this->elect_btn->setFont(font);
    //this->prt_fizic_btn->setFont(font);
}

void GUI::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap("C:\\Users\\Geo\\Desktop\\MegaHack\\interfata.jpg").scaled(size()));
    QWidget::paintEvent(e);
}


void GUI::set_connects(){
    connect(elect_btn, &QPushButton::pressed, this, [=](){

        int val = system("C://platform-tools//sendToPhone C:\\Users\\Geo\\Desktop\\thebook.pdf /sdcard/Android/data/com.example.dragos.observerr/files");
        if(val == -1){
            qDebug() << "NE BAROS :(\n";
        }
        else{
            qDebug() << "BAROS\n";
        }
    });
}


