#include<fstream>
using namespace std;
int main()
{
    ifstream f("triunghi1.in");
    ofstream g("triunghi1.out");
    int nr,l,c,s,cif;
    f>>l>>c;
    s=(l*(l-1)/2)+c;
    nr=s%9;
    if(nr==0) nr=9;
    g<<nr;
    return 0;
}
