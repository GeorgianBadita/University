#include<fstream>
using namespace std;
long long int x,y,r,i,j,v[15],w[]={0,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
int main()
{
    ifstream f("sumfact.in");
    ofstream g("sumfact.out");
    f>>x;
    for(i=12;i>=1;i--)
    {   j=0;
        if(x>=w[i] && y==0)
        g<<i<<"\n";
        while(x>=w[i])
         {
            j++;y=1;
            x-=w[i];
            }
        if(j!=0||y!=0)
        {
            v[r++]=j;

        }
    }
    for(i=r-1;i>=0;i--)
    {
        g<<v[i]<<'\n';
    }

}
