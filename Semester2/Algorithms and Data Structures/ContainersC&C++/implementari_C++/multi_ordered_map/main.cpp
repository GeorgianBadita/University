#include <iostream>
using namespace std;


/*
 *
 *
 *  Daca ai un numar, sa zicem 1200, sa vedem ce se intampla daca il descompuni in factori primi
 *
 *  1200 |  2
 *   600 |  2
 *   300 |  2
 *   150 |  2
 *    75 |  5
 *    15 |  5
 *     3 |  3
 *     1 | ..   Deci 1200 se descompune in factori primi ca si 2^4 * 5^2 * 3
 *
 *     Bun, ce am facut mai sus nu e neaparat esenta ideei de a calcula 0-urile, dar e ceva general sa iti faci o idee
 *     Adevarata smecherie vine acum:
 *
 *     Cum ti-am aratat, daca ai sa zicem 1290, poate fi scris ca si 129*10 = 129*2*5
 *     daca ai sa zicem 102300, poate fi scris ca si 1023*100 = 1023*10*10 = 1023*2*5*2*5
 *
 *     Ce se observa ca un 0 de la finalul unui produs este dat de un 2*5, deci e suficient sa vezi cati 5 si cati 2 intra
 *     in produsul respectiv, si cum vezi de exemplu cati 5 sunt in descompunerea unui numar? Verifici de cate ori se imparte numarul
 *     excat la 5, la fel si daca vrei sa vezi cati 2 sunt in produs. Iar raspunsul final va fi numarul minim dintre numarul de 2 si
 *     numarul de 5, ca, ai nevoie de atatia 5 si atataia 2 ca sa faci perechi de 2*5
 *
 *     Exemnplu:
 *
 *     cate 0-uri are la final 1*2*3*4*5*6*7*8*9*10
 *     Produsul numerelor este 3628800 => are 2 zero-uri la final, sa vedem cum am face fara sa calculam produsul, pe baza
 *     observatiilor de mai sus
 *
 *     luam toate numerele pe rand sa vedem cati 5 si 2 au:
 *     o sa notez numar -> 2:cati_2, 5:cati_5 (astea inseamna ca 2^cati_2 si 5^cati_5 apar in descompunerea numarului in factori primi)
 *
 *     1 -> 2:0, 5:0 |
 *     2 -> 2:1, 5:0 |
 *     3 -> 2:0, 5:0 |
 *     4 -> 2:2, 5:0 |
 *     5 -> 2:0, 5:1 |  => avem de 7 ori 2 in produs si de 2 ori 5, cum numarul de 5 < numarul de 2, ne va da numarul de 0 de la final
 *     6 -> 2:1, 5:0 |                                                                                                      adica 2
 *     7 -> 2:0, 5:0 |
 *     8 -> 2:3, 5:0 |
 *     9 -> 2:0, 5:0 |
 *     10-> 2:1, 5:1 |
 */

int main(){

}