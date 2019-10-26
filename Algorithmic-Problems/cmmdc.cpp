#include<fstream>

using namespace std;

int main()

{
    ifstream f("adunare.in");
    ofstream g("adunare.out");
    int a,b;
    f>>a>>b;

 g<<a+b;


}
