#include<fstream>
using namespace std;
ifstream f("copaci.in");
ofstream g("copaci1.out");
int c,final,pos,i,j,a[51][51],n,m,minim,b[51][51];
int ver(int final)
{
    final=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i][j]==0) {final=0;}
        }
    }
    return final;
}
int main()
{   int ok;
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        f>>a[i][j];
    }
    pos=0; ok=0;

    while(pos==0&&final==0)
    {  final=ver(final);
        pos=1; ok=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i][j]==0)
                if(a[i][j+1]+a[i][j-1]+a[i-1][j]+a[i+1][j]>=2) {b[i][j]=1; pos=0;}
            }
        }
        if(pos==1) minim++;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            if(b[i][j]==1) a[i][j]=1;
        }
    }
    if(pos==1) g<<minim;
    else g<<minim<<'\n'<<"IMPOSIBIL";
}

