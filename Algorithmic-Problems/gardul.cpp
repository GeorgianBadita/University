#include<fstream>
using namespace std;
int main()
{
    ifstream f("gardul.in");
    ofstream g("gardul.out");
    int r,rosu,albastru,cmmmc,cmmdc,n,violet,p,q,a,b,P,nevopsit;
      f>>n>>p>>q;
      P=p*q;
      a=p;
      b=q;

      while(q!=0)
         {r=p%q;
         p=q;
         q=r;
         }
         cmmdc=p;
         cmmmc=P/cmmdc;

          violet=n/cmmmc;
          rosu=n/a-violet;
          albastru=n/b-violet;
          nevopsit=n-rosu-albastru-violet;
          g<<nevopsit<<'\n'<<rosu<<'\n'<<albastru<<'\n'<<violet;
}
