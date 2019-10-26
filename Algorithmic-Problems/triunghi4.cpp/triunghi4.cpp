# include <fstream>
using namespace std;

ifstream f("triunghi4.in");
ofstream g("triunghi4.out");

long long L[2][1001];
long long i, n, j, k, v[1001], p[1001];
int main()
{
    f>>n;
    for (i=n; i>0; --i)
    {
        f>>p[i]>>v[i];
    }
    L[0][1]=v[1];
    for (i=2; i<=n; ++i)
        {
            //refac linia i
            j=p[i];
            L[1][j]=(long long)v[i];
            //refac stanga
            k=j-1;
            while (k)
            {
                L[1][k]=L[0][k]-L[1][k+1];
                --k;
            }
            //refac dreapta
            k=j+1;
            while (k<=i)
            {
                L[1][k]=L[0][k-1]-L[1][k-1];
                ++k;
            }
            //copiez linia
            for (j=1; j<=i; ++j)
                L[0][j]=L[1][j];
        }
    for (j=1; j<n; ++j)
        g<<L[1][j]<<' ';
    g<<L[1][n]<<'\n';

    return 0;
}
