#include <cstdio>
#include <vector>
#define foreach(V) for(typeof (V).begin() it = (V).begin(); it != (V).end(); ++it)
#define pb push_back
#define MAX_N 100005
#define MAX_L 20

using namespace std;

FILE *f = freopen("lca.in", "r", stdin);
FILE *g = freopen("lca.out", "w", stdout);

int k, M, N;
int Niv[MAX_N << 1], Euler[MAX_N << 1], First[MAX_N << 1];
int Rmq[MAX_L][MAX_N << 2], Lg[MAX_N << 1];

vector <int> G[MAX_N];

void read()
{
    scanf("%d%d", &N, &M);

    for(int i = 2; i<=N; i++)
    {
        int x;
        scanf("%d", &x);
        G[x].pb(i);
    }
}

void dfs(int nod, int niv)
{
    Euler[++k] = nod;
    Niv[k] = niv;
    First[nod] = k;
    foreach(G[nod])
    {
        dfs(*it, niv + 1);
        Euler[++k] = nod;
        Niv[k] = niv;
    }
}

void rmq()
{
    for(int i = 2; i<=k; i++)
        Lg[i] = Lg[i / 2] + 1;
    for(int i = 1; i<=k; i++)
        Rmq[0][i] = i;
    for(int i = 1; (1 << i) < k; ++i)
        for(int j = 1; j<= k - (1 << i); ++j)
        {
            int l = 1 << (i - 1);
            Rmq[i][j] = Rmq[i - 1][j];
            if(Niv[Rmq[i - 1][j]] < Niv[Rmq[i][j]])
                Rmq[i][j] = Rmq[i - 1][j + 1];
        }
}
int lca(int x, int y)
{
    int diff, sol, sh, l;
    int a = First[x], b = First[y];

    if(a > b) swap(a, b);
    diff = b - a + 1;
    l = Lg[diff];
    sol = Rmq[l][a];
    sh = diff - (1 << l);
    if(Niv[sol] > Niv[Rmq[l][a + sh]])
        sol = Rmq[l][a + sh];
    return Euler[sol];
}
int main()
{
    read();
    dfs(1, 0);
    rmq();
    while(M --)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", lca(x, y));
    }
    return 0;
}
