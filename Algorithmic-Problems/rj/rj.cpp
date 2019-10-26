#include<fstream>
using namespace std;
ifstream f("rj.in");
ofstream g("rj.out");
int r[102][102],lin[10202],col[10202],col1[10202],lin1[10202],w[102][102];
char a[102][102],c;
int n,m,i,j,x1,x2,y2,p1,p,u1,u,tmin=10202,xmin=-1,ymin=-1;
int l1;
void citire()
{
    f>>n>>m;
for(i=0;i<=n+1;i++) {a[i][0]=a[i][m+1]='X';r[i][0]=r[i][m+1]=-1;w[i][0]=w[i][m+1]=-1;}
for(j=0;j<=m+1;j++) {a[0][j]=a[n+1][j]='X';r[0][j]=r[n+1][j]=-1;w[0][j]=w[n+1][j]=-1;}
    f.get(c);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            f.get(c); a[i][j]=c;
            if(a[i][j]=='R') {x1=i;l1=j;}
            if(a[i][j]=='J') {x2=i;y2=j;}
            if(a[i][j]=='X') {r[i][j]=w[i][j]=-1;}
            if(a[i][j]==' ') {r[i][j]=w[i][j]=0;}
        }
        f.get(c);
    }
}
void lee()
{
    r[x1][l1]=1; lin[1]=x1; col[1]=l1; p=1; u=1;
    while(p<=u)
    {   i=lin[p]; j=col[p];
        if(i>1&&r[i-1][j]==0)
        {
           r[i-1][j]=r[i][j]+1; u++; lin[u]=i-1; col[u]=j;
        }
        if(i<n&&r[i+1][j]==0)
        {
            r[i+1][j]=r[i][j]+1; u++; lin[u]=i+1; col[u]=j;
        }
        if(j>1&&r[i][j-1]==0)
        {
            r[i][j-1]=r[i][j]+1; u++; lin[u]=i; col[u]=j-1;
        }
        if(j<m&&r[i][j+1]==0)
        {
            r[i][j+1]=r[i][j]+1; u++; lin[u]=i; col[u]=j+1;
        }
        if(i>1&&j>1&&r[i-1][j-1]==0)
        {
            r[i-1][j-1]=r[i][j]+1; u++; lin[u]=i-1; col[u]=j-1;
        }
        if(i<n&&j<m&&r[i+1][j+1]==0)
        {
            r[i+1][j+1]=r[i][j]+1; u++; lin[u]=i+1; col[u]=j+1;
        }
        if(i>1&&j<m&&r[i-1][j+1]==0)
        {
            r[i-1][j+1]=r[i][j]+1; u++; lin[u]=i-1; col[u]=j+1;
        }
        if(i<n&&j>1&&r[i+1][j-1]==0)
        {
            r[i+1][j-1]=r[i][j]+1; u++; lin[u]=i+1; col[u]=j-1;
        }
        p++;
    }
    w[x2][y2]=1; lin1[1]=x2; col1[1]=y2; p1=1; u1=1;
    while(p1<=u1)
    {
        i=lin1[p1]; j=col1[p1];
        if(i>1&&w[i-1][j]==0)
        {
            w[i-1][j]=w[i][j]+1; u1++; lin1[u1]=i-1; col1[u1]=j;
        }
        if(i<n&&w[i+1][j]==0)
        {
            w[i+1][j]=w[i][j]+1; u1++; lin1[u1]=i+1; col1[u1]=j;
        }
        if(j>1&&w[i][j-1]==0)
        {
            w[i][j-1]=w[i][j]+1; u1++; lin1[u1]=i; col1[u1]=j-1;
        }
        if(j<m&&w[i][j+1]==0)
        {
            w[i][j+1]=w[i][j]+1; u1++; lin1[u1]=i; col1[u1]=j+1;
        }
        if(i>1&&j>1&&w[i-1][j-1]==0)
        {
            w[i-1][j-1]=w[i][j]+1; u1++; lin1[u1]=i-1; col1[u1]=j-1;
        }
        if(j<m&&i<n&&w[i+1][j+1]==0)
        {
            w[i+1][j+1]=w[i][j]+1; u1++; lin1[u1]=i+1; col1[u1]=j+1;
        }
        if(i>1&&j<m&&w[i-1][j+1]==0)
        {
            w[i-1][j+1]=w[i][j]+1; u1++; lin1[u1]=i-1; col1[u1]=j+1;
        }
        if(i<n&&j>1&&w[i+1][j-1]==0)
        {
            w[i+1][j-1]=w[i][j]+1; u1++; lin1[u1]=i+1; col1[u1]=j-1;
        }
        p1++;
    }
}
void rezolvare()
{
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(r[i][j]==w[i][j])
                if(w[i][j]<tmin&&w[i][j]!=-1&&w[i][j]!=0)
                {tmin=w[i][j];xmin=i;ymin=j;}
        }
    }
    g<<tmin<<' '<<xmin<<' '<<ymin;
}
int main()
{
    citire();
    lee();
    rezolvare();
    return 0;
}
