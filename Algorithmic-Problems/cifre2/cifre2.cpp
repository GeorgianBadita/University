#include<fstream>
#include<cmath>
using namespace std;
int main()
{
    ifstream f("cifre2.in");
    ofstream g("cifre2.out");
    unsigned long long j,x,i,n,c,a,y,nr=0,z=10,r,step;
    f>>n;
    for(i=1;i<=n;i++)
        {
            j=i;
            nr=0;
            f>>x; y=x;
            while(y!=0)
             {
                 y/=10;
                 nr++;
             }
            if(i==1)
                {x/=10;
                //g<<x<<' ';
                }
                c=pow((float)10,(int)j);

           if(i!=1)
            {
                a=x-x%c;
                a/=10;
                a+=x%(c/10);
                if(a!=x);
                //g<<a<<' ';
            }
            if(i>nr)
            {
                r=j%nr;
                step=pow((float)10,(int)nr-(int)r);
                if(r>0)
                {
                    a=x%step;
                    a/=10;
                    a+=x%(step/10);
                    g<<a<<' ';
                }

            }


        }
}
