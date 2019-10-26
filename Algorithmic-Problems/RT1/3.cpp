#include<iostream>
using namespace std;
int c(int n)
{
    if(n==1) return 0;
    else return n*n+c(n-1);
}
int main()
{
    int n;
    cout<<c(10);
}
