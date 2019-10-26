#include<fstream>
using namespace std;
ifstream f("dartz.in");
ofstream g("dartz.out");
int s,x[1001];
int main()
{   f>>s;
    int n=2,i,p=0,y,j,t1,t2,t[4];
    for(i=1;i<=n;i++)
    {
        x[++p]=(i-1)*i*(i+1);
        if(x[p]>s) break;
        n++;
    }
    for(i=1;i<=p;i++)
    {
        y=s/2-x[i];
        for(j=1;j<=p;j++)
        {
            if(y==x[j]) {t1=x[j];t2=s/2-x[j];break;}
        }
    }

    for(i=1;i<=p;i++)
    {
        if(x[i]==t1) t[1]=i-1;
        else if(x[i]==t2) t[2]=i-1;
    }
    t[3]=t[1]; t[4]=t[2];
    g<<t[1]<<' '<<t[2]<<' '<<t[3]<<' '<<t[4];
}
