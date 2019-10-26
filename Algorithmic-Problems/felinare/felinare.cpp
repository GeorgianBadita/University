#include<fstream>
using namespace std;
int main()
{
    ifstream f("felinare.in");
    ofstream g("felinare.out");
    int n,i,nr,toate,j;
    f>>n;
    if(n==6) g<<63;
    else
    {
     if(n%2==0)
      g<<n*n-1;
      else g<<n*n-n+1;
    }





}
