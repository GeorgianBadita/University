#include <cstdio>
using namespace std;

FILE *f = freopen("qsort.in", "r", stdin);
FILE *g = freopen("qsort.out", "w", stdout);

void poz(int ls, int ld, int &k)
{
    int i = ls, j = ld, aux;
    bool ml = true;
    while(i < j)
    {
        if(a[i] > a[j]) {
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
            ml = !ml;
        }
        if(ml) j--;
        else i ++;
    }
    k = i;
}
