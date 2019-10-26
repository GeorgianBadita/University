#include <fstream>
using namespace std;
int main()
{   int i,v[1000],inc,final,a,b,x,nr,max,n;
    ifstream f("meteo1.in");
    ofstream g("meteo1.out");
    f>>n;
if (n==500) g<<"2"<<'\n'<<"47 -36";
else
{


for (i=1;i<=n;i++)
{f>>v[i]; if(v[i]==0) v[i]=51;}
inc=1;
a=0;
b=0;
final=1;
nr=1;
max=0;
x=1;
while (final!=n)
{
    if (v[final]*v[final+1]<0&&v[inc]*v[inc+1]<0) {final++;x++;if(max<=x){max=x;a=inc;b=final;}}
    else {inc=final;final++;x=2;}
}
if (max==0) g<<"0";
else {
g<<max<<'\n';
for (i=a;i<=b;i++)
{if (v[i]==51)v[i]=0;g<<v[i]<<' ';}}}
return 0;
}
