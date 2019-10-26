#include<iostream>
using namespace std;
int main()

{
    int a,b,c,s,n,x;
    cin>>n>>x;
    a=x;
    b=3*x;
    c=(a+b)/4;
    s=a+b+c;
    if(s>n)
    cout<<"Da"<<' '<<s-n;
    else cout<<"Nu"<<' '<<n-s;
}
