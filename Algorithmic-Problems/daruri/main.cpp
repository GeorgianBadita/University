# include<fstream>
using namespace std;
ifstream f("daruri.in");
ofstream g("daruri.out");
int cmmdc(int a, int b)
{
    if(a==0) return b;
    if(b==0) return a;
    else return cmmdc(b,a%b);
}
int main()
{
    g<<cmmdc(10,15);
}
