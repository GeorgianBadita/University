#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n;
 struct nod{int x,y;}v[16006];
int cmp(const nod a,const nod b)
{
    return a.x<b.x;
}
int main()
{freopen("granita.in","r",stdin);
freopen("granita.out","w",stdout);
    int a,b,i,s=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d" "%d",&v[i].x,&v[i].y);
    sort(v+1,v+n+1,cmp);
    a=v[1].x; b=v[1].y;
    for(i=2;i<=n;i++)
    {
        if(v[i].x>b) {a=v[i].x;b=v[i].y;}
        else if(v[i].y>b) {b=v[i].y;}
        else s++;
    }
    printf("%d",s);
    return 0;
}
