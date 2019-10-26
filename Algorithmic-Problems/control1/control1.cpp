#include<fstream>
using namespace std;
ifstream f("control1.in");
ofstream g("control1.out");
int cif_cotrol (int x)
{
    int s;
   while(x>9)
    {   s=0;
        while(x!=0)
        {
            s+=x%10;
            x/=10;
        }
        x=s;
    }
    return x;
}
int main()
{
        int a,b,c,i,k;
        f>>a>>b>>c;
        if(c>b) g<<0; else {
        for(i=a;i<=b;i++)
        if(cif_cotrol(i)==c) break;
        k=(b-i)/9;
        g<<k+1;
        }

}
