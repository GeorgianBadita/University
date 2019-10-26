#include<fstream>
#include<iostream>
using namespace std;
int main()
{
    ifstream f("cladiri.in");
    ofstream g("cladiri.out");
    int c,max=0,ras,nr=0,n,v[10001],i,x,nrmax=0,k,t,j,cuburi=0;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>v[i];
        ras=0; x=v[i];
        while(x!=0)
        {
            ras=ras*10+x%10;
            x/=10;
            k++;
        }
        if(ras==v[i])
        nr++;


    }

    for(i=1;i<=n;i++)
    {
        x=v[i];
        while(x!=0)
        {
          c=x%10;
          if(c>max) max=c;
          x/=10;
        }

    }
    for(i=1;i<=n;i++)
    {   t=0;
        x=v[i];
        while(x!=0)
        {
            c=x%10;
            if(c==max) t++;
            if(t!=0&&t<2&&c==max) nrmax++;
            x/=10;

        }
    }
    g<<max<<' '<<nrmax<<'\n'<<nr<<'\n';
    for(i=1;i<=n;i++)
    {   x=v[i];
        k=0; ras=0;
        while(x!=0)
        {
            ras=ras*10+x%10;
            k++;
            x/=10;
        }
        if(ras!=v[i])
             for(j=1;j<=k/2;j++)
        {
            if(v[i]%10>ras%10)
            cuburi+=(v[i]%10-ras%10);
            else
            cuburi+=(ras%10-v[i]%10);
            v[i]/=10;
            ras/=10;
        }
    }
    g<<cuburi;

}
