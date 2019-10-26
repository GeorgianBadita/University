#include <cstdio>
#include <queue>
#include <vector>
#define NMAX 36005
#define pb push_back
#define INF 2*1e12
using namespace std;

FILE *f = freopen("catun.in", "r", stdin);
FILE *g = freopen("catun.out", "w", stdout);

class vecin{
public:
    int y, cost;
    vecin(int y, int cost)
    {
        this -> y = y;
        this -> cost = cost;
    }

};
struct sat{
    long long minim;
    int fort;
}satuc[NMAX];
vector <vecin> G[NMAX];
queue <int> Q;
queue <int> catun;
vector <int> finals;
long long  Dist[NMAX];
bool inqueue[NMAX], incatun[NMAX];
int N, M, K;
void read()
{
    scanf("%d%d%d", &N, &M, &K);
    for(int i = 1; i<=K; i++)
        {
            int x;
            scanf("%d", &x);
            incatun[x] = true;
            catun.push(x);
        }
    for(int i = 1; i<=M; i++)
    {
        int x, y, dist;
        scanf("%d%d%d", &x, &y, &dist);
        G[x].pb(vecin(y, dist));
        G[y].pb(vecin(x, dist));
    }
}
void bellman(int start)
{
    for(int i = 1; i<=N; i++)
        Dist[i] = INF;
    for(int i = 0; i<=N; i++)
        inqueue[i] = false;
    Q.push(start);
    vector <vecin> ::iterator  it;
    inqueue[start] = true;
    Dist[start] = 0;
    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        inqueue[node] = false;
        for(it = G[node].begin(); it != G[node].end(); it++)
            if(Dist[node] + it -> cost < Dist[it -> y])
            {
                Dist[it -> y] = Dist[node] + it -> cost;
                if(!inqueue[it -> y]) {
                Q.push(it -> y);
                inqueue[it -> y] = true;
                }
            }
    }
}
void solve()
{
    for(int i = 1; i<=N; i++)
        satuc[i].minim = INF;
    while(!catun.empty())
    {
        int fort = catun.front();
        catun.pop();
        bellman(fort);
        for(int i = 1; i<=N; i++)
            if(Dist[i] < satuc[i].minim)
        {
            satuc[i].minim = Dist[i];
            satuc[i].fort = fort;
        }

    }
    for(int i = 1; i<=N; i++)
       if(incatun[i] == true || satuc[i].minim == INF) printf("%d ", 0);
       else printf("%d ", satuc[i].fort);
}
int main()
{
    read();
    solve();
    return 0;
}
