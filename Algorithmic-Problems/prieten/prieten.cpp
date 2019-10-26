#include<fstream>
using namespace std;
ifstream f("prieten.in");
ofstream g("prieten.out");
int main()
{
    int ok,n1,j,m,r,x,n,k,i,v[100001];
    unsigned long long s;
    f>>n>>k;
    x=1;
    for(i=1;i<=k;i++)
    {
        v[i]=x*n+x;
        g<<v[i]<<' ';
        x++;
    }
    g<<'\n';
    f>>s;
    ok=1; n1=2;
    while(ok==1)
    {
        for(i=n1;i>=n1;i--)
        {   j=i;
            if(2*s%(n1-1)==0&&2*s%n1==0&&2*s%(n1+1)==0&&(n1-1)*n1*(n1+1)==2*s)
             {g<<j<<' '; ok=0; break;}
        }
        n1++;
    }
    return 0;
}
