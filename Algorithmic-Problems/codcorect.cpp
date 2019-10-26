#include<fstream>
using namespace std;
int main()
{
    ifstream f("codcorect.in");
    ofstream g("codcorect.out");
    int n,x,nrcif,y,i,c,pcif,ucif,d,e,format,h,cif;
    f>>n;
    for(i=1;i<=n;i++)
        {
            f>>x; y=c=d=e=h=x;
            while(c>9)
                {
                     pcif=c/10;
                     c/=10;
                }
                ucif=d%10;
             format=0;
            nrcif=0;
            while(y!=0)
                {

                    nrcif++;
                    y/=10;

                }
                if(nrcif%2==0)
                         g<<x<<' ';
                       if(nrcif%2==1&&pcif>ucif)
                         g<<x<<' ';
                         else if(nrcif%2==1&&ucif>pcif)
                              {
                                while(h!=0)
                                   {
                                       format=format*10+h%10;
                                       h/=10;

                                   }

                              }

        }
}
