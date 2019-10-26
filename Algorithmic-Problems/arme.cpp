#include<fstream>
using namespace std;
int mian()
{
    ifstream f("arme.in");
    ofstream g("arme.out");
    int v[1001],n,m,i,ok,aux;
    f>>n>>m;
    for(i=1;i<=n+m;i++)
        {f>>v[i];
        g<<v[i];
        }
        return 0;
}

