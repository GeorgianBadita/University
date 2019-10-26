#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
vector<int>v;
int main()
{
    freopen("meteo.in","r",stdin);
    freopen("meteo.out","w",stdout);
    int s=0,s1=0,x,i,n,p,k;
    scanf("%d%d%d",&n,&p,&k);
      for(i=0;i<k;i++)
      {
          scanf("%d",&x);
          v.push_back(x);
      }
      sort(v.begin(),v.end());
      int nr=0;
      for(i=0;i<k;i++)
      {
          if(v[i]!=v[i+1]) {s+=v[i];nr++;}
          if(nr==n) break;
      }
      printf("%d ",s/n);
      nr=0;
      for(i=k-1;i>=0;i--)
      {
          if(v[i]!=v[i-1]) {s1+=v[i];nr++;}
          if(nr==p) break;
      }

      printf("%d",s1/p);
      return 0;
}
