#include<iostream>
#include<cmath>
using namespace std;
int mai()
{
    int n,x,r;
    cin>>n>>x;
    while(n!=0)
        {
            r=x%n;
            x=n;
            n=r;
        }
        cout<<x;


}
