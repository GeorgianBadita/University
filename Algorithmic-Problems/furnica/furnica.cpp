#include<fstream>
using namespace std;
ifstream f("furnica.in");
ofstream g("furnica.out");
short a[102][102],b[102][102];
int col[101],lin[101],rez[101];
int main()
{
    int n,m,i,j,k,x=1,y=1;
    f>>n>>k;
    m=n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        b[i][j]=a[i][j]=(i+j)%6; //constriuim matricea
    }
    /*
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) g<<a[i][j]<<' ';
        g<<'\n';
    }*/
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        g<<a[i][j]<<' ';
        g<<'\n';
    }*/
    int dir,s=a[1][1],max=0;
    b[1][1]=-1;
    for(i=1;i<=k;i++) //parcurgem matricea in cele k directii
    {
        f>>dir;
        if(dir==1) {s+=a[x-1][y]; x--;if(x>n) x--; if(y>n) y--;a[x][y]=0;lin[i+1]=x; col[i+1]=y;b[x][y]=-1;} else
        if(dir==2) {s+=a[x-1][y+1]; x--; y++;if(x>n) x--; if(y>n) y--;a[x][y]=0;lin[i+1]=x; col[i+1]=y;b[x][y]=-1;} else
        if(dir==3) {s+=a[x][y+1]; y++;if(x>n) x--; if(y>n) y--;a[x][y]=0;lin[i+1]=x; col[i+1]=y;b[x][y]=-1;} else
        if(dir==4) {s+=a[x+1][y+1]; x++;y++; if(x>n) x--; if(y>n) y--;a[x][y]=0;lin[i+1]=x; col[i+1]=y;b[x][y]=-1;} else
        if(dir==5) {s+=a[x+1][y]; x++;if(x>n) x--; if(y>n) y--;a[x][y]=0;lin[i+1]=x; col[i+1]=y;b[x][y]=-1;} else
        if(dir==6) {s+=a[x+1][y-1]; x++; y--;if(x>n) x--; if(y>n) y--;a[x][y]=0;lin[i+1]=x; col[i+1]=y;b[x][y]=-1;} else
        if(dir==7) {s+=a[x][y-1]; y--;if(x>n) x--; if(y>n) y--;a[x][y]=0;lin[i+1]=x; col[i+1]=y;b[x][y]=-1;} else
        if(dir==8) {s+=a[x-1][y-1]; x--; y--;if(x>n) x--; if(y>n) y--;a[x][y]=0;lin[i+1]=x; col[i+1]=y;b[x][y]=-1;}

    }

    int nr1=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        if(b[i][j]==-1) nr1++;
    }
    g<<s<<' '<<nr1;
}
