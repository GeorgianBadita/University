#include<fstream>
using namespace std;
int v[10002];
int main()
{
    ifstream f("panglica.in");
    ofstream g("panglica.out");
    int x,i,n,c,nr1=0,nr2=0;
    f>>n>>c;
    for(i=1;i<=n;i++)
    f>>v[i];
    i=1; x=n;
    while(v[i]!=v[n])
    {
        i++;nr1++;
        if(v[i]==v[n]) {g<<x-nr1-nr2<<'\n'<<v[i]<<'\n'<<nr1<<'\n'<<nr2;break;}
        else {n--; nr2++;}
        if(v[i]==v[n]) {g<<x-nr1-nr2<<'\n'<<v[i]<<'\n'<<nr1<<'\n'<<nr2;break;}
    }
}
