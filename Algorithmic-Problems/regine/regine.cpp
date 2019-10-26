#include<fstream>
#include<cmath>
using namespace std;
ifstream f("regine.in");
ofstream g("regine.out");
int v[100],n,sol=0;
int solutie(int k);
int valid(int k);
void bkt(int k);
void afisare(int k);
void bkt(int k)
{
    int i;
    for(i=1;i<=n;i++)
    {
        v[k]=i;
        if(valid(k)){
        if(solutie(k))
        afisare(k);
        else bkt(k+1);
        }
    }
}
int solutie(int k)
{
    if(k==n) return 1;
    return 0;
}
int valid(int k)
{
    int i;
    for(i=1;i<=k-1;i++)

        if(v[i]==v[k] || abs((float)v[k]-(float)v[i])==(k-i))
        return 0;
    return 1;
}
void afisare(int k)
{   int i,j,x;
    sol++;
    for(i=1;i<=n;i++)
    {for(j=1;j<=n;j++)
        if(v[i]==j&&sol<=3) g<<j<<' ';
    }

    if(sol<=3)g<<'\n';
}
int main()
{
    f>>n;

    bkt(1);
    g<<sol;

}
