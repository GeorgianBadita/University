#include<fstream>
using namespace std;
int a[100001],v[100001],n,m;
ifstream f("colina.in");
ofstream g("colina.out");
int caut(int v[], int n, int x)
{
    int ls=0,ld=n-1,m,poz;
    while(ls<=ld)
    {
        m=(ls+ld)/2;
        if(x==v[m]) {poz=m;return m,poz;}
        if(x<v[m]) ld=m-1;
        else ls=m+1;

    }
        return -1;
}
void citire()
{   int i;
    f>>n>>m;
    for(i=0;i<n;i++)
        f>>v[i];
        for(i=0;i<m;i++) f>>a[i];
}
int main()
{
    citire();
    for(int i=1;i<=n;i++)
    if(caut(a,m,v[i])!=-1) g<<"DA"<<'\n'; else g<<"NU"<<'\n';
}
