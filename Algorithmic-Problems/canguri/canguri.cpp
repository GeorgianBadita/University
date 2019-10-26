#include<fstream>
using namespace std;
int n;
ifstream f("cangur.in");
ofstream g("cangur.out");
int main()
{   int p=7;
    f>>n;
    while(n-1)
    {
        p+=p*10;
        n--;
    }
    g<<p+14;
}
