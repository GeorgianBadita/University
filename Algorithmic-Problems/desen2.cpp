#include<fstream>
using namespace std;
int main()
{
    ifstream f("desen2.in");
    ofstream g("desen2.out");
    int a,b,cmmdc,p,r,x,y,figuri,latura;
    f>>x>>y; p=x*y; a=x; b=y;
    while(y!=0)
        {
            r=x%y;
            x=y;
            y=r;
        }
        cmmdc=x;  figuri=cmmdc;
        latura=p/cmmdc;

        figuri=latura/cmmdc;
        if(cmmdc==a)
        figuri=latura/b;
        g<<latura<<'\n'<<figuri;


}
