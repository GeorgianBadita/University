#include<fstream>
using namespace std;
ifstream f("opmat.in");
ofstream g("opmat.out");
int a[251][251],v[251],w[251];
int main()
{
    int n,m,i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++) f>>a[i][j];

}
