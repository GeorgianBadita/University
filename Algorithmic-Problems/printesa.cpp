#include<fstream>
using namespace std;
int main()
{
	ifstream f("printesa.in");
	ofstream g("printesa.out");
	int k,v[10000],i,j,n,s=0,x,c[102];
	f>>k>>n;
	for(i=2;i<=999;i++)
	{
		if(v[i]==0)
		{

			for(j=i;j<=(999/i);j++)
				v[i*j]=1;
		}
	}
	for(i=1;i<=n;i++)
	{f>>x;
	    v[x]=1;
	}
	i=2;
	while(s<k)
	{
	    if(v[i]==0)
	    {s++; c[s]=i;}
	    i++;
	}
    for(i=s;i>=1;i--)
         {
             g<<c[i]<<' ';
         }
	return 0;
}


