#include<fstream>
#include<cmath>
using namespace std;
int main()
{
    ifstream f("perfecte.in");
    ofstream g("perfecte.out");
    int x1=0,n=1,x,y,nr=0,j,ii,z,c,d,e,i;
    f>>x>>y;
    if(sqrt(x)*sqrt(x)<x)
    n++;
    for(i=n;i<=sqrt(y);i++)
    for(j=i+1;j<=sqrt(y);j++)
    for(ii=j+1;ii<=sqrt(y);ii++)
    if(i*i+j*j+ii*ii<=y)
    x1++;
    g<<x1;


}
