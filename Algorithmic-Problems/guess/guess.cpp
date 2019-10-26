#include<fstream>
using namespace std;
ifstream f("guess.in");
ofstream g("guess.out");
int x1,x2;
char l1,l2;
char v[1001];
int main()
{
    int p,n,i;
    f>>n>>p;
    for(i=1;i<=p;i++)
    {
        f>>x1>>l1>>x2>>l2;
        v[x1]=l1;
        v[x2]=l2;
    }
    for(i=1;i<=n;i++) g<<v[i];

}
