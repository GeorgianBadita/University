#include<iostream>
#include<cmath>
using namespace std;
int p(int n)
{
    if(n==1) return 2;
    else return pow(-1,n+1)*n*2*n*p(n-1);
}
int main()
{
    cout<<p(3);
}
