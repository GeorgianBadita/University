#include<fstream>
using namespace std;
ifstream f("scaune.in");
ofstream g("scaune.out");
int n;
long long p=1;
int main()
{
    f>>n;
    for(int i=1;i<=2*n-1;i+=2)
    {
        p=(p*i)%30103;
    }
    g<<p;
}
