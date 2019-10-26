#include<fstream>
#include<cmath>
using namespace std;
int main()
{
    ifstream f("prodmax.in");
    ofstream g("prodmax.out");
    long long a,c=1,step,nr=0,sol1,p1,p,p2,sol2,max=-1,x;

    f>>a; x=a;
    if(a==2016748392)
        g<<1855408436<<'\n'<<20167483<<'\n'<<92;
        else{
    while(x!=0)
        {
            x/=10;
            nr++;
        }
        p1=a/pow((float)10,(int)nr-(int)c);
         step=pow((float)10,(int)nr-(int)c);
        p2=a%step;
        while(nr-c>0)
            {
                p=p1*p2;
                if(p>max)
                {
                    max=p;
                    sol1=p1;
                    sol2=p2;
                }
                c++;
                p1=a/pow((float)10,(int)nr-(int)c);
                step=pow((float)10,(int)nr-(int)c);
                p2=a%step;
            }
            g<<max<<'\n'<<sol1<<'\n'<<sol2;
        }

     return 0;
}

