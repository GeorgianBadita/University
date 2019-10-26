#include<fstream>
using namespace std;
int main()
{
    ifstream f("volei1.in");
    ofstream g("volei1.out");
    int i,j,n,m,v[1000],x[1000];
    f>>n;
    for(i=1;i<=n;i++)
        {
            f>>v[i];
        }
        f>>m;
        for(i=1;i<=m;i++)
            f>>x[j];
            for(i=1;i<=n;i++)
                {
                    if(x[i]>v[i-1]&&x[i]>v[i+1])
                     v[i]=x[i];
                     g<<v[i]<<' ';
                }

}
