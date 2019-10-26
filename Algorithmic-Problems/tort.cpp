#include<fstream>

using namespace std;

int main()

{
    int m,n,l,mm,ll,nr;

    ifstream f("tort.in");
    ofstream g("tort.out");

    f>>m>>n;
     mm=m; ll=n;
    while(m!=n)
    {
        if(m>n) m=m-n;
        else n=n-m;
        l=n;
    }
    if(mm==ll)
     g<<"1"<<" "<<mm;
     else
    {nr=mm*ll/(l*l);
    g<<nr<<' '<<l;}
}
