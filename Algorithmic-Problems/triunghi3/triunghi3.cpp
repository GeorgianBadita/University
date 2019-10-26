#include<fstream>
using namespace std;
int main()
{
	int n,x=1,i;
	ifstream in("triunghi3.in");
	ofstream out("triunghi3.out");
	in>>n;
	for(i=1;i<=n;i++)
	{x=(x*2)%2011;
    }
	x=x-2;
out<<x;
return 0;
}
