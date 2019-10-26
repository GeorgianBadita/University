#include<fstream>
using namespace std;
int main()
{
    ifstream f("diferit.in");
    ofstream g("diferit.out");
    int n,nr=0,c;
    do
    {
        c=n%10;
        nr++;
        n/=10;
        }while(n!=0);
           g<<nr;
}
