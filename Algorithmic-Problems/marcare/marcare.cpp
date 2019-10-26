#include<fstream>
# define Nmax 1001
using namespace std;
ifstream f("marcare.in");
ofstream g("marcare.out");
int m[Nmax];
int main()
{
    int n,s,k,i;
    f>>n>>s>>k;
    for(i=0;m[(s+i*k)%n+n*((s+i*k)%n==0)]==0;i++)
    {
        g<<(s+i*k)%n+n*((s+i*k)%n==0)<<' ';
        m[(s+i*k)%n+n*((s+i*k)%n==0)]=1;
    }
    g<<'\n';
    g<<n-i<<'\n';
}



