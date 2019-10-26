#include<fstream>
using namespace std;
ifstream f("plagiat.in");
ofstream g("plagiat.out");
int main()
{
    int t,i;
    f>>t;
    for(i=1;i<=t;i++)
    {
        if(i%2!=0) g<<"NU"<<'\n';
        else g<<"DA"<<'\n';

    }
}
