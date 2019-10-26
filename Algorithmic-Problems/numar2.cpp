#include<iostream>
using namespace std;
int main()
{
int long long v[200000],n,i,ras;
cout<<"Introduceti numarul de elemente al vectorului: ";
do{
cin>>n;
if(n<0||n>20000)
cout<<"Introduceti alta valoare!";
}while(n<0||n>20000);
for(i=1;i<=n;i++)
v[i]=i*i*i;
cout<<"Primele "<<n<<" cuburi perfecte sunt:"<<endl;
for(i=1;i<=n;i++)
  {
     ras=0;
     do
     {
         ras=ras*10+v[i]%10;
         v[i]=v[i]/10;
         cout<<v[i]<<'\n' ;
     }while(v[i]!=0);

  }
}
