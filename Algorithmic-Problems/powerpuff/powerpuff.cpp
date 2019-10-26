#include<fstream>
using namespace std;
ifstream f("powerpuff.in");
ofstream g("powerpuff.out");
int rezolvare(int x, int y)
{   int v[11],w[11],n,m,p=0,k=0,i,j,ok;
    n=x;
    while(x) {v[++p]=x%10; x/=10;}
    while(y) {w[++k]=y%10; y/=10;}
    for(i=1;i<=p;i++)
    {
        ok=0;
        for(j=1;j<=k;j++)
        if(v[i]==w[j]) {ok=1;};
        if(ok==0) n+=v[i];
    }
    for(i=1;i<=k;i++)
    {   ok=0;
        for(j=1;j<=p;j++)
        if(w[i]==v[j]) {ok=1;}
        if(ok==0) n-=w[i];
    }
    return n;
}
int main()
{
    int k,x,y,z,i,n;
    f>>x>>y>>z;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>k;
        x=rezolvare(x,k);
        y=rezolvare(y,k);
        z=rezolvare(z,k);
    }
    g<<x<<'\n'<<y<<'\n'<<z;
}
