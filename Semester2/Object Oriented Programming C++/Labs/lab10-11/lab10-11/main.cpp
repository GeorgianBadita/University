#include "tests.h"
#include "repository.h"
#include "service.h"
#include "user_interface.h"
#include "gui.h"
#include "helper.h"
#include <QtWidgets/QApplication>

int main(int argv, char **args) {
    QApplication app(argv, args);
    Tests my_tests;
    MovieValidator mv_validator;
    my_tests.run_tests();
    RepoFile repo(mv_validator, "movies.txt");
    Service srv = Service(repo);
    //UI ui = UI(srv);
    //ui.show_ui();

    auto gui = new GUI(srv);
    gui->show();

    return app.exec();
}
