#include<fstream>
#include<algorithm>
using namespace std;
struct react{int x,y;}v[8003];
int n,i,rez,aux;
bool cmp(react A,react B)
{
    if(A.x==B.x) return A.y<B.y;
    return A.x<B.x;
}
int main()
{
    ifstream f("reactivi.in");
    ofstream g("reactivi.out");
    f>>n;
    rez=n;
    for(i=1;i<=n;i++)
      f>>v[i].x>>v[i].y;
    sort(v+1,v+n+1,cmp);
    aux=v[1].y;

    for(i=2;i<=n;i++)
    {
     if(v[i].x<=aux)
     {
      rez--;
      aux=max(aux,v[i].x);
      aux=min(aux,v[i].y);
     }
     else
      aux=v[i].y;
    }
    g<<rez;
    f.close();g.close();
    return 0;
}
