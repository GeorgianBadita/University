#include<fstream>
#include<cmath>
using namespace std;
ifstream f("numere10.in");
ofstream g("numere10.out");
int v[1000000]={0},x[1000000];
void ciur()
{
     long long i,j,p=1;
    x[0]=2;
    for(i=3;i<=1000000;i+=2)
    {
        if(v[i]==0)
        {
            x[p]=i;
            p++;
            for(j=i*i;j<=1000000;j+=2*i)
            v[j]=1;
        }
    }

}
int main()
{   int i,p;
    ciur();
    for(i=0;i<p;i++)
    g<<x[i]<<' ';
}

