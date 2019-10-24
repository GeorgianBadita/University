//
// Created by geo on 3/20/18.
//

#include <string.h>
#include <stdlib.h>
#include "Fotbalist.h"
Fotbalist* creeazaFotbalist(int id,char nume[50],char echipa[50],double valoare){
    Fotbalist* f = (Fotbalist*)malloc(sizeof(Fotbalist));
    f->id =id;
    strcpy(f->nume,nume);
    strcpy(f->echipa,echipa);
    f->valoare = valoare;
    return f;
}

int getId(Fotbalist* f){
    return f->id;
}
void getNume(Fotbalist* f,char nume[50]){
    strcpy(nume,f->nume);
}