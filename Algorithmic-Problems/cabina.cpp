#include<fstream>
using namespace std;
int main()
{
    ifstream f("cabina.in");
    ofstream g("cabina.out");
    int pers,i,n,p1,p2,p3,h1,h2,h3,cons,special=0;
    f>>n;
    f>>h1>>p1;
    f>>h2>>p2;
    pers=p1+p2;
    cons=0;
    if(h1>h2)
    cons=cons+(h1-h2)*1;
    else cons=cons+(h2-h1)*3;
    for(i=3;i<=n;i++)
        {f>>h3>>p3;
            pers+=p3;
            if((h2>h1)&&(h2>h3)||(h2<h1)&&(h2<h3))
            special++;
            if(h3<h2)
                 cons=cons+(h2-h3)*1;
            else cons=cons+(h3-h2)*3;
                h1=h2;
                p1=p2;
                h2=h3;
                p2=p3;

        }
        g<<pers<<'\n'<<cons<<'\n'<<special;
        return 0;
}

