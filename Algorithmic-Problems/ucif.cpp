#include<fstream>
#include<cmath>
using namespace std;
int main()
{
    ifstream f("ucif.in");
    ofstream g("ucif.out");
    int i,s=0,n,ucif,j;
    f>>n;
   ucif=0;
    for(i=1;i<=n;i++)
        {
           s=1;
            for(j=1;j<=i;j++)
            s=(s*i)%10;
            ucif=(ucif+s)%10;
        }
                       g<<ucif;
}
