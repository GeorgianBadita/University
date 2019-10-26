#include <fstream>
using namespace std;
ifstream in("subsir.in");
ofstream out("subsir.out");
long long n,l[10000],v[10000],poz[10000],maxim;
int main()
{
    long long i,j;
    in>>n;
    for(i=1;i<=n;i++)
       in>>v[i];
       poz[n]=-1;
       l[n]=1;
       for(i=n-1;i>=1;i++)
            {
                maxim=0;
                poz[i]=-1;
                for(j=i+1;j<=n;j++)
                    if(v[i]<v[j] && l[j]>maxim)
                    {maxim=l[j]; poz[i]=j;}
                    l[i]=maxim+1;
            }
            maxim=0;
            for(i=1;i<=n;i++)
                if(l[i]>maxim)
                maxim=l[i];
                out<<maxim;
                return 0;



}
