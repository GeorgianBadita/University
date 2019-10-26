#include<fstream>
using namespace std;
 int a[101][101],v[1001];
int main()
{
    ifstream f("seif1.in");
    ofstream g("seif1.out");
    int n,k,i,j,x=0,p=0,l=1;
    f>>n>>k;
    k=k%(n*2);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    f>>a[i][j];
    for(i=1;i<=n/2;i++) x++,v[x]=a[i][n/2-i+1];
    for(i=1;i<=n/2;i++) x++,v[x]=a[n/2+i][i];
    for(i=1;i<=n/2;i++) x++,v[x]=a[n-i+1][n/2+i];
    for(i=1;i<=n/2;i++) x++,v[x]=a[n/2-i+1][n-i+1];
    for(i=k+1;i<=x;i++) g<<v[i]<<' ';
    for(i=1;i<=k;i++) g<<v[i]<<' ';
    return 0;
}
