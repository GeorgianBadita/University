#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("numere7.in");
ofstream g("numere7.out");
int v[250000],x[250000],e[250000],maxim,minim=501;
int main()
{
    int n,i,l=1,j;
    f>>n;
    for(i=1;i<=n*n;++i) v[i]=i;
   for(i=1;i<=n*n;++i) {f>>x[i];}
    sort(x,x+n*n+1);
    for(i=0;i<=n*n;i++)
    {//e[++l]=v[i]-x[i];
    //if(e[l]>maxim) maxim=e[l];
    //if(e[l]<minim) minim=e[l];
    g<<v[i]-x[i]<<' ';
    }
    g<<'\n';
    for(i=1;i<=n*n;++i) {g<<x[i]<<' ';}
    g<<'\n';
    for(i=1;i<=n*n;++i) {g<<v[i]<<' ';}
    //g<<minim<<' '<<maxim;
}
