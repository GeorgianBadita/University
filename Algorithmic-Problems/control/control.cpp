#include<fstream>
#include<cmath>
using namespace std;
int main()
{
    ifstream f("control.in");
    ofstream g("control.out");
    int k=0,h=0,d,m,x=1,ok,aux,n,i,j,t[100],b[100],a[100],l,nr=1,c[100],prim,p(0),nk=0;
    f>>n;
    for(i=1;i<=n;i++)
     f>>a[i];
    do
    {
        ok=1;
        for(i=1;i<=n-1;i++)
            {
                if(a[i]>a[i+1])
                 {
                    ok=0 ;aux=a[i]; a[i]=a[i+1]; a[i+1]=aux;
                 }
            }
    }while(ok==0);
    //for(i=1;i<=n;i++)
       // g<<a[i]<<' ';
       j=2; i=1; x=1;
       while(i<=n)
        {   nr=1; p++;
            while(a[i]==a[j]) i++,j++,nr++;
            i++; j++;
            b[x++]=nr;

        }
        m=0; i=1;
        while(i<p)
            { //g<<b[i]<<' ';

            m++;

         if(b[i]%2==0&&b[i+1]%2==0&&b[i+2]%2==0)
                          t[m]=1;
                          else
                          t[m]=0;


         if (b[i]%2==1&&b[i+1]%2==1&&b[i+2]%2==1&&t[m]==0)
                          t[m]=1;
                          else if(t[m]==0)
                          t[m]=0;
                          //g<<t[m]<<' ';
                          i+=3;

                if(t[m]==1) h++;
                else k++;

            }
            d=h*10+k;
            g<<d<<'\n';
            for(i=1;i<=d;i++)

                    if(d%i==0)
                     nk++;
                     if(nk==2)
                     g<<1; else g<<0;

                return 0;


}





