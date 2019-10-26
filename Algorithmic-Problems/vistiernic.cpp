#include<fstream>
using namespace std;
int main()
{
    ifstream f("vistiernic.in");
    ofstream g("vistiernic.out");
    int long long i,p=1,x,s2=0,n,y,s5=0;
    f>>n;
    for(i=1;i<=n;i++)
        {
            f>>x; y=x;

            while(x%2==0&&x!=0)
                {s2++;
                x=x/2;}

           if(y%10==0||y%10==5)
               {
                   while(y%5==0&&y!=0)
                    {s5++;
                    y/=5;}
               }
        }
       if(s2>s5)
       g<<s5;
       else g<<s2;

}
