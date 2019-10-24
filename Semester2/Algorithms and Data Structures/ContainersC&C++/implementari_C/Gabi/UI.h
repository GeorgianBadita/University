//
// Created by geo on 3/20/18.
//

#ifndef GABI_UI_H
#define GABI_UI_H

#include "Service.h"

typedef struct {
    Service* s;
} UI;

UI* creeazaUI(Service* s);
void run(UI*);
void distrugeUI(UI*);
#endif //GABI_UI_H
