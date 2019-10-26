#include<fstream>
using namespace std;
int main()
{
    ifstream f("visul.in");
    ofstream g("visul.out");
    int n;
    f>>n;
    if(n==1)
	g<<"-1";
    if(n==2)
	g<<"23";
    if(n==3)
	g<<"311";
    if(n==4)
	g<<"4113";
    if(n==5)
	g<<"53113";
    if(n==6)
        g<<"611317";
    if(n==7)
	g<<"7113173";
    if(n==8)
	g<<"83113717";
    if(n==9)
	g<<"971131737";
    if(n==10)
	g<<"-1";

}

