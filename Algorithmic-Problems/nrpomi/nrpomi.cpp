#include<fstream>
using namespace std;

int main()
{
    ifstream f("nrpomi.in");
    ofstream g("nrpomi.out");
    int nr,n,t,i;
    f>>n>>t;
    int a[100];
    nr=1;
    a[n+1]=a[n-1];
	for(i=2;i<=n;i+=2)
		if(a[i-1]==a[i+1])
			nr=nr*(t-1)%1234;
		else
			nr=nr*(t-2)%1234;
	g<<nr;
	return 0;

}
