#include<fstream>
using namespace std;
int main()
{
    ifstream f("stele1.in");
    ofstream g("stele1.out");
    int k,n,i,a,col,rand;
    long long s=1;
    f>>k>>n;
    a=2;
    for(i=1;i<=k-1;i++)
        {
            s+=a;
            a+=2;
        }
        g<<s<<'\n';
        if(n==1)
         g<<1<<' '<<1;
         for(i=1;i<=n;i++)
            {
                if(i*i>=n)
                 {col=i;
                   break;
                 }
            }
                g<<col<<' ';
                rand=col*col-n+1;
                g<<rand;
}
