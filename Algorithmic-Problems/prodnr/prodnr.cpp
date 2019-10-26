#include<cstdio>
#include<cstring>
using namespace std;
char s[30001];
int w[15001],v[100001],pr[10001],k=0,lg,gm,nrprime,fr[10001];
void ciur()
{   int i,j;
   for(i=2;i<=100000;i++) if (v[i]==0) {pr[k++]=i; for(j=i;j<=100000/i;j++) v[i*j]=1;}
}
void citire()
{
    gets(s);
    lg=strlen(s);
}
int main()
{
    freopen("prodnr.in","r",stdin);
    freopen("prodnr.out","w",stdout);
    int i,j,nr,t,q;
    citire();
    ciur();
    nrprime=k;
    k=0; i=-1;
    while(i<lg-1)
    {
        i++;
        nr=s[i]-'0';
        q=0;
        for(j=1;j<=nr;j++)
        {
            i++;
            t=s[i]-'0';
            q=q*10+t;
        }
        k++;
        w[k]=q;
    }
    printf("%d\n",k);
    for(i=1;i<=k;i++)
    {
        for(j=0;j<nrprime;j++)
        {   int fm=0;
            while(w[i]%pr[j]==0)
            {   fm++;
                w[i]/=pr[j];
            }
            fr[j]+=fm;
            if(w[i]==1) break;
        }
    }
    for(j=0;j<nrprime;j++) if(fr[j]>0){printf("%d %d\n",pr[j],fr[j]);}
}
