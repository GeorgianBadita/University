#include<cstdio>
using namespace std;
int v[2501];
int main()
{
    freopen("matriosca.in","r",stdin);
    freopen("matriosca.out","w",stdout);
    int j,n,i,ls,ld;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
    }
    for(i=1;i<=n;i++)
    {
         ls=i; int nr=0;
        while(v[i]<v[i+1]) {nr++;i++;ld=i;}
        printf("%d ",nr);
        for(j=ls;j<=ld;j++) printf("%d ",j);
        printf("%d\n");
    }
}
