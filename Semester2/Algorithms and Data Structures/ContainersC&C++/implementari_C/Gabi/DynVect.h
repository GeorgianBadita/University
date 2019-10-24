//
// Created by geo on 3/13/18.
//

#ifndef GABI_DYNVECT_H
#define GABI_DYNVECT_H

typedef void* TElem;

typedef struct {
    int dim;
    int capac;
    TElem* elems;
    int (*cmp)(TElem,TElem);
    void (*sterge)(TElem);
} DynVect;

DynVect* creeazaDynVect(int,int (*cmp)(TElem,TElem),void (*sterge)(TElem));

void adauga(DynVect*, TElem);
int cauta(DynVect*, TElem);
TElem sterge(DynVect*, TElem);

void distrugeDynVect(DynVect*);
#endif //GABI_DYNVECT_H

