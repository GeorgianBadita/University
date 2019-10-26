#include<cstdio>
using namespace std;
int a[101][101],n,m;
int size;
void fill(int i,int j,int k)
{
    if(a[i][j]==0)
    {
        a[i][j]=k;
        size++;

        if(i>1&&a[i-1][j]==0) fill(i-1,j,k);
        if(i<n&&a[i+1][j]==0) fill(i+1,j,k);
        if(j>1&&a[i][j-1]==0) fill(i,j-1,k);
        if(j<n&&a[i][j+1]==0) fill(i,j+1,k);
    }
}

int main()
{
    int i,j;
    FILE *fin=freopen("foto.in","r",stdin);
    FILE *fout=freopen("foto.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(i=0;i<=m+1;i++) a[i][0]=a[i][m+1]=1;
    for(j=0;j<=n+1;j++) a[0][j]=a[n+1][j]=1;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    int max=0;
    int k=1;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i][j]==0){
                k++;
                size=0;
                fill(i,j,k);
                if(max<size&&size<=m*n) max=size;
            }
    printf("%d",max);
    fclose(fin);
    fclose(fout);
    return 0;
}
