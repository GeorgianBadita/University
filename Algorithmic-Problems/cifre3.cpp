#include<fstream>
#include<cmath>
using namespace std;
int v[100],z[100],l[100];
int main()
{
    ifstream f("cifre3.in");
    ofstream g("cifre3.out");
    int long long  i,a,b;
    f>>a>>b;
    while(a!=0)
        {
            v[a%10]++;
             l[a%10]++;
             a/=10;
        }
        while(b!=0)
        {
            z[b%10]++;
             l[b%10]++;
             b/=10;
        }
        for(i=0;i<=9;i++)
            {
              if(z[i]!=0&&v[i]!=0)
                {
                    g<<i<<' ';

                }

            }
             g<<'\n';
             for(i=9;i>=0;i--)
                {
                    while(l[i]!=0)
                        {
                            g<<i;
                            l[i]--;
                        }
                }
                return 0;




}
