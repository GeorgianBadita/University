//
// Created by geo on 3/20/18.
//

#ifndef GABI_FOTBALIST_H
#define GABI_FOTBALIST_H
typedef struct {
    int id;
    char nume[50];
    char echipa[50];
    double valoare;
}Fotbalist;

Fotbalist* creeazaFotbalist(int,char[50],char[50],double);
int getId(Fotbalist*);
void getNume(Fotbalist*,char nume[50]);
#endif //GABI_FOTBALIST_H
