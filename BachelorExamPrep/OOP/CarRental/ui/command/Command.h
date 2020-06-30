//
// Created by geo on 16.06.2020.
//

#ifndef CARRENTAL_COMMAND_H
#define CARRENTAL_COMMAND_H


#include "../../service/Service.h"

class Command {
private:
    Service &service;
public:
    explicit Command(Service &srv) : service(srv) {}

    virtual void execute() = 0;

    virtual ~Command() = default;
};


#endif //CARRENTAL_COMMAND_H
