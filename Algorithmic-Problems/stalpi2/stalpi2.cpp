# include <fstream>
# include <cmath>
# include <vector>
# include <cstdio>
# include <iostream>
using namespace std;

int a[10001],b[10001];
int v[101][1001];//era buna si ideea cu sa memorarea colorii ficaruia cu un vector
                // dar cu o matrice in care
                //v[i][0] - nr de elemente care au culoarea i
                //v[i][j] - indicele elementului j , catre vectorul a sau b
                // complexitatea e mai buna si se reduce timpul , mult
vector<double> min1(101,9999999);
short rez1[101];
short rez2[101];

int main()
{
    int n,k=0,d,i,j,maxim=0,c;
    double dis;
    freopen ("stalpi2.in","r",stdin);
    freopen ("stalpi2.out","w",stdout);
    scanf("%d%d",&n,&d);
    for (i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i],&c);
        v[c][0]++;
        v[c][v[c][0]]=i;
        if (c>maxim)
        {
            maxim=c;
        }
    }
    //printf("%d",k);
    for (i=n+1;i<=n*2;i++)
    {
        scanf("%d%d",&b[i-n],&c);
        v[c][0]++;
        v[c][v[c][0]]=i;
        if (c>maxim)
        {
            maxim=c;
        }
    }
    k=maxim;
    //cout<<k;
    for (i=1;i<=k;i++) // inafara de forurile care le avea se mai aduga unu pentru fiecare culoare
    {
        for (j=1;v[i][j]<=n;j++)//parcurg toate elementele din a care au culoare i
        {
            for(int t=v[i][0];v[i][t]>n;t--) // parcurg toate elementele din b care au culoarea i
                // si fac combinatii intre ele , verific noua distanta
            {

                dis=sqrt(d*d+((double)(a[v[i][j]]-b[v[i][t]-n]))*((double)(a[v[i][j]]-b[v[i][t]-n])));
                if (dis<min1[i])
                {
                    min1[i]=dis;
                    rez1[i]=v[i][j];
                    rez2[i]=v[i][t]-n;
                }
            }
        }
    }
    double s=0;
    for (i=1;i<=k;i++) s+=min1[i];
    printf("%.3f",s);
    for (i=1;i<=k;i++)
    {
        printf("\n%d %d",rez1[i],rez2[i]);
    }
    return 0;
}
