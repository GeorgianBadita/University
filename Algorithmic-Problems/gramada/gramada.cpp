#include<fstream>
using namespace std;
int v[51];
int main()
{   ifstream f("gramada.in");
    ofstream g("gramada.out");
    int i,nr=0,n;
    v[1]=v[2]=1;
    i=2;
    while(v[i]<=1000000000)
    {
       v[i]=v[i-1]+v[i-2];
        i++;

    }
    f>>n;
    do
    {
        nr++;
        i=1;
        while(v[i]<=n)
        i++;
        n=n-v[i-1];
    }while(n!=0);
    if(nr==1) g<<0;
    else g<<v[i-1];
    return 0;

}
