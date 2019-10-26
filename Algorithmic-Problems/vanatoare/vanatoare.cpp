#include<fstream>
using namespace std;
int main()
{
    ifstream f("vanatoare.in");
    ofstream g("vanatoare.out");
    int sa,sn,a,b,c,nr;
    f>>sa>>sn;
    a=1; b=1; nr=0;
    while(sa>=(b%2+b/2)&&sn>=b/2)
    {
        nr++;
        sa=sa-(b%2+b/2);
        sn-=b/2;
        c=a+b;
        a=b;
        b=c;
    }
    g<<nr<<'\n'<<sa<<'\n'<<sn;
    return 0;
}
