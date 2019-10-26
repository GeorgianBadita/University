#include<fstream>
using namespace std;
int main()
{
    ifstream f("culegere.in");
    ofstream g("culegere.out");
    int s,i,n,p,m,ne,x,k=0,t=0,p1=1;
    f>>p>>n;
    ne=p*(p+1)/2;
    x=ne;
    while(x>0)
    {k++;
     x/=10;
    }
    for(i=1;i<=k-1;i++)
    {
        t=t+i*p1; p1*=10;
    }
    t=t*9+(ne-p1+1)*k;
    g<<t<<'\n';
    m=0; s=0;
    while(s<n)
    {
        m++; s+=m;
    }
    g<<m;
}
