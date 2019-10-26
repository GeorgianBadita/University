#include<fstream>
using namespace std;
int main()
{
    ifstream f("rachete.in");
    ofstream g("rachete.out");
   int i,m,n,o=0,aux=0,x=0,v;
    f>>n;
    for(i=1;i<=n;i++)
    {
     f>>v;
     if(v==1)
     x++;
     else if(v==2)
     aux++;
     else if(v==3)
     o++;
    }
    while(x!=0)
    {g<<1<<' ';
    x--;}
    while(aux!=0)
    {g<<2<<' ';
    aux--;
    }
    while(o!=0)
    {g<<3<<' ';
    o--;}
    return 0;
}
