#include<iostream>
using namespace std;
int main()
{
    int v[100],i,j,n,ok,aux;
    cin>>n;
    for(i=1;i<=n;i++)

         cin>>v[i];
        do {
              ok=1;
              for(i=1;i<=n-1;i++)
              if(v[i]>v[i+1])
              {
                  ok=0;
                  aux=v[i];v[i]=v[i+1];aux=v[i+1];
              }
           }while(ok==0);

       for(i=1;i<=n;i++)
       cout<<v[i]<<'\n';
}


