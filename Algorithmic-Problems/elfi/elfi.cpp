#include<fstream>
using namespace std;
int v[14400];
int main()
{
    ifstream f("elfi.in");
    ofstream g("elfi.out");
    int c,i,n,x,p,s,j,t,max=0;
    f>>n;

    for(i=1;i<=n;i++)
    {
        f>>c>>p;
        t=2*c+p+1;
        x=t;
        while(x<14400)
           {
            v[x]++;
            x+=t;
           }

    }
    for(i=1;i<=14400;++i)
    {
        if(v[i]>max) max=v[i];
    }
    g<<max;
}
