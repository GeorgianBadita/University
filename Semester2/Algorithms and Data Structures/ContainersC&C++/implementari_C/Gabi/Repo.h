//
// Created by geo on 3/20/18.
//

#ifndef GABI_REPO_H
#define GABI_REPO_H
#include "DynVect.h"
#include "Fotbalist.h"

typedef Fotbalist* TElem;

typedef struct {
    DynVect* v;
} Repo;

Repo* creeazaRepo();
adaugaElem(Repo*,TElem);
void distrugeRepo(Repo*);
#endif //GABI_REPO_H
