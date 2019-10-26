#include<cstdio>
#include<algorithm>
using namespace std;
short v[21],n,k,p,x=1;
bool maxim();
void afisare();
bool maxim()
{
    short l[13];
    for(int i=1;i<=n;i++) l[i]=0;
    l[n]=1;
    for(int i=n-1;i>=1;i--)
    {
        l[i]=1;
        for(int j=i+1;j<=n;j++)
        if(v[i]<=v[j]&&l[i]<l[j]+1) l[i]=l[j]+1;
    }
    if(l[1]>=k) return true;
    else return false;
}
void afisare()
{   freopen("jucarii.out","w",stdout);
    for(int i=1;i<=n;i++)
    printf("%d ",v[i]);
}
int main()
{
    freopen("jucarii.in","r",stdin);
    scanf("%hd%hd%hd",&n,&k,&p);
    for(int i=1;i<=n;i++) v[i]=i;
    while(next_permutation(v+1,v+n+1))
    {
        if(maxim()) x++;
        if(x==p) {afisare();break;}
    }
    return 0;
}
