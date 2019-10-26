#include<fstream>
using namespace std;
long long a[50][50][50];
int main()
{   ifstream f("ceva.in");
    ofstream g("ceva.out");
    int q,n,m,p,i,j,k,l,z,x;
    f>>n>>m>>p;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            for(k=1;k<=p;k++)
               {
                   a[i][j][k]=i;
               }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            for(k=1;k<=p;k++)

                {
                   g<<a[i][j][k]<<' ';
                }
                g<<'\n';
        }
    }
}
