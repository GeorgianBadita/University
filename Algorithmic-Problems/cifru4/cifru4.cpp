#include<fstream>
using namespace std;
int w[100],v[100];
int main()
{
    ifstream f("cifru4.in");
    ofstream g("cifru4.out");
    int a,t=0,n=0,p,i,n1,j,k=0;
    f>>a;
    n1=a;
    while(n1!=0)
     {
         n1/=10;
         n++;
     }
     p=1; n1=a;
     for(i=0;i<n;i++)
        {
            v[i]=n1/p;
            p*=10;
            if(v[i]%n==0)
              k++;
              else w[t++]=v[i];
        }
        for(i=0;i<t-1;i++)
        for(j=i+1;j<=t;j++)
            if((w[j]-w[i])%n==0) k++;
            g<<k;
            return 0;


}
