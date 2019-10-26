#include<fstream>
using namespace std;
int main()
{
    ifstream f("cifra1.in");
    ofstream g("cifra1.out");
    int c,n,ras=0,i,m,x,j,nr=0;
    f>>n>>m;       x=n;
    while(x!=0)
    {
        ras=ras*10+x%10;
        c=x/=10;
    }
    while(ras>0)
    {
        for(i=1;i<=ras%10;i++)
            {nr++;
            if(m==nr)
            g<<ras%10;
            }
            ras/=10;
    }

}
