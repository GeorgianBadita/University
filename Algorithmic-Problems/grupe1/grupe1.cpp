#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("grupe1.in");
ofstream g("grupe1.out");
int v[400],k,n,nrc[100],j,i,l,x[400],minim=1001,maxim=0,nrf,nrb,y,maximf=0,maximb=0,minimf=1001,minimb=1001;
char s[1001];
int main()
{
    f>>n>>k;
    for(i=1;i<=n;++i) {f>>s[i]; v[i]=i;} //g<<y<<' ';
    f.get();
    for(l=1;l<=k;++l)
    {   nrb=0; nrf=0;
    f>>nrc[l]; //g<<nrc[l]<<' ';
    for(j=1;j<=nrc[l];++j)
    {
        f>>x[j];
         for(i=1;i<=n;++i)
            {
            if(x[j]==v[i]&&s[v[i]]=='b') nrb++;
            nrf=nrc[l]-nrb;
            }
    } if(nrb<minimb) minimb=nrb;
      if(nrb>maximb) maximb=nrb;
      if(nrf<minimf) minimf=nrf;
      if(nrf>maximf) maximf=nrf;
    g<<nrb<<' '<<nrf; g<<'\n';
    }

    for(i=1;i<=k;++i)
      {// g<<nrc[i]-nrc[i+1]<<' ';
      if(nrc[i]>maxim) maxim=nrc[i];
      if(nrc[i]<minim) minim=nrc[i];
      }

        if(maxim-minim<2&&maximf-minimf<2&&maximb-minimb<2&&maximb-minimf<2&&maximf-minimb<2) g<<"DA";
        else g<<"NU";
    return 0;
}
