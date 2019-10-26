#include<fstream>
using namespace std;
int cmmdc(int a, int b)
{
    int r;
    while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        return a;
}
int main()
{
    ifstream f("cmmdcsecvmax.in");
    ofstream g("cmmdcsecvmax.out");
    int n,v[10000],i,nr,sol,maxs=0;
    f>>n;
    for(i=1;i<=n;i++)
        {   f>>v[i]; sol=1;
            nr=cmmdc(v[i],v[i+1]);
            while(nr==cmmdc(nr,v[i+2])) sol++,i++;
            if(sol>maxs) maxs=sol;
        }
        g<<maxs;
}
