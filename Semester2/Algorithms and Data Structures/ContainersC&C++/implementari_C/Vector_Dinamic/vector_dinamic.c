//
// Created by geo on 3/11/18.
//

#include "vector_dinamic.h"
#include <malloc.h>


VectorDinamic* creeaza(int cp){
    VectorDinamic* v = (VectorDinamic*)malloc(sizeof(VectorDinamic));
    //setam capacitatea
    v->cp = cp;

    //alocam spatiu pentru vector
    v->e = (TElem*)malloc(sizeof(TElem));

    //seteaza numarul de elemente
    v->n = 0;

    return v;
}


void distruge(VectorDinamic* v){
    //elibereaza spatiul de memorie

    free(v->e);
    free(v);
}


void redim(VectorDinamic* v) {
    //realocam spatiu de memorie de capacitate dubla

    TElem* e_nou = (TElem*)malloc(2 * v->cp * sizeof(TElem));
    //copiem vechiile valor in noua zona

    int i;
    for(i = 0; i<v->n; i++) {
        e_nou[i] = v->e[i];
    }
    //dublam capacitatea

    v->cp *= 2;
    //eliberam vechea zona
    free(v->e);

    //vectorul indica spre zona noua
    v->e = e_nou;

}

int dim(VectorDinamic* v){
    return v->n;
}


TElem element(VectorDinamic* v, int pos){
    return v->e[pos - 1];
}


void adauga_sfarsit(VectorDinamic* v, TElem e){
    if(v->cp == v->n) {
        redim(v);
    }

    v->e[(v->n)++] = e;
}


//ALTE OPERATII
//....

Iterator* creeaza_iterator(VectorDinamic* v) {
    //alocam spatiu de memorie pentru iterator
    Iterator* iterator = (Iterator*)malloc(sizeof(Iterator));
    //setam componentele iteratorului
    iterator->v = v;
    iterator->curent = 0;

    return iterator;
}

Iterator* iteratorV(VectorDinamic* v){
    //returneaza iteratorul pe vector
    return creeaza_iterator(v);
}


void prim(Iterator* i){
    //setam iteratorul la primul element din vector
    i->curent = 0;
}

int valid(Iterator* i){
    return i->curent < dim(i->v);
}

void urmator(Iterator* i){
    i->curent ++;
}

TElem elementI(Iterator* i){
    return i->v->e[i->curent];
}


void distrugeI(Iterator* i){
    //eliberam memoria
    free(i);
}