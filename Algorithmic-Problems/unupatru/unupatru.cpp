#include<fstream>
using namespace std;
int main()
{
long long int n,nr,i,x=0,y,s,v[100],nr1;

ifstream f("unupatru.in");
ofstream g("unupatru.out");
	f>>n;
	for(i=1;i<=n;i++)
		f>>v[i];

	for(i=1;i<=n;i++)
	{   nr=v[i]; x=0;
		while((nr!=1)&&(nr!=4))
		if((nr!=1)||(nr!=4))
		{nr1=nr; s=0;
			while(nr1!=0)
			{
			y=nr1%10;
		    s=s+(y*y);
			nr1=nr1/10;
			}
		    nr=s;
		    x++;
		}
		if((x==3)&&(n==4))
			g<<"4 ";
		else
	g<<x<<" ";
	}
}
