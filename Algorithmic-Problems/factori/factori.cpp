#include<cstdio>
#include<vector>
using namespace std;
vector<bool>ciur(20000);
vector<int>v(20000,0);
vector<int>fr;
int n,p=0;
void ciu()
{
    int i,j;
    v[p]=2;
    for(i=3;i<=n;i+=2)
    {
        if(ciur[i]==false)
        {
            v[++p]=i;
            for(j=i;j*i<=n;j+=2)
            ciur[i*j]=true;
        }
    }
}
int main()
{
    freopen("factori.in","r",stdin);
    freopen("factori.out","w",stdout);
    scanf("%d",&n);
    int j,x,i,fact=1;
    ciu(); x=1;
    while(x!=0)
    {      unsigned long long p1=1;
        scanf("%d",&x);
        for(i=1;i<=x;i++)
        {
            p1*=i;
        }
        printf("%d\n",p1);
    }
    //for(j=0;j<=p;j++) if(fr[j]>0) printf("%d\n",fr[j]);
}
