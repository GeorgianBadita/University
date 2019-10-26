#include<fstream>
using namespace std;
int v[401][401];
int main()
{
    ifstream f("figura.in");
    ofstream g("figura.out");
    int i,d,n,x,y,p=0,j;
    f>>d>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;
        v[x][y]=2;
    }
    for(i=1;i<=d;i++)
    for(j=1;j<=d;j++)
    {
        if(v[i-1][j]==0&&v[i][j]!=0)
        p++;
        if(v[i][j-1]==0&&v[i][j]!=0)
        p++;
        if(v[i+1][j]==0&&v[i][j]!=0)
        p++;
        if(v[i][j+1]==0&&v[i][j]!=0)
        p++;
    }
    g<<p;


}
