#include<fstream>
using namespace std;
ifstream f("taxe1.in");
ofstream g("taxe1.out");
int b[101][101],a[100][100],s,n,lin[10001],col[10001],p,u;
int main(),
{
    int i,j;
    f>>s>>n;
    for(i=0;i<=n+1;i++) {a[i][0]=a[i][n+1]=-1; b[i][0]=b[i][n+1]=-1;}
    for(j=0;j<=n+1;j++) {a[0][j]=a[n+1][j]=-1; b[0][j]=b[n+1][j]=-1;}
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {f>>a[i][j]; b[i][j]=a[i][j];}
    b[1][1]=1; lin[1]=1; col[1]=1; p=1; u=1;
    while(p<=u)
    {
        i=lin[p]; j=col[p];
        if(i>1&&b[i-1][j]==0)
        {
            b[i-1][j]=b[i][j]+1; u++; lin[u]=i-1; col[u]=j;
            if(lin[u]==n;&&col[u]==n) break;
        }
        if(i<n&&b[i+1][j]==0)
        {
            b[i+1][j]=b[i][j]+1; u++; lin[u]=i+1; col[u]=j;
            if(lin[u]==n;&&col[u]==n) break;
        }
        if(j>1&&b[i][j-1]==0)
        {
            b[i][j-1]=b[i][j]+1; u++; lin[u]=i; col[u]=j-1;
            if(lin[u]==n;&&col[u]==n) break;
        }
        if(j<m&&b[i][j+1]==0)
        {
            b[i][j+1]=b[i][j]+1; u++; lin[u]=i; col[u]=j+1;
            if(lin[u]==n;&&col[u]==n) break;
        }
        p++;
    }
}
