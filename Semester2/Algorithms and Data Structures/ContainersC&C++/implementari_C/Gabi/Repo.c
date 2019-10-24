//
// Created by geo on 3/20/18.
//

#include <stddef.h>
#include <stdlib.h>
#include "Repo.h"
Repo* creeazaRepo(){
    Repo *repo = (Repo*)malloc(sizeof(Repo));
    repo->v = creeazaDynVect(3,NULL,NULL);
}

void distrugeRepo(Repo* r){
    distrugeDynVect(r->v);
    free(r);
}