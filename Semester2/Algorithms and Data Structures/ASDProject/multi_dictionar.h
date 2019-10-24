#ifndef MULTI_DICTIONAR_H
#define MULTI_DICTIONAR_H
#include "my_vector.h"

template<typename TCheie, typename TValoare>
class IteratorMD;

/*
 * Clasa genereica pentru reprezentarea unei perechi, cu elemente de timp TCheie, TValoare
 */
template<typename TCheie, typename TValoare>
class TPereche{

public:
    TCheie c;
    TValoare v;


    /*
     * Constructor pentru clasa TPereche
     * :param cheie: element de tip TCheie
     * :param valoare: element de tip TValoare
     */
    //creeaza
    TPereche(const TCheie& cheie, const TValoare&valoare): c{cheie}, v{valoare} {}

    /*
     * Supraincarcam operatorul ==
     */
    bool operator==(const TPereche<TCheie, TValoare>& per){
        return this->v == per.v && this->c == per.c;
    }

    /*
     * Supraincarcam operatorul !=
     */
    bool operator!=(const TPereche<TCheie, TValoare>& per){
        return !(*this == per);
    }


};

/*
 * Clasa pentru reprezentarea unui nod alocat dinamic
 */

template<typename TCheie, typename TValoare>
class TNod{
public:
    TPereche<TCheie, TValoare> e;
    TNod* urm;
    /*
     * Constructor class for TNod class
     */
    //creeaza
    explicit TNod(const TPereche<TCheie, TValoare>& el): e{el}, urm{nullptr}{}

};



/*
 * Clasa pentru reprezentarea multidicitonarului
 */
template<typename TCheie, typename TValoare>
class MD{
private:
    TNod<TCheie, TValoare>* prim;
    TNod<TCheie, TValoare>* ultim;

public:


    friend class TNod<TCheie, TValoare>; //pentru accesul la membrii privati ai TNod

    /*
     * Constructor pentru clasa MD(MultiDictionar)
     */
    //creeaza
    MD(): prim{nullptr}, ultim{nullptr} {}



    /*
     * Functie de adaugare in multidctionar
     * :param c: TCheie, cheia elementului de adaugat
     * :param v: TValoare, valoarea elementului de adaugat
     */
    void adauga(const TCheie& c, const TValoare& v){
        auto node = new TNod<TCheie, TValoare>(TPereche<TCheie, TValoare>{c, v});
        if(this->prim == nullptr){
            node->urm = this->prim;
            this->prim = this->ultim = node;
            this->ultim->urm = nullptr;
        }
        else{
            auto start = this->prim;
            while(start != nullptr && start->e.c != node->e.c){
                start = start->urm;
            }
            if(start == nullptr){
                node->urm = this->prim;
                this->prim = node;
            }
            else{
                node->urm = start->urm;
                start->urm = node;
            }
        }
    }

    /*
     * Functie de stergere din multidictionar
     * :param c: TCheie, cheia elementului de sters
     * :param v: TValoare, valoarea elementului de sters
     */
    void sterge(const TCheie& c, const TValoare& v){
        if(this->prim == nullptr){ //daca lista e vida nu sterg nimic
            return;
        }
        auto nod = TPereche<TCheie, TValoare>{c, v};
        if(this->prim->e == nod){
            auto de_sters = this->prim;
            this->prim = this->prim->urm;
            delete de_sters;
            return;
        }

        auto start = this->prim;
        while(start->urm->e != nod){

            start = start->urm;
            if(start->urm == nullptr){
                break;
            }
        }
        if(start->urm == nullptr){
            return;
        }
        auto de_sters = start->urm;
        start->urm = start->urm->urm;
        delete de_sters;
    }

    /*
     * Functie care returneaza numarul de elemente din dictionar
     * :return: numar natural reprezentand numarul de elemente din dictionar
     */
    int dim(){
        if(this->prim == nullptr){
            return 0;
        }
        int lungime = 1;
        TNod<TCheie, TValoare>* nod = this->prim;
        while(nod->urm != nullptr){
            lungime ++;
            nod = nod->urm;
        }
        return lungime;
    }

    /*
     * Functie care returneaza lista de valori asociate unei chei
     * :param c: TCheie, cheia a carei liste de valori o cautam
     * :return: Lista valorilor asociate chei c
     */
    TVector<TValoare> cauta(const TCheie& c){
        TVector<TValoare> rez;
        if(this->prim == nullptr){
            return rez;
        }
        auto start = this->prim;
        while(start != nullptr){
            if(start->e.c == c){
                rez.push_back(start->e.v);
            }
            start = start->urm;
        }
        return rez;
    }

