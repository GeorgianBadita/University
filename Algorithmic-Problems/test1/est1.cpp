#include<fstream>
#include<cmath>
using namespace std;
int main()
{
    ifstream f("test1.in");
    ofstream g("test1.out");
    int z,step,o,m,y,a,b,maxn=0,maxp=0,i,d=0,prim=0,c,x,nr=0,j;
    f>>a>>b; c=a; x=b;
    for(i=1;i<=a;i++)
            if(a%i==0)
             d++;
             if(d==2)
              {
                  prim++;
                  if(a>maxp)
                  maxp=a;
              }
              if(a>maxn)
                  maxn=a;
              //g<<prim<<' '<<maxn<<' '<<maxp;
              d=0; z=0;
              for(i=1;i<=b;i++)
                if(b%i==0)
                    d++;
                    if(d==2)
                        {
                            prim++;
                            if(a>maxp)
                            maxp=b;
                        }
                        if(b>maxn)
                        maxn=b;
                    //g<<prim<<' '<<maxn<<' '<<maxp;
                    while(x!=0)
                    {
                        x/=10;
                        nr++;
                    }
                    d=0; z=0;
                    while(c!=0)
                        {
                            y=c%10;
                            step=pow((float)10,(int)nr-1);
                            o=y*pow((float)10,(int)nr-1)+b%step;
                            m=b-b%10+y;
                            c/=10;
                            for(i=1;i<=o;i++)
                                if(o%i==0)
                                    d++;
                                    if(d==2)
                                    {   prim++;
                                        if(maxp<o)
                                            maxp=o;
                                    }
                                    if(maxn<o)
                                        maxn=o;
                                        for(j=1;j<=m;j++)
                                            if(m%j==0)
                                                z++;
                                                if(z==2)
                                                    {
                                                        prim++;
                                                        if(maxp<m)
                                                        maxp=m;
                                                 }
                                                    if(maxn<m)
                                                maxn=m;
                                    d=0; z=0;

                        }
                        if(prim>0)
                        g<<maxp;
                        else g<<maxn;
}
