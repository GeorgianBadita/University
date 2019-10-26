#include<fstream>
using namespace std;
int v[100],t[100];
int main()
{
    ifstream f("anagramabil.in");
    ofstream g("anagramabil.out");
    unsigned long long nc=0,n,x,i,a=2,na,z;
    f>>n;
    x=n;
    while(x!=0)
     {
         v[x%10]++;
         x/=10;

     }
     //for(i=0;i<=9;i++)
        //{
          //  if(v[i]!=0)
          //   g<<i<<' ';
       // }



     while(a<9)
        {
          na=n*a;
           z=na;
          while(z!=0)
           {
               t[z%10]++;
               z/=10;
           }

          for(i=0;i<=9;i++)
            {
                if(v[i]==t[i])
                 {g<<a;

                 }
            }
            a++;
        }

}
