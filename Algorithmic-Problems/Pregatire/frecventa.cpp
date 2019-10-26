#include<fstream>
using namespace std;
ifstream f("nmaxdiv.in");
ofstream g("nmaxdiv.out");
int main()
{
    int v[1001]={0},x;
    int n,i;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x;
        v[x]++;
    }
    for(i=10;i<=99;i++)
    {
        if(v[i]==0) g<<i<<' ';
    }
}
