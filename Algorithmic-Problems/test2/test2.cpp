#include<fstream>
using namespace std;
ifstream f("test2.in");
ofstream g("test2.out");
void rez(int poz, int n)
{   int pozmax=-1,i,p=0,v[11],nr=0,max=-1;
    while(n) {v[++p]=n%10; if(n%10>=max){pozmax=p,max=n%10;} n/=10;nr++;}
    if(poz>nr) {poz=poz%pozmax;}
    for(i=poz;i<=p-1;i++) v[i]=v[i+1];
    p--; int x=0;
    for(i=p;i>=1;i--) x=x*10+v[i];
    g<<x;

}
int main()
{   int i,x,n;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x;
        rez(i,x); g<<' ';
    }
}
