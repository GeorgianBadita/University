#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
ifstream f("degrade.in");
ofstream g("degrade.out");
int v[100002],y[100002];
char s[100002],w[100002],x[100002];
int main()
{
    int n,i,j,s1,max=0,nr=0;
    for(i=1;i<=10;i++) f>>s[i];
    for(i=1;i<=10;i++) v[i]=s[i]-'0';
    //for(i=1;i<=n;i++) g<<v[i]<<' ';
   // f>>w;
    n=16;
    for(i=1;i<=n;i++) {f>>x[i];} //g<<x[i]<<' ';}
    for(i=1;i<=n;++i)
        for(j=1;j<=10;j++)
        if(x[i]==s[j]) y[i]=v[j];
        //for(i=1;i<=n;i++) g<<y[i]<<' ';
        for(i=1;i<=n;i++)
        {   s1=1;
            while(y[i]<=y[i+1])
            {
                s1++; i++;
            }
            if(s1>max) max=s1;
            if(max==s1) nr++;
        }
        g<<max<<' '<<nr;
}
