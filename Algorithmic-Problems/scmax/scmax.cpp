#include<cstdio>
using namespace std;
int main()
{
scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    l[n]=1; poz[n]=-1;
    for (i=n-1;i>=1;i--)
    {
        ok=1;max=0;
        for (j=i+1;j<=n;j++)
        {
            if (a[i]<a[j])
            {
                ok=0;
                if (l[j]>max) max=l[j];
            }
        }
        if (ok==1) l[i]=1;
        else l[i]=max+1;
    }
}
