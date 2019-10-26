#include<fstream>
using namespace std;
ifstream f("joc13.in");
ofstream g("joc13.out");
int v[101],a[101],x[101];
int main()
{
    int n,m,i,j,s1=0,s2=0,poz1[101]={0},poz2[101]={0},p=1;
    f>>n;
    for(i=1;i<=n;i++){f>>v[i]; x[i]=i;}
    f>>m;
    for(i=1;i<=m;i++) f>>a[i];
    for(i=1;i<=m;++i)
    {
        if(i%2==1&&v[a[i]]!=0&&poz1[i]<n) {s1+=v[a[i]];poz1[i]+=a[i];}
        if(i%2==0&&v[a[i]]!=0&&poz2[i]<n) {s2+=v[a[i]];poz2[i]+=a[i];}
        g<<s1<<' '<<s2;
        g<<'\n';

    }
}
