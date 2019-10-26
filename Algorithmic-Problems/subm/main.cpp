#include <iostream>
#include <cmath>
using namespace std;

int main()
{   int p,n;
    cin>>n;
    int i,nr=0,x,r;
    p=pow(2,n)-1;
    //cout<<p<<'\n';
    for(i=1;i<=p;i++)
    {   nr=0;
        x=i;
        while(x)
        {
            r=x%2; nr++; x/=2;
            if(r==1) cout<<nr<<' ';
        }
        cout<<'\n';
    }
}
