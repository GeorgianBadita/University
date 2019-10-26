#include<fstream>
using namespace std;
ifstream f("1.in");
ofstream g("1.out");
int v[100];
int suma(int n,int v[])
{   int i,s;
    if(n==0) return 0;
    else return (v[n]+suma(n-1,v));
}
int main()
{
    int n,i;
    f>>n;
    for(i=1;i<=n;i++)
    f>>v[i];
    g<<suma(n,v);
}
