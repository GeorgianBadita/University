#include<fstream>
using namespace std;
float a(float n,float x)
{   if(n==0)
    a(0,x)=x+1;
    else if(x==1.0)
    a(n+1.0)=a(n,1);
    else return a(n+1,x+1)=a(n,a(n+1,x));
}
int main()
{
    cout<<a(4,3); //nici aici nimic....
}
