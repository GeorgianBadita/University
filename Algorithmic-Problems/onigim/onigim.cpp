#include<fstream>
using namespace std;
ifstream f("onigim.in");
ofstream g("onigim.out");
int nrm,nrc=0,ok,i,j,k,n,maxim,v[1001],w[1001],a[1001],minim=1001,p[1001];
int main ()
{
    f>>n>>k;
    for(i=1;i<=k;i++)
    {
        f>>p[i];
    }
    for(i=1;i<=n;i++)
    {
        f>>a[i];
        w[a[i]]++;
    }
    i=1;
    for(j=0;j<=n;j++)
    {
        if(w[j]!=0)
        {
            v[j]=p[i];
            i++;
        }
    }
    for(i=1;i<=n;i++)
    a[i]=v[a[i]];
    for(i=1;i<=n;i++)
    g<<a[i]<<' '; g<<'\n';
    for(i=n;i>=0;i--)
    {
        if(w[i]!=0&&nrc<3)
        {
           nrm+=w[i];
           nrc++;
        }
    }
    g<<nrm<<' '<<'\n';
    nrc=0;
    for(i=0;i<n;i++)
    if(nrc<w[i]) nrc=w[i];
    g<<nrc<<'\n';
}

