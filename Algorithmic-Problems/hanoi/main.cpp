#include<iostream>
using namespace std;
char A,B,C;
int n;
void h(int n,char A,char B, char C)
{
if(n==1) cout<<A<<"->"<<B<<"\n";
else
{
h(n-1,A,C,B);
cout<<A<<"->"<<B<<"\n";
h(n-1,C,B,A);
}
}
int main()
{
cout<<"n=";cin>>n;
h(n,'A','B','C');
}
