#include<fstream>
using namespace std;
ifstream f("n3.in");
ofstream g("nr3.out");
char s[1002];
int c,v[1002],x[1002],n,ok;
int main()
{   int i,n=1;
    do
    {
        s[n]=f.get();
        n++;
    }while(s[n-1]!=' ');
   n--;
   f>>c;
   for(i=1;i<=n;i++) v[i]=x[i]=s[i]-'0';
   n--;
   //for(i=1;i<=n;i++) g<<v[i];
   i=1; ok=0; int poz;
   while(ok==0)
   {
       if(v[i]>c) {poz=i-1; ok=1; break;} else i++;
   }
   for(i=n;i>=poz-1;i--)
   {
       v[i+1]=v[i];
       v[poz-1]=c;
       //g<<v[i]<<' ';
   }
   int  nr=0;
   for(i=1;i<=n+1;i++)
   g<<v[i];
   g<<'\n';
   //for(i=1;i<=n;i++) g<<x[i];
   //return 0;
   i=1; ok=0;
   while(ok==0)
   {
       if(x[i]<c) {poz=i; ok=1; break;} else i++;
   }

    for(i=n+1;i>=poz;i--)
   {
       x[i+1]=x[i];
       x[poz+1]=c;
       //g<<v[i]<<' ';
   }
    for(i=1;i<=n+1;i++) g<<x[i];

}
