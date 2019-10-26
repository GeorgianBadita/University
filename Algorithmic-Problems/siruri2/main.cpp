#include<cstdio>
#include<cstring>
using namespace std;
int n,m,c[501][501],cost;
char a[501],b[501];
int min(int a, int b, int c)
{
    if(a<b&&a<c) return a;
    if(b<a&&b<c) return b;
    if(c<a&&c<b) return c;
}
int levenstein(char a[], char b[],int n, int m)
{   int i,j;
    for(i=0;i<=n;i++) c[i][0]=i;
    for(j=0;j<=m;j++) c[0][j]=j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            cost=0;
            else
            {
                cost=1;
                c[i][j]=min(c[i-1][j]+1,c[i][j-1]+1,c[i-1][j-1]+cost);
            }
        }
    }
    return c[n][m];
}
int main()
{
        freopen("siruri2.in","r",stdin);
        freopen("siruri2.out","w",stdout);
       int x;
        gets(a);
        scanf("\n");
        gets(b);
        n=strlen(a); m=strlen(b);
        x=levenstein(a,b,n,m);
        printf("%d",x);
        return 0;
}
