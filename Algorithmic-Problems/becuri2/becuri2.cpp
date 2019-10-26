#include<fstream>
using namespace std;
ifstream f("becuri2.in");
ofstream g("becuri2.out");
int va[100],vb[100],s[100],s1;
int main()
{
    int poz,nra=0,nrb=0,a,b,n,m,i,lg=0,max=0,ok=0;
    f>>n;
    m=n;
    f>>a>>b;
    while(a)
    {
        va[m]=a%2; a/=2; m--;
    }
    if(m>0)
    for(i=1;i<=m;i++) va[i]==0;
    //for(i=1;i<=n;i++)
    //g<<va[i];
    m=n;
    while(b)
    {
        vb[m]=b%2; b/=2; m--;
    }
    if(m>0)
    for(i=1;i<=m;i++) vb[i]==0;
    //for(i=1;i<=n;i++)
    //g<<vb[i];
    for(i=1;i<=n;i++)
    {
        if(va[i]==1&&vb[i]==0) nra++; else
        if(vb[i]==1&&va[i]==0) nrb++;
        s[i]=va[i]+vb[i];
    }
    g<<nra<<' '<<nrb<<' '; s1=0; lg=0;
    for(i=1;i<=n;i++)
    {   lg=0;
      while(s[i]==2) {lg++;i++;}
      if(lg>max) max=lg;
    }
    g<<max;
}
