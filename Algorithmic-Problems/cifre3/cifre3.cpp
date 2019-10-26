#include<fstream>
using namespace std;
int v[100],l[100],u[100];
int main()
{
    ifstream f("cifre3.in");
    ofstream g("cifre3.out");
    int a,b,i;
    f>>a>>b;
    while(a!=0)
        {
            v[a%10]++;
            l[a%10]++;
            a/=10;
        }
        while(b!=0)
        {
            u[b%10]++;
            l[b%10]++;
            b/=10;
        }
        for(i=0;i<=9;i++)
            {
                if(v[i]!=0&&u[i]!=0)
                    g<<i<<' ';
            }
            g<<'\n';
            for(i=9;i>=0;i--)
                {
                    if(l[i]!=0)
                     g<<i<<' ';
                     l[i]--;
                }
}