    /*
     * Functie care determina daca dictionarul este vid
     * :return: true, daca dictionarul este vid, fals altfel
     */
    bool vid(){
        return this->dim() == 0;
    }

    /*
     * Suprascriem operatorul [] ca sa returneze lista de valori a unei anumite chei
     */
    TVector<TValoare> operator[](const TCheie& c){
        return this->cauta(c);
    }

    /*
     * RULE OF 3
     * Destructor pentru clasa multidictionar
     */
    ~MD(){
        TNod<TCheie, TValoare>* start = this->prim;
        while(start != nullptr){
            TNod<TCheie, TValoare>* urmator = start->urm;
            delete start;
            start = urmator;
        }
    }

    /*
     * Constructor de copiere
     * RULE OF 3
     */
    MD(const MD& ot){
        auto prim_nou = new TNod<TCheie, TValoare>(ot.prim->e);
        this->prim = prim_nou;
        TNod<TCheie, TValoare>* count = ot.prim->urm;
        while(count != nullptr){
            auto de_adaugat = new TNod<TCheie, TValoare>(count->e);
            prim_nou->urm = de_adaugat;
            prim_nou = prim_nou->urm;
            count = count->urm;
        }
    }

    /*
     * Asignment operator
     * RULE OF 3
     */
    MD& operator=(const MD& ot){
        if(this == &ot){
            return *this; //MD = MD
        }

        TNod<TCheie, TValoare>* start = this->prim;
        while(start != nullptr){
            TNod<TCheie, TValoare>* next = start->urm;
            delete start;
            start = next;
        }

        auto new_head = new TNod<TCheie, TValoare>(ot.prim->e);
        this->prim = new_head;
        TNod<TCheie, TValoare>* counter = ot.prim->urm;
        while(counter != nullptr){
            auto to_add = new TNod<TCheie, TValoare>(counter->e);
            new_head->urm = to_add;
            new_head = new_head->urm;
            counter = counter->urm;
        }
        return *this;
    }

    /*
     * Move constructor
     * RULE OF 5
     */
    MD(MD&& ot) noexcept:prim{nullptr}, ultim{nullptr}{
        this->prim = ot.prim;
        ot.prim = nullptr;
        ot.ultim = nullptr;
    }

    /*
     * Move assignment
     * RULE OF 5
     */
    MD& operator=(MD&& ot) noexcept{
        if(this != &ot){
            TNod<TCheie, TValoare>* start = this->prim;
            while(start != nullptr){
                auto urm = start->urm;
                delete start;
                start = urm;
            }

            this->prim = ot.prim;
            this->ultim = ot.ultim;
            ot.prim = nullptr;
            ot.ultim = nullptr;
        }
        return *this;
    }

    friend class IteratorMD<TCheie, TValoare>;

    IteratorMD<TCheie, TValoare> iterator(){
        return IteratorMD<TCheie, TValoare>(*this);
    }

    /*
     * Modificare
     */
    MD f(MD<TCheie, TValoare> md){
        MD<TCheie, TValoare> to_ret;
        auto it = this->iterator();
        while(it.valid()){
            auto el = it.element();
            auto res_c = md.cauta(el.c);
            bool is = false;
            for(auto el1: res_c){
                if(el1 == el.v){
                    is = true;
                    break;
                }
            }
            if(!is){
                to_ret.adauga(el.c, el.v);
            }
            it.urmator();
        }

        auto it1 = md.iterator();
        while(it1.valid()){
            auto el = it1.element();
            auto res_c = this->cauta(el.c);
            bool is = false;
            for(auto el1: res_c){
                if(el1 == el.v){
                    is = true;
                    break;
                }
            }
            if(!is){
                to_ret.adauga(el.c, el.v);
            }
            it1.urmator();
        }

        return to_ret;
    }

};

/*
 * Clasa pentru reprezentarea interatorului
 */
template<typename TCheie, typename TValoare>
class IteratorMD{
private:
    MD<TCheie, TValoare>& md;
    TNod<TCheie, TValoare>* curent;
public:
    /*
     * Constructor pentru interator
     */
    explicit IteratorMD(MD<TCheie, TValoare>& md):md{md} {
        curent = md.prim;
    }

    /*
     * Functie pentru returnarea elementului curent
     */

    TPereche<TCheie, TValoare> element(){
        return this->curent->e;
    }

    /*
     * Functie pentru testarea validitatii iteratorului
     */
    bool valid(){
        return this->curent != nullptr;
    }

    /*
     * Functie pentru trecerea iteratorului la elementul urmator
     */
    void urmator(){
        this->curent = this->curent->urm;
    }

};

#endif // MULTI_DICTIONAR_H
