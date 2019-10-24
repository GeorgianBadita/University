//
// Created by geo on 3/13/18.
//
#include "DynVect.h"
#include <stdlib.h>

DynVect* creeazaDynVect(int capac,int (*cmp)(TElem,TElem),void (*sterge)(TElem)){
    DynVect* vect = (DynVect*)malloc(sizeof(DynVect));
    vect->capac =capac;
    vect->dim = 0;
    vect->cmp = cmp;
    vect->sterge = sterge;
    vect->elems = (TElem*)malloc(sizeof(TElem)*capac);
    return vect;
}

void resize(DynVect* dv){
    int ndim = dv->dim*2;
    TElem* nelems= malloc(sizeof(TElem)*ndim);
    int i=0;
    for (;i<dv->dim;i++)
        nelems[i]= dv->elems[i];
    free(dv->elems);
    dv->elems = nelems;
    dv->capac =ndim;
}

void adauga(DynVect* dv, TElem el){
    if (dv->dim == dv->capac)
        resize(dv);
    dv->elems[dv->dim]=el;
    dv->dim++;
}

int cauta(DynVect* dv, TElem el){
    int i=0;
    for(;i<dv->dim;i++){
        if (dv->cmp(dv->elems[i],el)==0)
            return i;
    }
    return -1;
}

TElem sterge(DynVect* dv, TElem el){
    int pos = cauta(dv,el);
    if (pos<0){
        return 0;
    }
    int i=pos;
    TElem e = dv->elems[pos];
    for (;i<dv->dim-1;i++)
        dv->elems[i]=dv->elems[i+1];
    dv->dim--;
    dv->sterge(e);
    return e;
}

void distrugeDynVect(DynVect* vect){
    free(vect->elems);
    free(vect);
}
