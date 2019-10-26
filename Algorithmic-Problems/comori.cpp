#include<fstream>
using namespace std;
int main()
{
    ifstream f("comori.in");
    ofstream g("comori.out");
    int i,n,x,y,d,p,j;
    y=0;x=0;
    f>>n;
    for(i=1;i<=n;i++)
        {



            f>>d>>p;
          if(d==1)
            {
                x=x;
                y+=p;
            }
           else if(d==2)
            {
                x+=p;
                y+=p;
            }
           else if(d==3)
            {
              x+=p;
              y=y;
            }
          else  if(d==4)
            {
              x+=p;
              y-=p;
            }
          else  if(d==5)
            {
               x=x;
               y-=p;
            }
           else if(d==6)
             {
                x-=p;
                y-=p;
             }
           else  if(d==7)
             {
               x-=p;
                y=y;
             }
             else if(d==8)
             {
               x-=p;
               y+=p;
             }


        }
            g<<x<<' '<<y;



}

