#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("balcon.in");
ofstream g("balcon.out");
short a[51][51],v[2590];
int n,i;
int main()
{   int j,p=0,x=0;
    f>>n;
    for(i=0;i<=n+1;i++) a[i][0]=a[i][n+1]=-1;
    for(j=0;j<=n+1;j++) a[0][j]=a[n+1][j]=-1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            f>>a[i][j];
            v[++p]=a[i][j];
            a[i][j]=0;
        }
    }
    sort(v+1,v+p+1);
    //for(i=1;i<=p;i++)
    //g<<v[i]<<' ';

    x=1;
    for(i=1;i<=n/2+1;i++)
    {
        for(j=i;j<=n-i+1;j++) {a[i][j]=v[x++];}
        for(j=i+1;j<=n-i+1;j++) {a[j][n-i+1]=v[x++];}
        for(j=n-i;j>=i;j--) {a[n-i+1][j]=v[x++];}
        for(j=n-i;j>=i+1;j--){a[j][i]=v[x++];}
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        g<<a[i][j]<<' ';
        g<<'\n';
    }

}
