#include<fstream>
using namespace std;
int dif)
{
    if(x-y>0) return x-y;
    if(y-x>0) return y-x;
    return 0;
}
int main()
{
    ifstream f("ocr.in");
    ofstream g("ocr.out");
    int n,m,i,j;
    float a[52][53];
    f>>n>>m;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    f>>a[i][j];

    return 0;

}
