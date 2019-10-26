#include<fstream>
using namespace std;
int main()
{
  ifstream f("pozmax.in");
  ofstream g("pozmax.out");
    int scul1=0,scul2=0,m,ok1,ok,aux,aux1,n,d[100],c[100],i,s=0;
   f>>n; m=n;
   for(i=1;i<=n;i++)
    {
        f>>d[i]>>c[i];

    }
    do
   {
       ok=1;
    for(i=1;i<=n-1;i++)
        if(d[i]>d[i+1])
        {
            ok=0;
            aux=d[i];
            d[i]=d[i+1];
            d[i+1]=aux;
        }
   }while(ok==0);
   //for(i=1;i<=n;i++)
    //g<<d[i];

       do
   {
       ok1=1;
    for(i=1;i<=n-1;i++)
        if(c[i]>c[i+1])
        {
            ok1=0;
            aux1=c[i];
            c[i]=c[i+1];
            c[i+1]=aux1;
        }
   }while(ok1==0);
      //for(i=1;i<=m;i++)
        //g<<c[i];

}
