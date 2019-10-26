# include <fstream>
# include <cstring>
using namespace std;
int v[101][101];
char c[251];
int main()
{
    int n,a,b,i,j,nr;
    ifstream in("traseu2.in");
    ofstream out("traseu2.out");
    in>>n;
    in>>a>>b;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (i!=0 && j!=0) in>>v[i][j];
            else
            if (i==0) v[i][j]=1;
            else
            if (j==0) v[i][j]=1;
        }
    }
    in>>c;
    nr=strlen(c);

for (i=0;i<=nr-1;i++)
    {
        if (c[i]=='N')
        {
            if (a==1) break;
            if (v[a-1][b]==0)
            {
                a--;
            }
        }
        else
        if (c[i]=='E')
        {
            if (b==n) break;
            if (v[a][b+1]==0)
            {
                b++;
            }
        }
        else
        if (c[i]=='V')
        {
            if (b==1) break;
            if  (v[a][b-1]==0)
            {
                b--;
            }
        }
        else
        if (c[i] =='S')
        {
            if (a==n) break;
            if (v[a+1][b]==0)
            {
                a++;
            }
        }
    }
    out<<a<<' '<<b;
    return 0;
}
