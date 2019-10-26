#include<cstdio>
#include<vector>
using namespace std;
vector<int>v;
int main()
{
    int n,i,x,maxpar=0,k;
    freopen("alice.in","r",stdin);
    freopen("alice.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x%2==0&&maxpar<x) maxpar=x;
    }
    printf("%d",maxpar);
}
