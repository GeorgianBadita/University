#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("atelier.in");
ofstream g("atelier.out");
int sa[10005],sb[10005];

int main()
{
	int n,a,b,i,j,max,imax;
	char poz;
	f>>n;
	for (i=1;i<=n;i++)
	{
		f>>a>>b;;
		sa[i]=sa[i-1]+a;
		sb[i]=sb[i-1]+b;
	}
	max=sa[1]+(sb[n]-sb[1]);
	imax=1;
	poz='A';
	for(i=2;i<=n-1;i++)
	{
		if (sa[i]+(sb[n]-sb[i])>=max)
		{
			max=sa[i]+(sb[n]-sb[i]);
			imax=i;
		}
	}
	for(i=1;i<=n-1;i++)
	{
		if (sb[i]+(sa[n]-sa[i])>max)
		{
			max=sb[i]+(sa[n]-sa[i]);
			imax=i;
			poz='B';
		}
	}
	g<<max<<'\n'<<poz<<'\n'<<imax;
	return 0;
}
