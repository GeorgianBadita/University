#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int ok,a[51][51],v[2501],c,nr1,nr2;
int prim(int x)
{
    int i;
    if(x==2) return 1;
    for(i=2;i<=sqrt((float)x);i++)
    {
        if(x%i==0) return 0;
    }
    return 1;
}


int main()
{
    freopen("matrice4.in","r",stdin);
    freopen("matrice4.out","w",stdout);
    int n,m,i,j,nr=0,pr;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);

        }
    }
    while(ok==0)
    {
            ok=1;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)
                {   if(a[i][j]!=0)nr2++;
                    c=prim(a[i][j]);
                    if(c==1&&a[i][j]!=0) {a[i][j]=0;nr1++;}
                    if(c==0&&a[i][j]!=0) a[i][j]++;
                }
            }
            if(nr1!=nr2) ok=0;
            nr1=nr2=0;
            nr++;
    }
    pr=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
                c=prim(a[i][j]);
                if(c==1) v[++pr]=a[i][j];
        }
    }
    sort(v+1,v+pr+1);
    printf("%d %d\n",nr,pr);
    for(i=1;i<=pr;i++)
    printf("%d ",v[i]);
}
