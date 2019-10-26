#include<fstream>
using namespace std;
int main()
{
    ifstream f("scara.in");
    ofstream g("scara.out");
    int n,x,y,aux;
    f>>n;
    y=(n-1)/4;
    if(y%2==0)
    x=(n-1)%4+y;
    else if(y%2==1)
    x=3-(n-1)%4+y;
    g<<x<<' '<<y;
}
