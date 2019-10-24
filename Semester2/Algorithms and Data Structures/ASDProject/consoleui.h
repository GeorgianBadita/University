#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "graf.h"
#define MAX_INTER 500

class ConsoleUI
{
private:
    Graf graf{MAX_INTER};
    int numar_masini;
public:
    /*
     * Constructor pentru interfata utilizator
     * :param num_intes: numarul de intersectii din oras
     * :param num_masini: numarul de masini din oras
     */
    ConsoleUI(int num_inters, int num_mas): numar_masini{num_mas}{
        graf.set_num_inter(num_inters);
    }

    /*
     * Functie care printeaza meniul pentru utilizator
     */
    void print_menu();

    /*
     * Functie care controleaza functionalitatiie programului
     */
    void show_ui();

    /*
     * Functie pentru adaugarea unei noi intersectii
     * :post: o intersectie noua va fi adaugata
     */
    void adauga_intersectie();

    /*
     * Functie pentru stergerea unei intersectii
     * :post: o intersectie va fi stearsa
     */
    void sterge_intersectie();

    /*
     * Functie pentru testarea retelei de flux
     */
    void testeaza_retea_flux();

    /*
     * Functie pentru testarea retelei de ciclu/lant eulerian
     */
    void testeaza_retea_euler();

    /*
     * Functie care afiseaza capacitatea necesara unui drum nou construit
     * pentru a acomoda traficul necesar
     */
    void capacitate_drum();

    /*
     * Functie care afiseaza drumurile ce trebuie construite in oras astfel incat
     * sa existe un ciclu eulerian
     */
    void drumuri_noi();

    /*
     * Functie care afiseaza toate intersectiile din oras
     */
    void afiseaza_drumuri();

};



#endif // CONSOLEUI_H
