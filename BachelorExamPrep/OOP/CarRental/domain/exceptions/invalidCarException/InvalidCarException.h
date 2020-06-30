//
// Created by geo on 15.06.2020.
//

#ifndef CARRENTAL_INVALIDCAREXCEPTION_H
#define CARRENTAL_INVALIDCAREXCEPTION_H


#include <utility>

#include "../MyException.h"

class InvalidCarException : public MyException {
public:
    InvalidCarException(std::vector<std::string> errs) :
            MyException(std::move(errs)) {}
};


#endif //CARRENTAL_INVALIDCAREXCEPTION_H
