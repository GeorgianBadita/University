#include<iostream>
using namespace std;
int main()
{  int a,nr=0;
cout<<"a=";cin>>a;
while(a!=0)
{ if((a%10)%2==1)
nr++;
a/=10;
}
cout<<"nr="<<' '<<nr;
}
