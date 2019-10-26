#include<fstream>
using namespace std;
int main()
{
    ifstream f("sir4.in");
    ofstream g("sir4.out");
    int n,p,k,a[1000],z,u;
    f>>k;
    p=k*k; n=p;

    while(n>99);
     {
         n=n/10;
     }
     g<<n;

}
