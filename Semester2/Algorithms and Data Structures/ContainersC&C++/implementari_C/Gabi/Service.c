//
// Created by geo on 3/20/18.
//

#include <stdlib.h>
#include "Service.h"
#include "Fotbalist.h"

Service* creeazaService(Repo* r){
    Service* s = (Service*)malloc(sizeof(Service));
    s->r = r;
    return s;
}

int adaugaFotbalist(Service* s, int id, char nume[50], char echipa[50], double valoare){
    Fotbalist* f = creeazaFotbalist(id,nume,echipa,valoare);

}

void distrugeService(Service* s){
    distrugeRepo(s->r);
    free(s);
}