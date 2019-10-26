#include<fstream>
using namespace std;
ifstream f("conturi.in");
ofstream g("conturi.out");
int pcif(int x)
{
    while(x>9)
    {
        x/=10;
    }
    return x;
}
int main()
{
    int n,i;
    int y,k,x,s,smax=0;
    f>>n>>k;
    for(i=1;i<=n;i++)
    {
        f>>x; y=x;
        if(((x/10000))%10==1&&pcif(y)==k)
        {s=x%10000;
        if(s>smax) smax=s;}
    }
    g<<smax;
}
