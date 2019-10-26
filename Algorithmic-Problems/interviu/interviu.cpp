#include<fstream>
using namespace std;
int main()
{
    ifstream f("interviu.in");
    ofstream g("interviu.out");
    int n,x,i,j,max=0,ok;
    f>>n;
    for(i=1;i<=3;i++)
    {
        f>>x;
        if(max<x) max=x;
    }
    ok=1;
    for(i=4;i<=n;i++)
    {
        f>>x;
        if(x>max) {g<<i;ok=0;break;}

    }
    if(ok==1) g<<n;
    return 0;
}
