#include<fstream>
using namespace std;
ifstream f("genab.in");
ofstream g("genab.out");
int v[20],p,n;
void bkt(int k);
int solutie(int k);
void afisare(int k);
int main()
{
    int i;
    f>>n;
    for(p=1;p<=n-1;p++)
    bkt(1);

    for(i=1;i<n;i++) g<<i<<' ';
    g<<n;
}
void bkt(int k)
{
    int i;
    for(i=v[k-1]+1;i<=n;i++)
    {
        v[k]=i;
        if(solutie(k))
        afisare(k);
        else bkt(k+1);
    }

}
int solutie (int k)
{
    if(k==p) return 1;
    return 0;
}
void afisare(int k)
{
    for(int i=1;i<=k;i++) g<<v[i]<<' ';
    g<<v[k]<<'\n';
}
