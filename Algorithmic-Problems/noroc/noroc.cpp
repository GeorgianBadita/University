#include<fstream>
#include<algorithm>
using namespace std;

ifstream f("noroc.in");
ofstream g("noroc.out");
int x[205],s[205],n,i,j,pi,pf,ii,rez;
int main()
{
   f>>n;
   for(i=1;i<=n;i++)
   {
	f>>x[i];
	s[i]=s[i-1]+x[i]*x[i];
	if (s[i]%n==0) {g<<i<<'\n'; for(ii=1;ii<=i;ii++) g<<x[ii]<<" "; return 0;}
   }
    if (s[i-1]%n!=0)
	{
		for(i=1;i<n;i++)
			for (j=i+1;j<=n;j++)
			if ((s[j]-s[i])%n==0) {pi=i+1; pf=j; rez=j-i; g<<rez<<'\n'; for(ii=pi;ii<=pf;ii++) g<<x[ii]<<" "; return 0;}

	}
	return 0;
}
