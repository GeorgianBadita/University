#include<fstream>
using namespace std;
int main()
{
    ifstream f("joc20.in");
    ofstream g("joc20.out");
    int j,s1=0,s2=0,i,n,a[100],k[100],v=0,nr,u,y;
    f>>n;  u=n; y=0;

        for(i=1;i<=n;i++)
            {
                f>>a[i];
            }
            for(i=1;i<=n;i++)
                {
                   f>>k[i];
                }
        for(i=1;i<=n;i++)
            {

                if(i%2==1)
                 {
                        if(k[i]==1)
                        s1+=a[i];
                        else if(k[i]==2)
                        s2+=a[i];
                 }
            }
        g<<s1<<' '<<s2;
}
