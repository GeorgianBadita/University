#include<fstream>
using namespace std;
char s[500001];
int n;
int main()
{ifstream fin("semne3.in");
 ofstream fout("semne3.out");
	fin>>n;
	int maxx=n,minn=1;
	for(int i=0;i<n;i++)
		   fin>>s[i];

	for(int i=0;i<n;i++)
	if(s[i]=='<')
			fout<<minn<<" ",minn++;
		else
			fout<<maxx<<" ",maxx--;
	return 0;
}
