#include <fstream>
using namespace std;
ifstream f("roata.in");
ofstream g("roata.out");
int main()
{

int n,p,i,k,pozmax,pozmin,o[361],c[100001];
long long s=0;

f>>n>>p;

for(i=1;i<=n;i++)
	o[i]=i;

for(i=1;i<=p;i++)
	{f>>c[i]; s+=c[i];}
g<<s<<'\n';
if (n<p)
	for(k=n+1;k<=p;k++)
		{
		pozmin=1;
		for(i=2;i<=n;i++)
			if (c[i]<c[pozmin]) pozmin=i;

		g<<o[pozmin]<<' ';

		if (c[pozmin]>10000000)
			for(i=1;i<=n;i++)
					c[i]-=10000000;

		c[pozmin]+=c[k];
		o[pozmin]=k;
		}
	else
		n=p;

pozmax=1;
for(i=2;i<=n;i++)
	if (c[i]>=c[pozmax]) pozmax=i;

for(k=1;k<=n;k++)
		{
		pozmin=1;
		for(i=2;i<=n;i++)
			if (c[i]<c[pozmin]) pozmin=i;

		g<<o[pozmin]<<' ';

		c[pozmin]+=100001;
		}
g<<'\n';
g<<pozmax;
return 0;
}

