#include<fstream>
#include<cmath>
using namespace std;
int main()
{
    ifstream f("porumb1.in");
    ofstream g("porumb1.out");
    int a,n,x,k=0,u=0;
    unsigned long long j;
    f>>n>>x;
    g<<(n+1)/2<<'\n';
    a=n;
    while(a!=1)
    {
        a/=2;
        k++;
    }
    g<<k+1<<'\n';
    if(x%2==1)
     g<<1;
     else
     {
         while(x%2==0)
          { x/=2;
            u++;
          }
          g<<u+1<<'\n';
     }
     j=pow((float)2,(int)k);
     g<<j;
     return 0;
}
