#include<fstream>
#include<cmath>
using namespace std;
unsigned long formula;
unsigned int i,n,nr,pus[100];
int main()
{
    ifstream f("visul.in");
    ofstream g("visul.out");


    f>>n;
    formula=n;
if((n==1)||(n==10)) g<<-1;
    else
{
for(i=1;i<100;i++)pus[i]=0;
int nrcifre=n-1,bun;
do
{       bun=0; nr=formula%10;
        i=1;
        while((i<10)&&(!bun))
        { nr=nr*10+i;
          int prim=1;
          if(nr<=1)prim=0;
          else for(int j=2;j<=sqrt(nr);j++)
                if(!(nr%j))prim=0;
          if((prim)&&(!pus[nr]))
                {pus[nr]=1;
                formula=formula*10+i;
                bun=1;
                nrcifre--;
                }
                else nr/=10;

          i+=2;
          }
}while(nrcifre);
g<<formula;
}
}

