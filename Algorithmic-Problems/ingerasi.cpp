#include<fstream>
using namespace std;
int main()
{
    ifstream f("ingerasi.in");
    ofstream g("ingerasi.out");
    int long long i,n,a,b,r,cmmdc,v[1000],r1,l;
    f>>n;
    f>>a>>b;
    while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
          cmmdc=a;  l=cmmdc;
         if(n==2)
         g<<a;
          for(i=3;i<=n;i++)
            {
                f>>v[i];
                while(v[i]!=0)
                    {
                        r1=l%v[i];
                        l=v[i];
                        v[i]=r1;
                    }

            }
          if(n>2)
            g<<l;
            return 0;
}
