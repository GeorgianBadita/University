#include<fstream>
using namespace std;
int main()
{
    ifstream f("cluburi.in");
    ofstream g("cluburi.out");
    int n,k,membri,i;
    f>>n;
    for(i=1;i<=n;i++)
      { if(n%2==0)
        {
        k=n/2;
        membri=2;
        }
        else k=n/2+1;
           g<<membri;
      }
      g<<k;
}
