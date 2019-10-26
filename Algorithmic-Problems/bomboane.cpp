#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if((n*2+3)%3!=2)
    cout<<"Nu exista solutie";
    else
    cout<<n*2+3;
}
