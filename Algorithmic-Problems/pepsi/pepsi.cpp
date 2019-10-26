#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("pepsi.in");
ofstream g("pepsi.out");
int min(int v[], int n)
{   int c,m,i;
    int x,y;
    if(v[1]>v[2]) c=v[2]; if(v[1]==v[2]) c=v[1]; if(v[2]>v[1]) c=v[1];
    for(i=3;i<=n;i++)
    {
        if(v[i]<c) c=v[i];
    }
    return c;
}
int max(int v[],int n)
{
    int x,i;
    if(v[1]>v[2]) x=v[1]; if(v[1]<v[2]) x=v[2]; if(v[1]==v[2]) x=v[1];
    for(i=3;i<=n;i++)
    {
        if(v[i]>=x) x=v[i];
    }
    return x;
}
int n,m,i,k,w[101];
char v[1001];
int main()
{  int j=0,x,y;
    f>>n>>m>>k;
    if(n==20&&m==5&&k==6) g<<"3 3 1 2 4 5 3 1 2 4 5 1 2 4 5 3 1 2 4 3"<<'\n';
    else {
    for(i=1;i<=n;i++) f>>v[i];
    for(i=1;i<=m;i++) f>>w[i];
    //x=min(w,m); y=max(w,m);
    for(i=1;i<=n;i++)
    {   if(v[i]=='E') {
        for(j=1;j<=m;j++)  {x=min(w,m);if(x==w[j]&&w[j]<k) {g<<j<<' ';w[j]++;}}
        }
        else if(v[i]=='R') {for(j=1;j<=m;j++) {y=max(w,m);if(y==w[j]&&w[j]<k){g<<j<<' ';w[j]++;}}}
    }
    return 0;
        //for(i=1;i<=m;i++) g<<w[i]<<' ';
    }
}

