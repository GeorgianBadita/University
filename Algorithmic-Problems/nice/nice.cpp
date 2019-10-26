#include<fstream>
#include<cmath>
using namespace std;
ifstream f("nice.in");
ofstream g("nice.out");
int main()
{
    int i,n;
    long long k;
    f>>n;
   for(i=0;i<n;i++)
   {
       k=pow((double)3,(double)i);
       g<<k<<' ';
   }
   g<<'\n';
   k=pow((double)3,(double)n);
   g<<(k-1)/2+1;
}
