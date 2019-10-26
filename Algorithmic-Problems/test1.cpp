#include<fstream>
using namespace std;
int main()
{
    ifstream f("test1.in");
    ofstream g("test1.out");
    int format,b1,d1=0,j,i,d=0,a,b,c,ok,okb,nr=0;
    f>>a>>b;   x=a; y=b;
     for(i=1;i<=a;i++)
        {if(a%i==0)
        d++;
        if(d==2)
        ok=1;
        else ok=0;
        }
        for(j=1;j<=b;j++)
        {if(b%j==0)
           d1++;
           if(d1==2)
           okb=1;
           else okb=0;
        }
        do
        {
            c=a/10;
            a/=10;
        }while(a>9);
    while(b!=0)
        {
            b/=10;
            nr++;
        }


}

