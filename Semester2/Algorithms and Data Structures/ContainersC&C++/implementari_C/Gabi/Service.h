//
// Created by geo on 3/20/18.
//

#ifndef GABI_SERVICE_H
#define GABI_SERVICE_H

#include "Repo.h"

typedef struct {
    Repo* r;
}Service;

Service* creeazaService(Repo* r);
int adaugaFotbalist(Service*, int, char[50], char[50], double);
void distrugeService(Service*);
#endif //GABI_SERVICE_H
