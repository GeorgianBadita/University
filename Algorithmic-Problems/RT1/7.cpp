#include<iostream>
using namespace std;
int v[100];
int  f(int n)
{   int a[1000];
    if(n==0) return 1;
    else return a[n]*f(n-1);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {cin>>v[i];cout<<f(n);}
    // nu stiu unde e greseala, poate iti dai tu seama..
}
