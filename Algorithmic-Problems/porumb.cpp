#include<fstream>

using namespace std;

int main()

{
    ifstream f("porumb.in");
    ofstream g("porumb.out");
    int i,n,m,x,t,min,s=0;
    f>>n>>m;

    for(i=1;i<=n;i++)
        {
            f>>x;
            if(m-1<n-m)
            min=m-1;
            else min=n-m;
            s+=x;
            t=n-1+s+min;
        }
            g<<t;
}
