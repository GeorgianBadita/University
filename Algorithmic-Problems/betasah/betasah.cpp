#include<fstream>
using namespace std;
int d,v[1003],dama[103][3];
int a[1003][1003];
int main()
{
    ifstream f("betasah.in");
    ofstream g("betasah.out");
    int n,d,k,i,l,c,P,p1,j;
    f>>n>>d>>k;
    for(i=1;i<=d;i++)
    {
        f>>l>>c;
        a[l][c]=1;
        dama[i][1]=l;dama[i][2]=c;
    }

for(i=1;i<=n;i++)v[i]=i;
    for(i=1;i<=k;i++)
    {
        f>>l>>c;
        a[l][c]=2;
        v[l]--;
    }
    int M=v[1];
    for(i=2;i<=n;i++)M=max(v[i],M);
    g<<M<<'\n';
    for(i=0;i<=n+1;i++)
    a[i][0]=a[i][i+1]=a[i][i+2]=2;
    for(j=0;j<=n+2;j++)
    a[n+1][j]=2;
    for(i=1;i<=d;i++)
    {
        l=dama[i][1]; c=dama[i][2];

        j=c-1;
            while(a[l][j]!=2)
            {
               if(a[l][j]==0)a[l][j]=3;
               j--;
            }
            j=c+1;
            while(a[l][j]!=2)
            {
                if(a[l][j]==0)a[l][j]=3;
                j++;
            }

          p1=l-1;
            while(a[p1][c]!=2)
            {
                if(a[p1][c]==0)a[p1][c]=3;
                p1--;
            }
            p1=l+1;
            while(a[p1][c]!=2)
            {
                if(a[p1][c]==0)a[p1][c]=3;
                p1++;
            }

       p1=l-1; j=c-1;
            while (a[p1][j]!=2)
            { if(a[p1][j]!=1) a[p1][j]=3;
              p1--; j--;}
            p1=l+1; j=c+1;
            while (a[p1][j]!=2)
            { if(a[p1][j]!=1) a[p1][j]=3;
              p1++; j++;}

        p1=l-1; j=c+1;
            while (a[p1][j]!=2)
            { if(a[p1][j]!=1) a[p1][j]=3;
              p1--; j++;}
            p1=l+1; j=c-1;
            while (a[p1][j]!=2)
            { if(a[p1][j]!=1) a[p1][j]=3;
              p1++; j--;}
    }

     P=0;
    for(i=1;i<=n;i++)
    for(j=1;j<=i;j++)
       if(a[i][j]==3)P++;
       g<<P;
    return 0;

}
