#include<fstream>
using namespace std;
ifstream f("zid.in");
ofstream g("zid.out");
int s[1001],v[1001],r[1001];
int main()
{
    int i,n;
    f>>n;
    for(i=1;i<=n;i++) f>>v[i];
    int p=0,j;
    for(i=1;i<=n;i++)
    {   int s1=0;
        for(j=1;j<=i;j++) s1+=v[j];
        s[i]=s1; r[i]=s[i]%n;
    }
    int ok=1;
    for(i=1;i<=n;i++)
    {
        if(r[i]==0) {ok=0; g<<i<<'\n';
        for(j=1;j<=i;j++) g<<v[j]<<' ';
        break;
        }
    }
    int k,m;
    if(ok)
    {
        for(i=1;i<=n-1;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(r[i]==r[j])
                {   m=1;
                    g<<j-i<<'\n';
                    for(k=i;k<=j;k++) g<<v[k]<<' ';
                    break;
                }
            }
            if(m==1) break;
        }
    }
    return 0;
}
