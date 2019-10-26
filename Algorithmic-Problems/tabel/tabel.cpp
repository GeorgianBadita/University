#include<fstream>
using namespace std;
int a[51][51],v[100];
int main()
{
    ifstream f("tabel.in");
    ofstream g("tabel.out");
    int n,m,p,l[100],c[100],i,j;
    f>>n>>m;
    f>>p;
    for(i=1;i<=p;i++)
    {
        f>>l[i]>>c[i]>>v[i];
        //g<<l<<' '<<c<<' '<<v[i];
        //g<<'\n';
    }
    for(i=1;i<=p;++i)
    {for(j=1;j<=p;++j);
        a[l[i]][c[i]]=v[i];
    }
     //for(i=1;i<=n;i++)
    //{
      //  for(j=1;j<=m;++j)
      //  if(a[i-1][j]==0)
      //  a[i-1][j]=a[i][j]-a[i-2][j];
   // }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;++j)
        g<<a[i][j]<<' ';
        g<<'\n';
    }

}
