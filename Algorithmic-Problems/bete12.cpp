#include<fstream>
using namespace std;
int main()
{
    int sp=0,y[10001],k[10001],s1=0,nr=0,max1=0,max=0,ok1=0,p,x,s=0,a[10001],b[10001],i,j,ok=0,n,aux,aux1,m;
    ifstream f("bete1.in");
    ofstream g("bete1.out");
    f>>n;
    for(i=1;i<=n;i++)
        {
            f>>a[i]; y[i]=a[i];
        }

       while(!ok)
        {
            ok=1;
            for(i=1;i<n;i++)
                if(a[i]>a[i+1])
                    {
                        aux=a[i];
                        a[i]=a[i+1];
                        a[i+1]=aux;
                        ok=0;
                    }
        }for(i=1;i<=n;i++)
        {
            f>>b[i]; k[i]=b[i];
        }
        do
        {
            ok1=1;
            for(i=1;i<n;i++)
            if(b[i]<b[i+1])
            {
                ok1=0;
                aux1=b[i];
                b[i]=b[i+1];
                b[i+1]=aux1;
            }

        }while(!ok1);




                    for(i=1;i<=n;i++)
                    {
                     sp=y[i]+k[i];
                     s1=a[i]+b[i];
                     if(max<a[i])
                     max=a[i];
                     if(max1<b[i])
                     max1=b[i];
                     s=max+max1;
                     if(s==sp)
                        nr++;
                    }
                    g<<s1<<'\n'<<s<<'\n'<<nr;



}
