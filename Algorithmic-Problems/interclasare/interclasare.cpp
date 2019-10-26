#include<string.h>
#include<cstdio>
char a[10009], b[10009], c[20009];
int d[2][10009], nr[2];
int N,M,NM,P,T,t,r,cr,i,k,ok,i1,j1,egal;

int main(){
    freopen("interclasare.in","rt",stdin);
    freopen("interclasare.out","wt",stdout);
    scanf("%d\n",&T);
    for (t=1;t<=T;t++){
        scanf("%s %s %s\n",a+1,b+1,c+1);
        N=strlen(a+1);
        M=strlen(b+1);
        NM=strlen(c+1);
        cr=0;
        if(b[1]==c[1]){
            d[1][cr++]=0;
        }
        if(a[1]==c[1]){
            d[1][cr++]=1;
        }
        nr[1]=cr;
        ok=1;
        for(k=2;k<=NM;k++){
            r=k%2;
            cr=0;
            for(i=0;i<nr[1-r];i++){
                i1=d[1-r][i];
                j1=k-1-i1;
                if(((cr==0) ||(cr>0 && d[r][cr-1]!=i1)) && j1<M && b[j1+1]==c[k]){
                    d[r][cr++]=k-(j1+1);
                }
                if( i1<N && a[i1+1]==c[k]){
                    d[r][cr++]=i1+1;
                }
            }
            nr[r]=cr;
            if(cr==0){
                ok=0;
                break;
            }
        }
        printf("%d\n",ok);
    }
    fclose(stdout);
    return 0;
}

