#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
ifstream f("degrade.in");
ofstream g("degrade.out");
int v[100002],y[100002];
char s[100002],w[100002],x[100002];
int main()
{
    int u,n,i,j,s1[100],max=0,nr=0,l,p;
    for(i=1;i<=10;i++) f>>s[i];
    for(i=1;i<=10;i++) v[i]=s[i]-'0';
    //for(i=1;i<=n;i++) g<<v[i]<<' ';
   // f>>w;
    n=16;
    for(i=1;i<=n;i++) {f>>x[i];} //g<<x[i]<<' ';}
    for(i=1;i<=n;++i)
        for(j=1;j<=10;j++)
        if(x[i]==s[j]) {y[i]=v[j];}// g<<y[i]<<' ';} //g<<y[i]<<' ';}
        //for(i=1;i<=n;i++) g<<y[i]<<' ';
        for(i=1;i<=n-1;i++)
        {   s1[++l]=1;
            j=i+1; p=i;
            while(y[p]<=y[j])
            {
            s1[l]++; j++; p++;
                if(j==n) break;
            }
            if(s1[l]>max) max=s1[l];
            i=p;
        }
        for(i=1;i<=l;i++) if(s1[i]==max) nr++;
        g<<max<<' '<<nr;
}

