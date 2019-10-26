#include<fstream>
#include<cstring>
using namespace std;
ifstream f("grad.in");
ofstream g("grad.out");
char s[256],a[256];
int gr[256];
int main()
{
    int n,i,s1,c,p=0;
    f>>n; f.get();
    i=0; c=f.get();
    s[++i]=c;
    s1+=s[i]-'0';
    while(s[i-1]!='\n')
   {
       while(s[i-1]!=' ')
       {
            c=f.get();
            s[++i]=c;
            s1+=s[i]-'0';
       }
       gr[++p]=s1; s1=0;
   }
   for(i=1;i<=p;i++) g<<gr[i]<<' ';
}
