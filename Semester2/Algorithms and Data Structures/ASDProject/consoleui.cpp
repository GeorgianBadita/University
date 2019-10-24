#include "consoleui.h"

/*
 * Functie care printeaza meniul pentru utilizator
 */
void ConsoleUI::print_menu(){
    std::string meniu = "\n\n1. Pentru a adauga un drum nou\n"
            "2. Pentru a sterge un drum\n"
            "3. Pentru a verifica daca reteaua poate acomoda toate masinile\n"
            "4. Pentru a verifica daca exista un ciclu eulerian in reteaua de transport\n"
            "5. Pentru a afla capacitatea necesara unui nou drum pentru a acomoda toate masinile\n"
            "6. Pentru a afla intersectiile ce trebuiesc legate astfel incat sa existe un ciclu eulerian in retea\n"
            "7. Pentru a afisa toate intersectiile\n"
            "8. Pentru a iesi din aplicatie\n"
            "\tDati va rog o comanda: ";
    std::cout << meniu;
}

/*
 * Functie care controleaza functionalitatiie programului
 */
void ConsoleUI::show_ui(){
    this->graf.adauga_muchie(1, 2, 3);
    this->graf.adauga_muchie(1, 3, 5);
    this->graf.adauga_muchie(2, 4, 6);
    this->graf.adauga_muchie(3, 4, 4);
    this->graf.adauga_muchie(3, 2, 3);


    while(true){
        print_menu();
        int cmd;
        std::cin >> cmd;
        if(cmd == 1){
                this->adauga_intersectie();
        }else if(cmd == 2) {

            this->sterge_intersectie();
        }else if(cmd == 3) {
                this->testeaza_retea_flux();
        }else if(cmd == 4) {
                this->testeaza_retea_euler();
        }else if(cmd == 5) {
                this->capacitate_drum();
        }else if(cmd == 6) {

                this->drumuri_noi();
        }else if(cmd == 7){
                this->afiseaza_drumuri();
        }
        else if(cmd == 8){
                break;
        }
        else{
            std::cout << "Comanda gresita!\n";
        }

    }
}

/*
 * Functie pentru adaugarea unei noi intersectii
 * :post: o intersectie noua va fi adaugata
 */
void ConsoleUI::adauga_intersectie(){
    int x, y, capacitate;
    std::cout << "\nDati prima intersectie: ";
    std::cin >> x;
    std::cout << "\nDati a doua intersectie: ";
    std::cin >> y;
    std::cout << "\nDati capacitatea drumului dintre intersectii: ";
    std::cin >> capacitate;
    this->graf.adauga_muchie(x, y, capacitate);
}

/*
 * Functie pentru stergerea unei intersectii
 * :post: o intersectie va fi stearsa
 */
void ConsoleUI::sterge_intersectie(){
    int x, y;
    std::cout << "\nDati prima intersectie: ";
    std::cin >> x;
    std::cout << "\nDati a doua intersectie: ";
    std::cin >> y;
    this->graf.sterge_muchie(x, y);
    this->graf.sterge_muchie(y, x);
}

/*
 * Functie pentru testarea retelei de flux
 */
void ConsoleUI::testeaza_retea_flux(){
    int x, y;
    std::cout << "\n Dati intersectia de plecare: ";
    std::cin >> x;
    std::cout << "\n Dati intersectia de sosire: ";
    std::cin >> y;

    auto rasp = this->graf.flux_maxim(x, y);
    std::cout << "Numarul maxim de masini ce pot ajunge din " << x <<" in " << y << " este " << rasp << '\n';
    if(rasp >= this->numar_masini){
        std::cout << "Pot ajunge toate masinile din " << x << " in " << y << '\n';
    }
    else{
        std::cout << "Nu pot ajunge toate masinile din " << x << " in " << y << '\n';
    }

}

/*
 * Functie pentru testarea retelei de ciclu/lant eulerian
 */
void ConsoleUI::testeaza_retea_euler(){
    auto rez = this->graf.ciclue_euler();
    if(rez.empty()) {
        std::cout << "Nu exista niciun lant in retea astfel incat o masina sa parcurga fiecare drum o singura data\n";
    }
    else{
        std::cout << "Exista un lant astfel incat o masina sa poata parcurge o singura data fiecare drum: ";
        for(const auto& elem : rez){
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }
}

/*
 * Functie care afiseaza capacitatea necesara unui drum nou construit
 * pentru a acomoda traficul necesar
 */
void ConsoleUI::capacitate_drum(){
    int x, y;
    std::cout << "Dati intersectia de plecare: ";
    std::cin >> x;
    std::cout << "Dati intersectia de sosire: ";
    std::cin >> y;
    int capacitate = this->graf.capacitate_drum(x, y, this->numar_masini);
    if(capacitate == 0){
        std::cout << "Nu mai trebue adaugat niciun drum suplimentar\n";
    }
    else{
        std::cout << "Ar trebui adaugat un drum de la " << x << " la " << y << " de capacitate " << -capacitate << '\n';
    }
}

/*
 * Functie care afiseaza drumurile ce trebuie construite in oras astfel incat
 * sa existe un ciclu eulerian
 */
void ConsoleUI::drumuri_noi(){
    auto rez = this->graf.muchii_euler();
    if(rez.empty()){
        std::cout << "Nu mai trebuie drumuri adaugate\n";
    }
    else{
        std::cout << "Drumurile ce trebuie adaugate sunt: \n";
        for(const auto& muc : rez){
            std::cout << muc.x << ' ' << muc.y << '\n';
        }
        std::cout << '\n';
    }
}

/*
 * Functie care afiseaza toate intersectiile din oras
 */
void ConsoleUI::afiseaza_drumuri(){
    std::cout << '\n';
    IteratorMD<int,int> it = this->graf.graph.iterator();
    while(it.valid()){
        auto el = it.element();
        std::cout << el.c << ' ' << el.v << '\n';
        it.urmator();
    }
    std::cout << '\n';
}
