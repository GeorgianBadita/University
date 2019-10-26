#include<fstream>
using namespace std;
int nr_div(int n)
{
    int i,nr=0;
    for(i=1;i<=n;i++)
    if(n%i==0) nr++;
    return nr;
}
int v[101];
int main()
{
    ifstream f("nmaxdiv.in");
    ofstream g("nmaxdiv.out");
    int n,i,x,max=0;
    f>>n;
    for(i=1;i<=n;i++)
    {f>>v[i]; x=nr_div(v[i]); if(x>max)max=x;}
    for(i=1;i<=n;i++) if(nr_div(v[i])==max) g<<v[i]<<' ';
    g<<'\n';
    for(i=1;i<=n;i++) g<<nr_div(v[i])<<' ';
    return 0;
}
