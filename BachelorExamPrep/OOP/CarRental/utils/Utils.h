//
// Created by geo on 16.06.2020.
//

#ifndef CARRENTAL_UTILS_H
#define CARRENTAL_UTILS_H

#include <string>
#include <iostream>

class Utils {
public:
    static char readCmd() {
        while (true) {
            std::cout << "Please choose a command: ";
            std::string cmd;
            std::cin >> cmd;
            if (cmd.size() == 1 && (cmd[0] == 'x' || (cmd[0] - '0' >= 0 && cmd[0] - '0' <= 9))) {
                return cmd[0];
            } else {
                std::cout << "Invalid command, please try again...";
            }
        }
    }
};


#endif //CARRENTAL_UTILS_H
