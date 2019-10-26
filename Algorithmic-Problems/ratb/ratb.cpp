#include<cstdio>
using namespace std;
int v[10000];
int main()
{
    freopen("ratb.in","r",stdin);
    freopen("ratb.out","w",stdout);
    int s,smax=-5000000,i,j,n,k,x,y;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++) scanf("%d",&v[i]);
    for(i=1;i<=n;i++)
    {
        s=0;
        for(j=i;j<=n;j++)
        {
            s+=v[j];
            if(s>smax&&j-i>=k-1) x=i,y=j,smax=s;
        }
    }
    printf("%d\n%d %d",smax,x,y);
}
