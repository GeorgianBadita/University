#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("permutari.in");
ofstream g("permutari.out");
int v[10];
int main()
{
    int i,n;
    f>>n;
    for(i=0;i<n;i++) v[i]=i+1;
    sort(v,v+n);
    do
    {
        for(i=0;i<n;i++) g<<v[i]<<' ';
        g<<'\n';
    }while(next_permutation(v,v+n));
}
