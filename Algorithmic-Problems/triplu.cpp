#include<fstream>
#include<cmath>
using namespace std;
int main()
{
    ifstream f("triplu.in");
    ofstream g("triplu.out");
    int long long a,b,c1,c2,nr1=0,nr2=0,aux,s1,j,s2,i,max1,s;
    f>>a>>b;
    j=a;i=b;
    do
    {
        c1=a%10;
        a=a/10;
        nr1++;

    }while(a!=0);

     do
     {
         c2=b%10;
        b=b/10;
        nr2++;
     }while(b!=0);
     if(nr1>nr2)
     max1=nr1;
     else max1=nr2;
      if(nr1==nr2)
     max1=nr1;
     if(nr1>nr2)
     aux=nr2;
     else aux=nr1;
     if(nr1<nr2)
     {s1=(j*pow((float)10,(int)max1))+i;
     s2=(i*pow((float)10,(int)aux)+j);
     }
      else if(nr1>nr2)
       {s1=(j*pow((float)10,(int)aux))+i;
        s2=(i*pow((float)10,(int)max1))+j;
        }
       else if(nr1==nr2)
       {
           s1=i*pow((float)10,(int)max1)+j;
            s2=j*pow((float)10,(int)max1)+i;

       }

       if(j==i)
       {s=(i*pow((float)10,(int)max1)+j)*3;
       g<<s;
       }
       if(s1>s2)
       g<<s1*3;
       else if(s2>s1) g<<s2*3;







    return 0;
}
