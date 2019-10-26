#include<fstream>
#include<cmath>
using namespace std;
int main()
{
    ifstream f("numar2.in");
    ofstream g("numar2.out");
 unsigned long long n;

   f>>n;
   if(n<1)
    g<<0;
 else
   if(n>=1&&n<=8)
    g<<1;
    else if(n>=8&&n<343)
     g<<8;
     else if(n>=343&&n<1331)
      g<<343;
      else if(n>=1331&&n<1030301)
      g<<1331;
      else if(n>=1030301&&n<1367631)
      g<<1030301;
      else if(n>=1367631&&n<1003003001)
      g<<1367631;
      else if(n>=1003003001)
      g<<1003003001;
      return 0;



}




