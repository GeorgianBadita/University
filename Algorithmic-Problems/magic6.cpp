#include<fstream>
#include<cmath>
using namespace std;
int main()
{
   ifstream f("cepe.in");
   ofstream g("cepe.out");
int long long ceva=1,step,nr=0,i,s1=0,b,a,x=0,s=0,y=0,p,z,p1,n,q=1,j,d=0,m=1,c=0,l,k,za,zb;
f>>a>>b;    za=a; zb=b;
    while(a!=0)
        {if(a%2==1)
        s=s+pow((double)10,(int)x);
        x++;
        a=a/2;
        }

        while(b!=0)
        {if(b%2==1)
        s1=s1+pow((double)10,(int)y);
        y++;
        b=b/2;
        }



        i=s;
        while(i!=0)
            {
                i/=10;
                nr++;
            }

           p=s/pow((float)10,(int)nr-(int)ceva);
           p1=s1%10;
           k=10;
           step=pow((float)10,(int)nr-(int)ceva);

           while(p==p1&&s>0&&s1>0)
           {
             s=s%step;
             s1=s1/k;
             ceva++;
             p=s/pow((float)10,(int)nr-(int)ceva);
             p1=s1%10;
             step=pow((float)-10,(int)nr-(int)ceva);


           }




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
            g<<c+d;
    return 0;
}
