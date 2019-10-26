#include<fstream>
using  namespace std;
int main()
{
    ifstream f("robinson.in");
    ofstream g("robinson.out");
    int m,n,i,j,a[101][101],c,l;
    f>>m>>n>>l>>c;

  for(j=0;j<=m;j++)
        a[1][j]=n-1+j;

            for(i=0;i<=m;i++)
            a[i][1]=n-1+i;

               for(i=2;i<=m;i++)
               for(j=2;j<=m;j++)
                    a[i][j]=(a[i][j-1]+a[i-1][j])%1000;
                            g<<a[m][m]<<'\n';

                                i=l; j=c;

                while(i>=1&&i<=m&&j<=m&&j>=1&&a[i][j]!=-1)
                    {
                g<<i<<' '<<j<<'\n';
                        if(a[i][j]%4==0)
                                    {
                                        a[i][j]=-1;
                                        i--;
                                    }
                                    else if(a[i][j]%4==1)
                                        {
                                            a[i][j]=-1;
                                            j++;
                                        }
                                        else if(a[i][j]%4==2)
                                            {
                                                a[i][j]=-1;
                                                i++;
                                            }
                                            else if(a[i][j]%4==3)
                                                {
                                                    a[i][j]=-1;
                                                    j--;
                                                }


                    }
                    return 0;
}
