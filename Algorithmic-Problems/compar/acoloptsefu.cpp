#include<cstring>
#include<fstream>


using namespace std;
char s[100000];
int main()
{ifstream fin("compar.in");
 ofstream fout("compar.out");

	fin>>s;
	int N;
	N=strlen(s)+1;
	fout<<N<<"\n";
	int maxx=N,minn=1;
	for(int i=0;i<N;i++)
		if(s[i]=='<')
			fout<<minn<<" ",minn++;
		else
			fout<<maxx<<" ",maxx--;
       	fout.close();
	return 0;
}
