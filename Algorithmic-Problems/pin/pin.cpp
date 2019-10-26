#include<fstream>
using namespace std;
int v[1000];
int main()
{
    ifstream f("pin.in");
    ofstream g("pin.out");
    int k=0,n,i,j,c,b=0,d,x,p,nr=0;
    f>>n>>p;
   for(i=9999;i>=1;i--)
    {
       d=i;
       while(d!=0)
        {
            x=d%10;
            d/=10;
             nr++;
             if(x!=n&&x!=p)
              b++;
        }
        if(nr==b)
        {
        for(j=1;j<=i;j++)

                if(i%j==0)

                     k++;

                 if(k==2)
                  {g<<i;
                   break;
                  }
                  k=0;


        }
         nr=0; b=0;






    }

}
