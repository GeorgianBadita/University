#include<fstream>
#include<vector>
#include<cmath>
using namespace std;
ifstream f("jocprim.in");
ofstream g("jocprim.out");
vector<int>v;
int prim(int n)
{
    if(n<2) return 0;
    if(n==2) return 1;
    for(int i=2;i<=sqrt((double)n);i++)
    if(n%i==0) return 0;
    return 1;
}
int main()
{
    int x,n,i;
    f>>n;
    for(i=0;i<n;i++)
    {
        f>>x;
        v.push_back(x);
    }
    for(i=0;i<n;i++)
    {
        if(prim(v[i])==1)
        for(int j=i+1;j<=2*i;j++)
    }
}
