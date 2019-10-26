#include<fstream>
#include<iostream>
using namespace std;
ifstream f("remi1.in");
ofstream g("remi1.out");
int v[10001],poly,n,i;
int main()
{   int p=0,max=0,maxi;
    f>>poly;
    f>>n;
    for(i=1;i<=n;i++) {f>>v[i]; if(max<v[i]) max=v[i];maxi=i;}
    v[0]=max;
    for(i=0;i<=n;i++) g<<v[i];
    return 0;
}
