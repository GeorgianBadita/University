#include<fstream>
#include<cstring>
using namespace std;
ifstream f("criptmat.in");
ofstream g("criptmat.out");
char s[201],a[201][201];
int m=0;
int main()
{
    int p=0,n,i;
    f>>n;
    f.get();
    do
    {
        s[p]=f.get();
        p++;
    }while(s[p]!='z');
   // f.get();
   g<<p;
}
