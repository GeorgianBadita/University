#include<fstream>
using namespace std;
int main()
{
    int x,y,n,i,z;
    ifstream f("fib.in");
    ofstream g("fib.out");
    f>>n;
    if(n==1||n==2) g<<1;
    else { x=1; y=1;
    for(i=3;i<=n;i++)
        {
            z=x+y;
            x=y;
            y=z;
         g<<' '<<z;
        }

    }

}

