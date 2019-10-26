#include<fstream>
using namespace std;
ifstream f("numere12.in");
ofstream g("numere12.out");
int main()
{
    int x,c=0,a,b,i,j,nr,nr1;
    f>>a>>b;
    for(i=a;i<=b;i++)
    {   nr=0,nr1=0;
        j=x=i;
        while(x)
        {
            if((x%10)!=0&&j%(x%10)==0)
            x/=10;
        }
        if(nr==nr1)  c++;
    }
    g<<c;
}
