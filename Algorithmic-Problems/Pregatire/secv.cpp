#include<fstream>
using namespace std;
ifstream f("nmaxdiv.in");
ofstream g("nmaxdiv.out");
int v[1000];
int main()
{
  int i,start,n,max=0,lg,poz=1,final;
  f>>n;
  final=n;
  for(i=1;i<=n;i++)
  {
      f>>v[i];
  }
  for(i=1;i<=n;i++)
  {     poz=i;
                lg=1;
      while(v[i]>0) {lg++; i++;}
      if(lg>max) {max=lg;start=poz;final=i;lg=1;}
  }
  for(i=start;i<=final-1;i++)
  g<<v[i]<<' ';
}
