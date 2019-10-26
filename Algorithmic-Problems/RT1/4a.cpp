#include<iostream>
using namespace std;
long long  p(long long n)
{
    if(n==1) return 2;
    else return 2*n*p(n-1);
}
int main()
{
    cout<<p(10);
}
