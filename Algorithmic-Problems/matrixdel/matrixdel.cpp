#include<fstream>
using namespace std;
int main()
{
    ifstream f("matrixdel.in");
    ofstream g("matrixdel.out");
    int a[100][100],i,j,n,m,q[100],p;
    f>>n>>m;
    for(j=0;j<=n;j++)
        a[1][j]=m-1+j;

    for(i=0;i<=n;i++)
        a[i][1]=m-1+i;

       for(i=2;i<=n;i++)
       for(j=2;j<=n;j++)
       a[i][j]=(a[i-1][j]+a[i][j-1])%1000;

      for(i=1;i<=n;i++)
      {
          for(j=1;j<=n;j++)
            g<<a[i][j]<<' ';
            g<<'\n';
      }

}
