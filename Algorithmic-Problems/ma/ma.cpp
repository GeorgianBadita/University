#include<fstream>
using namespace std;
int main()
{   ifstream f("ma.in");;
    ofstream g("ma.out");
    int s=0,n,x[200],i;
    f>>n;
    for(i=1;i<=n;i++) {f>>x[i]; s+=x[i];}
        int ma;
        ma=s/n;
        n++;
    for(i=n;i>=n/2;i--)
    {
        x[i]=x[i-1];
    }
    x[n/2]=ma;
    for(i=1;i<=n;i++) g<<x[i]<<' ';
}
