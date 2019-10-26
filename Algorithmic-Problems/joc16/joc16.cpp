#include<fstream>
using namespace std;
int b[40001],r[40000],v[40001];
int main()
{
    ifstream f("joc16.in");
    ofstream g("joc16.out");
    int j,z,n,i,x,y,p=0,l=0,ok=1;
    f>>n>>x>>y;
    b[p]=1;
    r[l]=n+1; z=r[l];
    ok=1; i=1;
    while(ok==1)
    {v[i]=i;
    for(j=1;j<=p;j++) if(b[i-1]+x!=b[j])
    b[++p]=b[i-1]+x;
    else {ok=0;break;}
     for(j=1;j<=l;j++) if(r[i-1]-y!=r[j])
    r[++l]=r[i-1]-y;
    else {ok==0; break;}
    if(b[p]>n) b[p]=1;
    if(r[l]<1) r[l]=z-y;
    if(b[p]==r[l]) {ok=0;break;}
    g<<b[p]<<' '<<r[l]<<'\n'; i++;

    }

}
