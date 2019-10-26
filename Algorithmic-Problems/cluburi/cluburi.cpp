#include<fstream>
using namespace std;
int main()
{
    ifstream f("cluburi.in");
    ofstream g("cluburi.out");
    int n,k=1,b,nrcluburi=0;
    f>>n; b=n;
    while(n!=0)
     {
         if(n%2==1)
          nrcluburi++;
          n/=2;

     }
     g<<nrcluburi<<'\n';
     while(b!=0)
      {
          if(b%2==0)
           {
               k*=2;
               b/=2;
           }
           else
           {g<<k<<' ';
           k*=2;
           b/=2;
           }
      }
      return 0;

}
