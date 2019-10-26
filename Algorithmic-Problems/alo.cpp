#include<fstream>
using namespace std;
int main()
{
    int n,e,nr,en,i;
    ifstream f("alo.in");
    ofstream g("alo.out");
    f>>e>>n;
    for(i=1;i<=n;i++)
        {
            f>>nr>>en;
            if(nr/10000==2 && nr%10==5)
            e=e+en;
            else
            if(nr/10000==1 && nr%10==5)
            e=e-2*en;
        }
        g<<e;
}
