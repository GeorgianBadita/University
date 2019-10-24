//
// Created by geo on 3/20/18.
//

#include "Tests.h"
#include "Fotbalist.h"
#include <string.h>
void testDomain(){
    int id =1;
    char nume[50];
    strcpy(nume,"gigi");
    char echipa[50];
    strcpy(echipa,"fcsb");
    double valoare= 900.1;
    Fotbalist* f = creeazaFotbalist(id,nume,echipa,valoare);
    assert(getId(f)==1);
    char fnume[50];
    getNume(f,fnume);
    assert(strcmp(nume,fnume)==0);
}