#include<fstream>
using namespace std;
int main()

{
   ifstream f("siruri1.in");
   ofstream g("siruri1.out");
   int n,x[32001],y[32001],i,j;
    f>>n;
    for(i=1;i<=n;i++)
        f>>x[i];
        for(i=1;i<=n;i++)
        y[i]=1;
        for(i=1;i<=n-1;i++)
        {
            for(j=i+1;j<=n;j++)
            if(x[i]>x[j])
            y[i]=y[i]+1;
            else y[j]=y[j]+1;
        }
        for(i=1;i<=n;i++)
        g<<y[i]<<' ';
}
