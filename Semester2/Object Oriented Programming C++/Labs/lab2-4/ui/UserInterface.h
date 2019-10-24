//
// Created by geo on 3/16/18.
//

#ifndef LAB2_GENERIC_DYN_USERINTERFACE_H
#define LAB2_GENERIC_DYN_USERINTERFACE_H

#include "../service/Service.h"

typedef struct{
    Service* srv;
}UI;

/*
 * Function that creates a new user interface
 * :param Service: the service for the UI
 * :return: a new User Interface
 */
UI* createUI(Service* srv);


/*
 * Function that coordinates the menu
 * :param UI: user interface type
 * :return: -
 * post: -
 */
void showUI(UI*);

/*
 * Function that destroys all the data from the user interface
 * :param UI: the user interface we want to destroy
 */
void destroyUI(UI*);

#endif //LAB2_GENERIC_DYN_USERINTERFACE_H