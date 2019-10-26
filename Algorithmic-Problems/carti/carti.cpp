#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
int poz[100001];
int main()
{
    int i,n,x,rez=0;
    freopen("carti1.in","r",stdin);
    freopen("carti1.out","w",stdout);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x); poz[x-1]=i;
    }
    for(i=0;i<n-1;i++)
    if(poz[i]>poz[i+1]) rez++;
    //cout<<sizeof(poz)/(1024*1024);
    printf("%d",rez);
}
