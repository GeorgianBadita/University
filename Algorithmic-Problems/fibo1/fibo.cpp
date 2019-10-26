#include<fstream>
using namespace std;
ifstream fin("fibo1.in");
ofstream g("fibo1.out");
void fibonacci()
{
    int n,i,f[25001];
    fin>>n;
    f[1]=f[2]=1;
    for(i=3;i<=25000;i++)
    {
        f[i]=f[i-1]+f[i-2];
        f[i]=f[i]%46337;
    }
    if(n%2==0) g<<0<<'\n';
    else g<<1<<'\n';
    if(n%2==0) {g<<n/2-1<<' '; g<<n/2+1<<'\n';}
    else {g<<n/2<<' '; g<<n/2+1<<'\n';}
    if(n%2==0) {g<<f[n/2-1]<<'\n'; g<<f[n/2+1]<<'\n';}
    else {g<<f[n/2]<<'\n'; g<<f[n/2+1]<<'\n';}
    g<<f[n]%46337;
}
int main()
{
    fibonacci();
}
