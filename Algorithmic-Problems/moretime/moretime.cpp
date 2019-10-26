#include<fstream>
#include<cmath>
using namespace std;
ifstream f("moretime.in");
ofstream g("moretime.out");
int rest[10001],cont[10001],fond[10001],n,i;
int p_cif(int y)
{
     int n,nr=0;
    n=y;
    while(n)  {nr++;n/=10;}
    return y/pow((float)10,(float)nr-1);
}
int u_cif(int x)
{
    return x%10;
}
int main()
{   int s,a,b,p=0,nr=0,j,k;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        if(p_cif(a)==u_cif(a)) {nr++;cont[++p]=a; fond[p]=b;}
    }
    g<<nr<<'\n';
    s=0;
    for(i=1;i<=p;i++)
    {
        g<<fond[i]<<' ';
        s+=fond[i];
        if(s%nr==0) {g<<i; for(j=1;j<=i;j++) g<<fond[j];break;}
        else {k=s%nr; rest[k]=i;}
    }
    for(i=1;i<=p-1;i++)
    {for(j=i+1;j<=p;j++)
    {
        g<<cont[j+1];
    }
    }
}
