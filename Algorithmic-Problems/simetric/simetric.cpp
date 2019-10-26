#include<fstream>
#include<algorithm>
using namespace std;

ifstream f("simetric.in");
ofstream g("simetric.out");

int w[205],n,i,k;

bool simetrie(int t,int a[205])
{
	int j;
	bool ok=true;
	for(j=1;j<=t/2;j++) if(a[j]!=a[t+1-j]) {ok=false; break;}
	return ok;
}

void complet(int t,int v[205])
{
	int j,x=0;
	for (j=n+t;j>=n+1;j--)
	{
		x++;
		v[j]=v[x];
	}
}

int main()
{

    f>>n;
    for(i=1;i<=n;i++) f>>w[i];
	if (simetrie(n,w)) g<<0<<'\n'<<'\n';
				  else
	{
		for (i=1;i<n;i++)
		{
			complet(i,w);
			if (simetrie(n+i,w))
				{
					g<<i<<'\n';
					for (k=n+1;k<=n+i;k++) g<<w[k]<<' ';
					return 0;
				}
		}
	}
	return 0;
}
