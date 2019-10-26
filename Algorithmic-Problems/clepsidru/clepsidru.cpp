#include<fstream>
using namespace std;
int main()
{
    ifstream f("clepsidru.in");
    ofstream g("clepsidru.out");
    int n,b,k;
    f>>n>>b>>k;
    g<<n+b-1<<'\n';

    return 0;
}
