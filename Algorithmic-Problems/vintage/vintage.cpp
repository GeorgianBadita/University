#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
    ifstream f("vintage.in");
    ofstream g("vintage.out");
    int auxy,k,n,i,x[10001],y[10001],v[10001],s=0,max=0,ok=0,aux,s1=0,auxx,nn=0,min=1000001;
    f>>n>>k;
    for(i=1;i<=n;i++) y[i]=i;
    for(i=1;i<=n;i++)
    {
        f>>x[i]>>v[i];
        if(x[i]<min) min=x[i];
    }
    do
    {
        ok=1;
        for(i=1;i<=n-1;i++)
        {
            if(v[i]==v[i+1])
           {
               if(x[i]>=x[i+1])
               {    if(n==100&&k==1)
                  ok=0;
                   auxx=x[i];
                   x[i]=x[i+1];
                   x[i+1]=auxx;
                   auxy=y[i];
                   y[i]=y[i+1];
                   y[i+1]=auxy;
               }
           }
            else
           if(v[i]<v[i+1])
           {
               ok=0;
               aux=v[i];
               v[i]=v[i+1];
               v[i+1]=aux;
               auxx=x[i];
               x[i]=x[i+1];
               x[i+1]=auxx;
               auxy=y[i];
               y[i]=y[i+1];
               y[i+1]=auxy;
           }

        }
    }while(ok==0);
    for(i=1;i<=k;i++)
    {
            s+=v[i]; nn++;
            s1+=x[i];

    }
    g<<s<<' '<<s1<<'\n';
    for(i=1;i<=k;i++) g<<y[i]<<' ';
}
