#include<fstream>
using namespace std;
int main()
{int n,v[1001],w[1001],i,x=0,x1=0,k,k1;
ifstream f("cuburi3.in");
ofstream g("cuburi3.out");
f>>n;
for(i=1;i<=1000;i++)
{
	v[i]=0;
	w[i]=0;
}
for(i=1;i<=n;i++)
{f>>k>>k1;
v[k]=1;
w[k1]=1;
}
for(i=1;i<=1000;i++)
{
	if(v[i]==1)
x++;
if(w[i]==1)
	x1++;
}
if(x<x1)
	g<<"D "<<x;
if(x>x1)
	g<<"C "<<x1;
if(x==x1)
	g<<"DC "<<x1;
}
