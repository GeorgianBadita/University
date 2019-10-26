#include<fstream>
using namespace std;

int main()
{
	ifstream f("pin.in");
	ofstream g("pin.out");
	int nr=0,k,v[10000],i,j,p,s=0,x,c,d,n,max=0;
	f>>k>>n;

       for(i=1;i<=9999;i++)
        {         p=c=i; d=0;
            for(j=1;j<=p;j++)
                {
                      if(p%j==0)
                        d++;
                }

                if(d==2)
                     {
                    while(p!=0)
                      {
                          x=p%10;
                            p/=10;


                      }


                     }




        }





}
