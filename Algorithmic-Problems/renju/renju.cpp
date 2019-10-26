#include<fstream>
#include<iostream>
using namespace std;
ifstream f("gomoku.in");
ofstream g("gomoku.out");
 int a[200][200];
int nr1=0,nr2=0,nr3=0,ok=1;
int main()
{   int n,i,j;
    n=19;
    for(i=0;i<=n+1;i++) a[i][0]=a[i][n+1]=-1;
    for(j=0;j<=n+1;j++) a[0][j]=a[n+1][j]=-1;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    f>>a[i][j];
    for(i=15;i<=n;i++)
    {
        for(j=6;j<=n;j++)
        {
            if(a[i][j]!=0&&a[i][j+1]!=-1&&a[i][j+2]!=-1&&a[i][j-1]!=-1&&a[i][j-2]==-1&&a[i][j]==a[i][j+1]&&a[i][j]==a[i][j+2]&&a[i][j]==a[i][j-1]&&a[i][j]==a[i][j-2]) nr1=5;
            else if(a[i][j]!=0&&a[i+1][j]!=-1&&a[i+2][j]!=-1&&a[i-1][j]!=-1&&a[i-2][j]!=-1&&a[i][j]==a[i+1][j]&&a[i][j]==a[i+2][j]&&a[i-1][j]==a[i][j]&&a[i-2][j]==a[i][j]) nr2=5;
            else if(a[i][j]!=0&&a[i+1][j+1]!=-1&&a[i+2][j+2]!=-1&&a[i-1][j-1]!=-1&&a[i-2][j-2]!=-1&&a[i][j]==a[i+1][j+1]&&a[i][j]==a[i+2][j+2]&&a[i-1][j-1]==a[i][j]&&a[i-2][j-2]==a[i][j]) nr3=5;
                if(nr1==5||nr2==5||nr3==5)
                {
                    if(nr1==5&&a[i][j]==1) g<<1<<'\n'<<i-2<<' '<<j<<'\n'; else
                    if(nr1==5&&a[i][j]==2) g<<2<<'\n'<<i-2<<' '<<j<<'\n'; else
                    if(nr2==5&&a[i][j]==1) g<<1<<'\n'<<i<<' '<<j-2<<'\n'; else
                    if(nr2==5&&a[i][j]==2) g<<2<<'\n'<<i<<' '<<j-2<<'\n'; else
                    if(nr3==5&&a[i][j]==1) g<<1<<'\n'<<i-2<<' '<<j-2<<'\n'; else
                    if(nr3==5&&a[i][j]==2) g<<2<<'\n'<<i-2<<' '<<j-2<<'\n';
                    ok=0; break;
                }
        }
        if(ok==0) break;
    }
    if(ok==1) g<<0<<'\n';
    //cout<<sizeof(a)/1204*1024;
}
