#include<cstdio>
#include<algorithm>
using namespace std;
int n,i,j,k,v[20000005];
int main()
{
    freopen("interclasari.in","r",stdin);
    freopen("interclasari.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&j);
        for(j;j>=1;j--,k++)
        {
            scanf("%d",&v[k]);
        }
    }
    sort(v,v+k);
    printf("%d\n",k);
    for(i=0;i<k;i++)
    printf("%d ",v[i]);
}
