#include<fstream>
using namespace std;
int euclid(int a, int b)
{
    if(!b) return a;
    return euclid(b, a%b);
}
int t,a,b,i,j;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(;t;--t)
    {
        f>>a>>b;
        g<<euclid(a,b); g<<'\n';
    }
    return 0;
}
