#include<fstream>
using namespace std;
ifstream f("numar1.in");
ofstream g("numar1.out");
int v[51],y[51],z[51];
int cif_control(int n)
{   if(n==0) return 0;
    if(n%9!=0) return n%9;
    return 9;
}
int main()
{
    int n,i=0,p=0,j;
    f>>n;
    if(n==1) {f>>v[++i]; y[++p]=v[i];}
    else {
    for(i=1;i<=n;i++) f>>v[i];
    for(i=1;i<=n-1;i++)
    {   int s=0;
        while(v[i]<=v[i+1]) {s+=v[i];i++;} s+=v[i];
        y[++p]=s;
    }
     if(v[n-1]>v[n]) y[++p]=v[n];
    }
    for(j=1;j<=p;j++) y[j]=cif_control(y[j]);
    for(i=1;i<=p;i++) z[y[i]]++;
    int k=0;
    for(i=9;i>=0;i--) if(z[i]==0) {g<<i; k++;}
    if(k==0) g<<-1;
}
