//
// Created by geo on 15.06.2020.
//

#ifndef CARRENTAL_MYEXCEPTION_H
#define CARRENTAL_MYEXCEPTION_H

#include <utility>
#include <vector>
#include <string>
#include <ostream>

class MyException : std::exception {
private:
    std::vector<std::string> errors;
public:
    /**
     * Constructor for MyException
     * @param errs - Exception errors
     */
    explicit MyException(std::vector<std::string> errs) : errors(std::move(errs)) {}

    friend std::ostream &operator<<(std::ostream &os, const MyException &exc) {
        for (const auto &err: exc.getExceptions()) {
            os << err + '\n';
        }
        return os;
    }

    std::vector<std::string> getExceptions() const {
        return this->errors;
    }
};


#endif //CARRENTAL_MYEXCEPTION_H
