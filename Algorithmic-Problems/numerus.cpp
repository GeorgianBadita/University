#include<fstream>
using namespace std;
int main()
{
    ifstream f("numerus.in");
    ofstream g("numerus.out");
    int n,k,i,linia;

    f>>k>>n;

       if(k%2==0)
        {
        g<<5*k<<' '<<5*k<<' '<<5*k-1<<' '<<5*k-2<<' '<<5*k-3<<' '<<5*k-4<<'\n';
        }
        else if(k%2==1)
            {
                g<<5*k-4<<' '<<5*k-3<<' '<<5*k-2<<' '<<5*k-1<<' '<<5*k<<' '<<5*k<<'\n';
            }
            if(n==1||n%10==5||n%10==0)
                linia=n/5;
                else linia=(n/5)+1;
                g<<linia;
                if(n%10==0)
                g<<'\n'<<"A B";
                else if(n%10==1)
                g<<'\n'<<"A";
                else if(n%10==2)
                g<<'\n'<<"B";
                else if(n%10==3||n%10==9)
                g<<'\n'<<"C";
                else if(n%10==4||n%10==8)
                g<<'\n'<<"D";
                else if(n%10==7)
                g<<'\n'<<"E";
                else if(n%10==6)
                g<<'\n'<<"F";
                else if(n%10==5)
                g<<'\n'<<"E F";







}
