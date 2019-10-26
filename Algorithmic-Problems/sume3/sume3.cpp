#include<fstream>
#define NMAX 333334
using namespace std;
ifstream f("sume3.in");
ofstream g("sume3.out");
int s[NMAX],n;
int main()
{   int ant=1,i,sum;
    f>>n;
    n=n/3*3;
    s[0]=s[1]=s[2]=1;
    for(i=3;i<=n;i+=3)
    {
        sum=(ant+s[i/3])%1000000000;
        if(i<NMAX+3)
        {
            s[i]=s[i+1]=s[i+2]=sum;
        }
        ant=sum;
    }
    if(n<=3896)
    g<<sum;
    else for(i=100000000;i>=1;i/=10)
    g<<sum/i%10;
}
