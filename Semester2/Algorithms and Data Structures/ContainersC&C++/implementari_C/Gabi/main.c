#include <assert.h>
#include <stdio.h>
#include "DynVect.h"
#include "Repo.h"
#include "Service.h"
#include "UI.h"
#include "Validator.h"
#include "Tests.h"

int compara(int* a,int* b){
    return *a-*b;
}
void stergei(int* a){

}
/*
void testDomain(){
    printf("Hello, World!\n");
    DynVect* v = creeazaDynVect(1,compara,stergei);
    int a =5;
    int x = 7;
    adauga(v,&a);
    adauga(v,&a);
    adauga(v,&a);
    adauga(v,&x);
    int b = 5;
    int pos = cauta(v,&b);
    assert(pos==0);
    int c = 7;
    pos = cauta(v,&c);
    assert(pos==3);
    distrugeDynVect(v);
}
*/
int main() {
    testDomain();
    Repo* repo = creeazaRepo();
    Service* srv = creeazaService(repo);
    UI* ui = creeazaUI(srv);
    run(ui);
    distrugeUI(ui);
    return 0;
}