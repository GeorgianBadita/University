#include<fstream>
using namespace std;
int main()
{
    ifstream f("pb.in");
    ofstream g("pb.out");
    int i,ok=1,y,x,u,n,d;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x; y=x;
        d=0; ok=1;
        while(y!=0)
        {
            y/=10;
            d++;
        }
        if(d!=3)
        {g<<"Nu sunt toate formate din 3 cifre";
        ok=0;
         break;}
    }
    if(ok!=0) g<<"Toate formate din 3 cifre";
    return 0;
}
