#include<iostream>
using namespace std;
int main()
{
    int  n,x,y,z;
    cout<<"Dati un n: "; cin>>n;
    if(n==1||n==2) cout<<1; else{
    x=1;y=1;
    for(int i=1;i<=n;i++)
    {
        z=x+y;
        x=y;
        y=z;

    }
    cout<<z;
    }

}
