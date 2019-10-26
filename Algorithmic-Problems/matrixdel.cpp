#include <fstream>
using namespace std;
int main()
{
   ifstream f("matrixdel.in");
   ofstream g("matrixdel.out");
   int v[100][100],n,m,i,j,l,c;
   f>>n>>l;

        for(i=0;i<=n;i++)
            v[i][1]=l-1+i;
            for(j=0;j<=n;j++)
                v[1][j]=l-1+j;
                for(i=2;i<=n;i++)
                    for(j=2;j<=n;j++)
                        v[i][j]=(v[i][j-1]+v[i-1][j])%1000;

                     for(i=1;i<=n;i++)
                        {
                            for(j=1;j<=n;j++)
                                g<<v[i][j]<<' ';
                                g<<'\n';
                        }

}
