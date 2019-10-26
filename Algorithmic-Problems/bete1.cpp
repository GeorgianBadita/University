#include<fstream>
using namespace std;
int main()
{
    ifstream f("bete.in");
    ofstream g("bete.out");
    int a,lmax=0,n,i,x[10001],y[10001],max=0,max1=0,s=0,nr=0,nrmaxx=0,nrmaxy=0;
    f>>n;
    for(i=1;i<=n;i++)
        {f>>x[i];
        s+=x[i];
        if(x[i]>max)
        {max=x[i];
        nrmaxx=1;
        }
        else if(x[i]==max)
            nrmaxx++;
        }
        for(a=1;a<=n;a++)
            {
                f>>y[a];
                s+=y[a];
                if(y[a]>max1)
                {max1=y[a];
                nrmaxy=1;}
                else if(y[a]==max1)
                nrmaxy++;
            }
            g<<s/n<<'\n'<<max+max1<<'\n';
            if(nrmaxx<nrmaxy)
            g<<nrmaxx;
           if(nrmaxx>nrmaxy) g<<nrmaxy;
            else if(nrmaxx==nrmaxy)
            g<<nrmaxx;
}
