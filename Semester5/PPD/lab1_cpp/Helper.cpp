//
// Created by georg on 10/12/2019.
//

#include "Helper.h"
#include <fstream>
#include <algorithm>

std::vector<int> Helper::readBigFromFile(std::string& file) {
    std::ifstream in(file);
    std::vector<int> rez;
    int x;
    while(in >> x){
        rez.push_back(x);
    }
    in.close();
    std::reverse(rez.begin(), rez.end());
    return rez;
}
