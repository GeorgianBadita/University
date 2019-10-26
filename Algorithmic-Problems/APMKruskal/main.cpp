#include <cstdio>
#define NMAX 400100
#define pb push_back
#include <algorithm>
#include <vector>
using namespace std;

FILE *f = freopen("apm.in", "r", stdin);
FILE *g = freopen("apm.out", "w", stdout);
int Father[NMAX];
vector <int> ANS;
int x[NMAX], y[NMAX], cost[NMAX], ind[NMAX], N, M, costsol;
int find_(int x)
{
   if(Father[x] == x) return x;
   Father[x] = find_(Father[x]);
   return Father[x];
}
void unite_(int x, int y)
{
    Father[find_(y)] = find_(x);
}
bool cmp(int x, int y)
{
    return cost[x] < cost[y];
}
void read()
{
    scanf("%d%d", &N, &M);
    for(int i = 1; i<=M; i++)
    {
        scanf("%d%d%d", &x[i], &y[i], &cost[i]);
        ind[i] = i;
    }
    sort(ind + 1, ind + M + 1, cmp);
    for(int i = 1; i<=N; i++) Father[i] = i;
}
void solve()
{
    for(int i = 1; i<=M; i++)
    {
        if(find_(x[ind[i]]) != find_(y[ind[i]])) {
            costsol += cost[ind[i]];
            unite_(x[ind[i]], y[ind[i]]);
            ANS.pb(ind[i]);
        }
    }
}
void write()
{
    printf("%d\n", costsol);
    printf("%d\n", N - 1);
    for(int i = 0; i<N - 1; i++)
        printf("%d %d\n", x[ANS[i]], y[ANS[i]]);
}
int main()
{
    read();
    solve();
    write();
    return 0;
}
