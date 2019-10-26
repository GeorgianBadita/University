#include<cstdio>
#include<algorithm>
using namespace std;
int a[101][101],i,j,jj,ii,n,m,s,nm,rez;
bool ok;
int main ()
{
    freopen ("foto.in","r",stdin);
    freopen ("foto.out","w",stdout);
    scanf ("%d %d",&n,&m);nm=1;
    for (i=1;i<=n;++i)
    {
        for (j=1;j<=m;++j)
        {
            scanf ("%d",&a[i][j]);
        }
    }
    for (i=1;i<=n;++i)
    {
        for (j=1;j<=m;++j)
        {
            if (!a[i][j])
            {
                ++nm;s=0;
                for (ii=i;ii<=n;++ii)
                {
                    for (jj=j;jj<=m;++jj)
                    {
                            if ((a[ii-1][jj]==nm || a[ii][jj-1]==nm) && ii!=i)
                            {
                                ++s;a[ii][jj]=nm;ok=true;continue;
                            }
                        if (!a[ii][jj])
                        {
                            ++s;a[ii][jj]=nm;ok=true;continue;
                        }
                        if (a[ii][jj] && ok)
                        {
                            ok=false;break;
                        }
                    }
                }
                if (rez<s) rez=s;
            }
        }
    }
    printf ("%d",rez);
    return 0;
}
