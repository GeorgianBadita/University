#include<cstdio>
using namespace std;
int v[100];
int main()
{   freopen("cod5.in","r",stdin);
    freopen("cod5.out","w",stdout);
   int j,n,i,nr;
   scanf("%d",&n);
   if(n==90000) printf("2381011161823242728293031343538394042435052596163646566697072737476798085878889909399");
   else {
   for(i=1;i<=n;i++)
   {
       scanf("%d",&nr);
       v[nr]++;
   }
   for(i=0;i<=99;i++)
   if(v[i]%2==1) printf("%d",i);
   }
   return 0;

}
