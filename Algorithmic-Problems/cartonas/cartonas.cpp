#include<cstdio>
using namespace std;
int v[101],s[101];
int main()
{
    freopen("cartonas.in","r",stdin);
    freopen("cartonas.out","w",stdout);
    int z,n,x,i,p=0;
    scanf("%d%d",&n,&x);
    for(i=1;i<=n;i++) scanf("%d",&v[i]);
    z=n;
    while(n>2) {
   for(i=1;i<=z;i++)
   {
       s[++p]=v[i]+v[i+1];
       v[i]=s[p-1]; v[i+1]=s[p];
   }
   z--;
   n--;
    }
   printf("%d",s[p]);
}
