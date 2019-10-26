#include<fstream>
using namespace std;
int main()
{
   ifstream f("pinochio.in");
   ofstream g("pinochio.out");
    int n,p,k,i;
    f>>n>>p>>k;
     while(k>0)
        {
            for(i=1;i<=7;i++)
                {
                   if(k==0)
                    {
                        break;
                    }
                   if((i!=6)&&(i!=7))
                    {
                        n+=p;
                    }
                    if((i==6)||(i==7))
                    {
                        n--;
                    }

                k--;
                }
        }
        g<<n;
}
