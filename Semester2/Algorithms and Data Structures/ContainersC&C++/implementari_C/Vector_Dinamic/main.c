#include "vector_dinamic.h"
#include "stdio.h"
#include "malloc.h"

VectorDinamic* creeare(){
    //se aloca spatiu de memorie pentru vector

    VectorDinamic* v = creeaza(2);
    adauga_sfarsit(v, 1);
    adauga_sfarsit(v, 2);
    adauga_sfarsit(v, 3);
    adauga_sfarsit(v, 4);
    return v;
}

//printam folosind iteratorul

void tiparire(VectorDinamic* v) {
    Iterator* i = iteratorV(v);

    prim(i);
    while(valid(i)) {
        printf("%d ", elementI(i));
        urmator(i);
    }
    printf("\n");
    distrugeI(i);
}

int main() {
    VectorDinamic *v = creeare();
    tiparire(v);
    distruge(v);
    return 0;
}