#include<fstream>
#include<cmath>
using namespace std;
int main()
{
   ifstream f("numere6.in");
   ofstream g("numere6.out");
int nr=0,i,s1=0,b,a,x=0,s=0,y=0,p,z,p1,n,q=1,j,d=0,m=1,c=0,l,k;
f>>a>>b;
    while(a!=0)
        {if(a%2==1)
        s=s+pow(10,x);
        x++;
        a=a/2;
        }

        while(b!=0)
        {if(b%2==1)
        s1=s1+pow(10,y);
        y++;
        b=b/2;
        }

         p=z=l=s;
        p1=k=s1;
        do
        {
            z=z/10;
            nr++;
        }while(z!=0);
      while(p>9)
      {
          p/=10;
      }
      p1=p1%10;
   while(p==p1)
     {
         while(l>9)
        {
            l/=10;
        }
            p1%=10;

            s=s%10^nr-1;
            s1=s1/10;

     }
     g<<s<<' '<<s1;
        while(s>0)
            {
              n=s%10;
              s/=10;
              c=c+n*q;
              q=q*2;
            }
            while(s1>0)
                {
                 j=s1%10;
                 s1/=10;
                 d=d+j*m;
                 m*=2;
                }

    return 0;
}
