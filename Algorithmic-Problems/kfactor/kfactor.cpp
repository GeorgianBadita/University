#include<fstream>
#define Kmax 100001
#define MAX 5000001
using namespace std;
ifstream f("kfactor.in");
ofstream g("kfactor.out");
int x[Kmax],prime[Kmax],v[MAX],np=0,k,a,b;
void ciur()
{
    int i,j;
    prime[0]=2;
    for(i=3;i<=k;i+=2)
    if(x[i]==0)
    {
        prime[++np]=i;
        for(j=i+i;j<=k;j+=i)
        x[j]=1;
    }

}
int main()
{
    int i,j,r,st,nr=0;
    f>>k>>a>>b;
    ciur();
   for(i=a;i<=b;i++)v[i-a+1]=i;
   for(i=0;i<=np;i++)
   {
       r=a%prime[i];
       if(r==0) st=1;
       else st=prime[i]-r+1;
       for(j=st;j<=b-a+1;j+=prime[i])
       while(v[j]%prime[i]==0)
       v[j]=v[j]/prime[i];
   }
   for(i=1;i<=b-a+1;i++)
   if(v[i]==1) nr++;
   g<<nr;

}

