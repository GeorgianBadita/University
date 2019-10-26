#include <cstdio>
#include<cstring>
#define maxim(a, b) ((a > b) ? a : b)
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define NMax 1024

int M, N, D[NMax][NMax], sir[NMax], bst;
char A[NMax],B[NMax];

int main(void)
{
    int i, j;

    freopen("codul.in", "r", stdin);
    freopen("codul.out", "w", stdout);
    scanf("%s",&A);
    scanf("\n");
    scanf("%s",&B);
    N=strlen(A);
    M=strlen(B);
    for(i=1;i<=N;i++) A[i]=A[i]-'0';
    for(i=1;i<=M;i++) B[i]=B[i]-'0';
    FOR (i, 1, M)
        FOR (j, 1, N)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);

    for (i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;

    printf("%d\n", bst);
    for (i = bst; i; --i)
        printf("%d ", sir[i]);

    return 0;
}



