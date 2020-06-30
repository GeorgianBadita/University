//
// Created by geo on 16.06.2020.
//

#ifndef CARRENTAL_UI_H
#define CARRENTAL_UI_H


#include "../service/Service.h"
#include "../utils/Utils.h"

class UI {
private:
    Service &srv;

    void showMenu() {
        std::string menu;
        menu += "========== MENU ==========\n";
        menu += "1. Add Car\n";
        menu += "2. Update Car\n";
        menu += "3. Delete Car\n";
        menu += "4. Filter by producer\n";
        menu += "5. Filter by type\n";
        menu += "6. Sort by car's number\n";
        menu += "7. Sort by car's producer\n";
        menu += "x. To exit\n\n";
    }

public:
    explicit UI(Service &srv) : srv(srv) {};

    void showUI() {
        while (true) {
            this->showMenu();
            char cmd = Utils::readCmd();
            switch (cmd) {
                case 'x':
                    return;
                default:
                    continue;
            }
        }
    }
};


#endif //CARRENTAL_UI_H
