#include<fstream>
#include<cmath>
using namespace std;
int main()
{
    ifstream f("cifra.in");
    ofstream g("cifra.out");
    int n,d,k,nr;
    f>>n;
    d=1+8*n;
    k=(int)-1-sqrt(d)/2;
    nr=k*(k+1)/2;
    if(nr==0)
    g<<k;
    else
    g<<n-nr;
    return 0;
}
