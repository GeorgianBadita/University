#include<fstream>
using namespace std;
ifstream f("muzeu.in");
ofstream g("muzeu.out");
int a,b,A,B;
int main()
{
    int n,i,k;
    f>>n>>k; A=k;B=0;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        if(b>=B) {A=A-(b-B);B=b;}
        else if(b<B&&a>=B-b) {A=A+(B-b);B=b;}
        else if(b<B&&a<B-b) {B=B-a;A=A+a;}
    }
    g<<A;
}
