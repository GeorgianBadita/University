#include <QApplication>
#include "gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto g = new GUI();
    g->show();
    return a.exec();
}
