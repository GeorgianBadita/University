#include <iostream>

#include "graf.h"
#include "consoleui.h"

int main()
{

    int num_inter, num_masini;

    /*std::cout << "Dati numarul de intersectii: ";
    std::cin >> num_inter;
    std::cout << "Dati numarul de masini: ";
    std::cin >> num_masini;*/
    //ConsoleUI ui{4, 9};
    //ui.show_ui();

    MD<int, int> md1;
    MD<int, int> md2;
    md1.adauga(1, 2);
    md1.adauga(1, 3);
    md1.adauga(2, 3);

    md2.adauga(1, 3);
    md2.adauga(2, 4);

    auto res = md1.f(md2);

    auto it = res.iterator();
    while(it.valid()){
        auto el = it.element();
        std::cout << el.c << ' ' << el.v << '\n';
        it.urmator();
    }

    return 0;
}
