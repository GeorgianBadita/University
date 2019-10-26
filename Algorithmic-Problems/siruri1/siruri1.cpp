#include<fstream>
using namespace std;
int n,i,j,x[101],y[101];
int main()
{
    ifstream f("siruri1.in");
    ofstream g("siruri1.out");
     f>>n;
     for(i=1;i<=n;i++)
        {
            f>>x[i];
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
             {
                if(x[i]>=x[j])
                 y[i]++;
             }
            for(i=1;i<=n;i++)
                g<<y[i]<<' ';

              return 0;
}
