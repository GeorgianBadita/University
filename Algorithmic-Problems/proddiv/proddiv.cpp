#include<fstream>
using namespace std;
ifstream f("proddiv.in");
ofstream g("proddiv.out");
int v[500000]={0},w[500000],a,b,p=1;
void ciur()
{
    long long i,j;
    w[0]=2;
    for(i=3;i<=b/2;i+=2)
    {
        if(v[i]==0)
        {
            w[p]=i;
            p++;
            for(j=i*i;j<=b/2;j+=2*i)
            v[j]=1;
        }
    }
}
int main()
{
    long long j,i,nr=0,q;
    f>>a>>b;
    ciur();
    for(i=0;i<p;i++)
    g<<w[i]<<' ';
    return 0;
    for(i=0;i<=p-2;i++)
    for(j=i+1;j<=p-1;j++)
    {q=w[i]*w[j];
    if(q>=a&&q<=b) nr++;
    else if(q>b) break;
    }
    for(i=0;i<=p-1;i++)
    {
        q=w[i]*w[i]*w[i];
        if(q>=a&&q<=b) nr++;
        else if(q>b) break;
    }
    g<<nr;
}
