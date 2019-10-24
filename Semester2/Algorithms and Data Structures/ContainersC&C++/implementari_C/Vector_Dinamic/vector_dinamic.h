//
// Created by geo on 3/11/18.
//

#ifndef VECTOR_DINAMIC_VECTOR_DINAMIC_H
#define VECTOR_DINAMIC_VECTOR_DINAMIC_H

//Tip de date generic (pentru moment este intrg)

typedef int TElem;

typedef struct {
    /*
     * Struct pentru reprezentarea Vectorului dinamic
     * :camp cp: dimensiune
     * :camp n: numarul de elemente
     * :camp TElem* e: pointer catre tipul de date generic TElem
     */

    int cp;
    int n;
    TElem* e;
}VectorDinamic;


typedef struct {
    /*
     * Struct pentru reprezentarea iteratorului
     * :camp VectorDinamic* v: Pointerul iteratorului catre Vectorul Dinamic
     * :camp curent: pozitia curenta a iteratorului in vectorul dinamic
     * :obs: se pote folosi si pointer spre un element
     */
    VectorDinamic* v;
    int curent;
}Iterator;

/*
 * Constructorul vectorului dinamic
 * :param cp: capacitatea initiala a vectorului
 * :return: returneaza un vector dinamic
 */
VectorDinamic* creeaza(int cp);

/*
 * Destructorul vectorului dinamic, functie care dealoca memoria folosita
 * :param v: Vector Dinamic
 */
void distruge(VectorDinamic* v);


/*
 * Functie care ne da numarul de elemente
 * :param v: Vector Dinamic
 * :return: dimensiunea vectorului
 */
int dim(VectorDinamic* v);

/*
 * Functie care returneaza al i-lea element din Vectorul dinamic
 * :param v: Vector Dinamic
 * :param pos: Pozitia elementului dorit
 * :pre: 1 <= pos <= dim(&v)
 * :return: elementul de pe pozitia pos va fi returnat
 */
TElem element(VectorDinamic* v, int pos);

/*
 * Functie care adauga un element nou la sfarsit
 * :param v: Vector Dinamic
 * :param e: elemntul de tip TElem ce se vrea a fi adaugat
 */
void adauga_sfarsit(VectorDinamic* v, TElem e);

//ALTE OPERATII
//....

/*
 * Functia care ne da un iterator pe vector
 * :param v: Vector dinamic
 * :return: un iteartor pe Vectorul v
 */
Iterator* iteratorV(VectorDinamic* v);

/*
 * Functie care initializeaza iteratorul sa pointeze catre primul element din v
 * :param v: Iterator
 */
void prim(Iterator* i);

/*
 * Functie care trece la urmatorul element din vector
 * :param i: Iterator
 */
void urmator(Iterator* i);

/*
 * Functie care intoarce elementul curent din iterator
 * :param i: iterator
 * :return: elementul curent din iterator
 */
TElem elementI(Iterator* i);

/*
 * Functie care ne spune daca iteratorul a ajuns la final sau nu (daca e valid)
 * :param i: Iterator
 * :return: 1 daca iteratorul este valid, 0 altfel
 */
int valid(Iterator* i);

/*
 * Functie care distruge un iterator (delaoca memoria asociata acestuia)
 * :param i: Iteratorul ce se vrea a fi disturs
 * :post: iteratorul va fi distrus
 */
void distrugeI(Iterator* i);

#endif //VECTOR_DINAMIC_VECTOR_DINAMIC_H
