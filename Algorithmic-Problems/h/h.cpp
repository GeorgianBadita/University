#include<fstream>
using namespace std;
int main()
{
    ifstream f("h.in");
    ofstream g("h.out");
    int n,i,s=0,s1=0,s2=0,s3=0,s4=0;
    f>>n;
    for(i=1;i<=n;i++)
        g<<i<<' ';
        for(i=3*n+1;i<=4*n;i++)
            g<<i<<' ';
            return 0;


}
