#include<fstream>
using namespace std;
ifstream f("palindromuri.in");
ofstream g("palindromuri.out");
int a,b;
int pal(int a, int b)
{
    int x,i,nr=0;
    for(i=a;i<=b;i++)
    {
        int r=0; x=i;
        while(x)
        {
            r=r*10+x%10;
            x/=10;
        }
        if(r==i) nr++;
    }
    return nr;
}
int main()
{
    f>>a>>b;
    g<<pal(a,b);
}
