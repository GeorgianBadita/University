#include<fstream>
#include<algorithm>
using namespace std;
int a[105],b[105],i,j,n;
float max,e,d;
int main()
{
    ifstream f("petro.in");
    ofstream g("petrol.out");
    f>>n>>e>>d;
    for(i=1;i<=n;i++)
        {
            f>>a[i]>>b[i];
        }
        float max=0.0;
        if(n==1)
         {
             if(a[1]>b[1])
              g<<e/a[1];
              else g<<d/b[1];
         }
         else
        {
            for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(((float)e/a[i]+(float)d/b[j])>max&&i!=j)
                    max=(float)e/a[i]+(float)d/b[j];
        }
                    g<<max;

}
