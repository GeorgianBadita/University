#include<cstdio>
using namespace std;
int v[700000];
int main()
{
    freopen("livada1.in","r",stdin);
    freopen("livada1.out","w",stdout);
    int n,m,p,k,max=0;
    scanf("%d%d%d",&m,&n,&p);
    int i,j;
    int rsm=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",&v[j]);
        j=0;
        int rmax=0;
        while(j<n-1)
        {
            int k=j+1;
            while(k<n&&v[k]==v[j]) k++;
            if(k-j>rmax)
            {
                rmax=k-j;
            }
            j=k;
        }

    if(rmax>max) max=rmax;
    int sm=v[0],cnt=1;
    for(j=1;j<n;j++)
    if(cnt==0) sm=v[j],cnt=1;
    else if(v[j]==sm) cnt++;
    else cnt--;
    if(cnt==0) sm=0;
    else
    {
        cnt=0;
        for(j=0;j<n;j++)
        if(v[j]==sm) cnt++;
        if(cnt<(n/2)+1) sm=0;
    }
        if(sm!=0) rsm++;
    }
    printf("%d\n%d",rsm,max);
}
