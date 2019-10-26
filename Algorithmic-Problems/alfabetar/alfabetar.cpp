# include <fstream>
# include <cstring>
using namespace std;
char v[101][201];
int y[101];
char c[201][201];
int main()
{
    int b,i,n=0,m=-1;
    ifstream in("alfabetar.in");
    ofstream out("alfabetar.out");
    in>>b;
    for (i=0;i<=b-1;i++)
    {
        in>>v[i];
        y[i]=strlen(v[i]);
        //out<<y[i];
    }
    int j=0;
    while (j!=b)
    {
        for (i=0;i<=y[j]-1;i++)
        {
            if (i==0)
            {
                n=0;
                m++;
                c[n][m]=v[j][i];
                //out<<c[n][m]<<' '<<n<<' '<<m<<endl;
            }
            else
            {
                n++;
                c[n][m]=v[j][i];
                //out<<c[n][m]<<' '<<n<<' '<<m<<endl;
            }
        }
        j++;
    }
    int max=0;
    for (i=0;i<=b-1;i++) if (y[i]>max) max=y[i];
    //out<<max;
    for (i=max-1;i>=0;i--)
    {
        for (j=0;j<=b-1;j++)
        {
            if (c[i][j]==0) out<<' ';
            else
            out<<c[i][j];
            if (j==b-1) out<<endl;
        }
    }
    for (i=0;i<=b-1;i++)
    {
        for (j=0;j<=y[i]-1;j++)
        {
            //out<<v[i][j];
            //if (j==y[i]-1) out<<endl;
        }
    }
    //out<<n<<' '<<m;

    return 0;
}
