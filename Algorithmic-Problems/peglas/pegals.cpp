#include<fstream>
using namespace std;
ifstream f("pegals.in");
ofstream g("pegals.out");
int n,k;
int main()
{
    f>>n;
    k=n/2;
    if(n%2==0) g<<3<<'\n'<<1<<' '<<k-1<<' '<<2*k;
    else g<<3<<'\n'<<1<<' '<<k<<' '<<n-1;
    return 0;
}
