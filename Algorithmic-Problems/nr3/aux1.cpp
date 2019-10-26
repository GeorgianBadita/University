#include<iostream>
using namespace std;
int main()
{
int i,n,v[20],nr=0,k,poz;
cout<<"n=";cin>>n;
cout<<"poz=";cin>>poz;
for(i=1;i<=n;i++) cin>>v[i];
for(i=1;i<=n;i++)
if(v[i]<0) nr++;
for(i=n+1;i>=poz;i--)
v[i+1]=v[i];
v[poz]=nr;
for(i=1;i<=n+1;i++) cout<<v[i]<<" ";
}


