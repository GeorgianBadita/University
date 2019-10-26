#include<cstdio>
#include<algorithm>
using namespace std;
int maxxm,n,a[1000005],b[1000005],m,j,i,k,s1,s2;
int main()
{
    freopen("bal.in","r",stdin);
    freopen("bal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&k,&j);
        a[k]++;
        a[j+1]--;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&k,&j);
        b[k]++;
        b[j+1]--;
    }
    int maxx=-2000000000;
    for(i=0;i<=1000005;i++)
    {
        s1=s1+a[i];
        s2=s2+b[i];
        if(min(s1,s2)>maxx) maxx=min(s1,s2);
    }
    printf("%d",maxx);
    return 0;

}
