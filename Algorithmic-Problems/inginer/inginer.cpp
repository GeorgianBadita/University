# include <fstream>
using namespace std;
char c[78][78];
int v[78][78];
int lin[6300],col[63000];
int main()
{
    int n,m,x1,y1,x2,y2,j,p,u,i,rez,o,q;
    ifstream in("inginer.in");
    ofstream out("inginer.out");
    in>>n>>m;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++) in>>c[i][j];
    }
    for (i=0;i<=n+1;i++)
    {
        c[i][0]=c[i][m+1]='.';
    }
    for (j=0;j<=m+1;j++)
    {
        c[0][j]=c[n+1][j]='.';
    }
    x1=1;
    while (x1!=0)
    {
        in>>x1>>y1>>x2>>y2;
        rez=0;
        if (x1==0) break;
        lin[1]=x1;
        col[1]=y1;
        p=u=1;
        while (p<=u)
        {
            i=lin[p]; j=col[p];
            if (i>0 && c[i-1][j]=='.' && v[i-1][j]==0)
            {
                v[i-1][j]=v[i][j]+1;
                u++;
                lin[u]=i-1;
                col[u]=j;
                if (lin[u]==x2 && col[u]==y2) break;
            }
            if (i<n+1 && c[i+1][j]=='.' && v[i+1][j]==0)
            {
                v[i+1][j]=v[i][j]+1;
                u++;
                lin[u]=i+1;
                col[u]=j;
                if (lin[u]==x2 && col[u]==y2) break;
            }
            if (j>0 && c[i][j-1]=='.' && v[i][j-1]==0)
            {
                v[i][j-1]=v[i][j]+1;
                u++;
                lin[u]=i;
                col[u]=j-1;
                if (lin[u]==x2 && col[u]==y2) break;
            }
            if (j<m+1 && c[i][j+1]=='.' && v[i][j+1]==0)
            {
                v[i][j+1]=v[i][j]+1;
                u++;
                lin[u]=i;
                col[u]=j+1;
                if (lin[u]==x2 && col[u]==y2) break;
            }
            if (i+1==x2 && j==y2) break;
            else
            if (i-1==x2 && j==y2) break;
            else
            if (i==x2 && j+1==y2) break;
            else
            if (i==x2 && j-1==y2) break;
            else
            if (p==u && i!=x2)
            {
                v[i][j]=-1;
                break;
            }
            else
            if (p==u && j!=y2)
            {
                v[i][j]=-1;
                break;
            }
            p++;
        }
        out<<v[i][j]+1<<endl;
        for (o=0;o<=n+1;o++) for (q=0;q<=m+1;q++) v[o][q]=0;
    }
    return 0;
}
