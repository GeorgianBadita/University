#include<fstream>
#include<cmath>
#include<algorithm>
using namespace std;
ifstream f("bileprime.in");
ofstream g("bileprime.out");
int v[1000001],x[1000001],y;
int main()
{   int n,a,b,i,j,m=1;
    f>>n>>a>>b;
    for(i=2;i<= 1000000;i++)
	{
		if(v[i]==0)
		{
            x[++m]=i;
			for(j=i;j<=(1000000/i);j++)
				v[i*j]=1;
		}
	}
	for(i=1;i<=n;i++)
	{f>>y;
	if(binary_search(x,x+m+1,y)==0&&y<=b) {a+=y;b-=y;}
	else if(binary_search(x,x+m+1,y)==0&&y>b) {a+=0;b+=0;}
	else if(binary_search(x,x+m+1,y)==1&&y<a) {a-=y;b+=y;}
	else if(binary_search(x,x+m+1,y)==1&&y>a) {a+=0;b+=0;}
	}
	g<<a;
	return 0;
}


