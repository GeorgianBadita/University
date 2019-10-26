#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int v[501],x[501],k[501];
int n,nr=0,r[200];
int main()
{
    freopen("concurs.in","r",stdin);
    freopen("concurs.out","w",stdout);
    int i,p=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&v[i],&k[i]);
       x[i]=v[i];

    }
    sort(x+1,x+n+1);
    for(i=1;i<=n;i++)
   if(x[i]!=x[i+1]) nr++;
   printf("%d\n",nr);
   for(i=1;i<=n;i++)
   {    r[++p]=1;
       while(x[i]==x[i+1]) {r[p]++; i++;}
   }
   sort(r+1,r+p+1);
   for(i=p;i>=1;i--) cout<<r[i]<<' ';
   cout<<'\n';
   for(i=1;i<=n;i++)
   cout<<v[i]<<' '<<k[i]<<'\n';
}
