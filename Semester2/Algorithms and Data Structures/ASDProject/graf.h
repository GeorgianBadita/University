#ifndef SERVICE_H
#define SERVICE_H
#include "multi_dictionar.h"
#include <cstring>
#include <queue>
#define MAX_INTERS 500

/*
 * Structura pentru implementarea unui nod
 */
struct Muchie{
    int y, x;

    /*
     * Constructorul unui nod
     */
    Muchie(int x, int y):y{y}, x{x} {}
};


class Graf{
private:
    int flux[MAX_INTERS][MAX_INTERS];
    bool viz[MAX_INTERS];
    int parent[MAX_INTERS];
    int num_intersectii;

    /*
     * Functie care aplica bfs asupra grafului nostru
     * :param s: sursa de aplicare a bfs
     * :param t: destinatia
     * :param viz[]: array pentru nodurile vizitate
     * :param parent[]: array pentru returnarea arborelui creat de bfs
     * :return: true, daca s-a gasit un drum de la s la t, false altfel
     */
    bool bfs(int s, int t);

public:
    MD<int, int> graph; //multidictionarul vid;

    /*
     * Constructor fara parametrii pentru graf
     */
    Graf();

    /*
     * Getter pentru numarul de intersectii
     */
    int get_numar_inters() const {return this->num_intersectii;}

    /*
     * Constructor pentru clasa Service
     */
    explicit Graf(int inter);

    /*
     * Functie care adauga o muchie in graf
     * :param int: nodul sursa
     * :param int: nodul destinatie
     * :param int: capacitatea muchiei
     */
    void adauga_muchie(int x, int y, int capacitate);

    /*
     * Functie pentru stergerea unei muchii din graf
     * :param int: nodul sirsa
     * :param int: nodul destinatie
     */
    void sterge_muchie(int x, int y);

    /*
     * Functie care returneaza lista de vecini a unui nod x
     * :param nt x: nodul ai carui vecin dorim sa ii aflam
     * :return: un vector continant toti vecinii nodului x
     */
    TVector<int> vecini(int x);

    /*
     * Functie care returneaza cantitatea maxima de flux de la o sursa la o destinatie dintr-un graf
     * :param int: sursa de intrare a fluxului
     * :param out: destinatia fluxului
     */
    int flux_maxim(int sursa, int destinatie);

    /*
     * Functie care returneaza lantul sau ciclul eulerian al unui graf daca exista
     */
    TVector<int> ciclue_euler();

    /*
     * Functie care verifica daca graful are un ciclu sau un lant eulerian
     * :post: daca graful nu este eulerian, dar are un lant eulerian atunci
     * functia returneaza nodul de pornire al lantului, iar daca nu are nici un lant eulerian
     * va returna -1
     */
    int verifica_euler();

    /*
     * Functie care returneaza capacitatea unui drum nou adaugat astfel incat fluxul sa poata ajunge de la sursa la destinatie
     * :param sursa: nodul sursa
     * :param destinatie: nodul destinatie
     * :param flux: fluxul ce se vrea a fi acomodat
     * :return: numar intreg reprezentand capacitatea minima de adaugat
     */
    int capacitate_drum(int sursa, int destinatie, int flux);

    /*
     *  Functie care returneaza muhciile ce trebuie adaugate intr-un graf astfel incat acesta sa devina eulerian
     * :param: -
     * :return: returneaza un vector de muchii, reprezentand muchiile ce trebuie adaugate in graf ca acesta sa devina eulerian
     */
    TVector<Muchie> muchii_euler();

    /*
     * Functie care seteaza numarul de intersectii
     * :param num_intersectii: intreg, noul numar de intersectii
     * :post: numarul de intersectii va fi modificat
     */
    void set_num_inter(int num_intersectii);
};

#endif // SERVICE_H
