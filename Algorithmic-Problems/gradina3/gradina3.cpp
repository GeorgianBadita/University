#include<cstdio>
using namespace std;
int x,y,i,j,a[1001][1001],n,m,p,k;
int main()
{
    freopen("gradina3.in","r",stdin);
    freopen("gradina3.out","w",stdout);
    scanf("%d%d%d",&n,&p,&k);
    for(i=1;i<=p;i++)
    {   scanf("%d%d",&x,&y);
        a[x][y]=1;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }
}
