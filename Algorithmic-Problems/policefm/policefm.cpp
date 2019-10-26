#include <fstream>
using namespace std;

int main()
{
    ifstream in("policefm.in");
    ofstream out("policefm.out");
    long long int p; int n[21]={0};
    in>>p;
    if (p<=9 && p>=1){ out<<p; return 0;} else if (!p){ out<<10; return 0;}
    for (int i=9;i>1;)
        if (!(p%i)) n[++n[0]]=i, p/=i;
        else --i;
    if (!n[0]) out<<0;
    else
        for (int i=n[0];i>0;--i) out<<n[i];
    return 0;
}
