#include<fstream>
using namespace std;
int main()
{
  ifstream f("matrixdel.in");
  ofstream g("matrixdel.out");
    int v[100][100],i,j,m,n,l,c;
    f>>n>>m>>l>>c;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        f>>v[i][j];
        for(i=l+1;i<=n;i++)
        {  for(j=1;j<=m;j++)

            v[i-1][j]=v[i][j];
        }
        n--;
        for(i=1;i<=n;i++)
        {
            for(j=c+1;j<=m;j++)
            v[i][j-1]=v[i][j];
        }
        m--;
         for(i=1;i<=n;i++)
                {for(j=1;j<=m;j++)
                g<<v[i][j]<<' ';
                g<<'\n';
                }


}
