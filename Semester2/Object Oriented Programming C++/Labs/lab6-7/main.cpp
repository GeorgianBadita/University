#include "utils/tests.h"
#include "repositroy/repository.h"
#include "service/service.h"
#include "ui/user_interface.h"


int main() {
    Tests my_tests;
    MovieValidator mv_validator;
    my_tests.run_tests();
    Repository repo(mv_validator);
    Service srv = Service(repo);
    UI ui = UI(srv);
    ui.show_ui();
    return 0;
}