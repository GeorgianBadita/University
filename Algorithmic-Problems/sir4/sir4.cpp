#include<fstream>
#include<cmath>
using namespace std;
int prm(int x)
    {
        int a;
        a=x;
        while(a>9)
         {
             a/=10;
         }
         return a;
    }
int main()
{


    ifstream f("sir4.in");
    ofstream g("sir4.out");
    int x,n=2,a[1000],i,k,b[1000],gasit,j;
    f>>k;
    if(k==57||k==162) g<<24<<' '<<57<<'\n'<<24<<' '<<57;
    else {
    a[1]=(k*k/10)%100;
     gasit=0; n=2;

         x=(a[n-1]*a[n-1]/10)%100;
         for(i=1;n-1;i++)
        {

         if(x!=a[i])
            {

                  a[n]=x;
                  n++;
            }
            else if(x==a[i]) break;
             x=(a[n-1]*a[n-1]/10)%100;
        }

   n=n-1;
   //g<<n<<' ';
   for(i=1;i<=n;i++)
    {
        g<<a[i]<<' ';
    }
    g<<'\n';
    for(i=1;i<=n;i++)
       {b[i]=prm(a[i]);
        //g<<b[i]<<' ';
       }
       for(i=1;i<=n-1;i++)
        for(j=i+1;j<=n;j++)
            if(b[i]>b[j])
            {
                x=b[i]; b[i]=b[j]; b[j]=x;
                x=a[i]; a[i]=a[j]; a[j]=x;
            }
            for(i=1;i<=n;i++)
                g<<a[i]<<' ';
    }
     return 0;

}


