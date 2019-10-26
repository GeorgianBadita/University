#include<fstream>
using namespace std;
ifstream f("cifre1.in");
ofstream g("cifre1.out");
int aux,p,ex,coef;
long long n,nrc;
int main()
{
    f>>n;
    aux=n;
    p=1; coef=9;
    while(aux>9)
    {
        nrc=nrc+p*coef;
       aux/=10;
       p++;
        coef*=10;
        ex=ex*10+9;
    }
    nrc=nrc+(p*(n-ex));
    g<<nrc;
}
