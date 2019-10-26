#include<fstream>
#include<cmath>
using namespace std;
int v[10000];
int main()
{
    ifstream f("divider.in");
    ofstream g("divider.out");
    int a,b,n,m,nr=1,i,ok,x;
    f>>a>>b>>n;
    m=pow(((double)a*(double)b),(double)n);
    for(i=1;i<=sqrt((float)m);i++)
        {
            if(m%i==0)
            {v[++nr]=i; v[++nr]=m/i;}
        }
        do
        {
            ok=1;
            for(i=1;i<=nr-1;i++)
            {
                if(v[i]>v[i+1])
                {
                    ok=0;
                    x=v[i];
                    v[i]=v[i+1];
                    v[i+1]=x;
                }
            }
        }while(ok==0);
        for(i=2;i<=nr;i++)
            if(v[i]!=v[i+1])
             g<<v[i]<<' ';

}

