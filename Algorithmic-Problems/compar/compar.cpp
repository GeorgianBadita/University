#include<fstream>
#include<cstring>
using namespace std;
char s[100001];
int main()
{
    ifstream f("compar.in");
    ofstream g("compar.out");
     int i,n,max,min;
     f>>s;
     n=strlen(s)+1;
      g<<n<<'\n';
       max=n; min=1;
       for(i=1;i<=n;i++)
        {
            if(s[i]=='<') g<<min<<' ',min++;
            else g<<max<<' ',max--;
        }
        return 0;
}


