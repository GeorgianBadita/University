#include<fstream>
using namespace std;
ifstream f("secvb.in");
ofstream g("secvb.out");
int b2(int x)
{
    int r,ras=0,v=0;
    while(x!=0)
    {
        r=x%2;
        x/=2;
        ras=ras*10+r;
    }
    while(ras!=0)
    {
        v=v*10+ras%10;
        ras/=10;
    }
    return v;

}
int nr1(int y)
{   int nr=0;
    while(y!=0)
    {
        if(y%10==1)
        nr++;
        y/=10;
    }
    return nr;
}
int v[1000],a[1000],x[1000];
int main()
{
    int n,t,i,ok=0,nr=0,s;
    f>>n>>t;
    for(i=1;i<=n;i++) f>>v[i];
    for(i=1;i<=n;i++)
        a[i]=b2(v[i]);
        for(i=1;i<=n;i++)
        {x[i]=nr1(a[i]);} //g<<x[i]<<' ';}
        for(i=1;i<=n;i++)
        {   s=0; ok=1;
        if(x[i]==t) nr++;
          //do {s+=x[i];i++;ok=0;}while(s==t);
            if(ok==0) nr++;
        }
        g<<nr;
        return 0;

}
