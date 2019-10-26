#include<iostream>
using namespace std;
int main()
{
    int l,p,x,y,totalanimale,puiuti;
    cin>>x>>y;
    l=2*x;
    p=2*y;

    puiuti=4*x+y;
    totalanimale=puiuti+l+p;
    cout<<puiuti<<'\n'<<totalanimale;
    if(6*x>3*y)
    cout<<'\n'<<"leu"<<' '<<6*x-3*y;
    else cout<<'\n'<<"panda"<<' '<<3*y-6*x;


}
