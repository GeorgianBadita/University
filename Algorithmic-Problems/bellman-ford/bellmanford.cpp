#include <cstdio>
#include <vector>
#include <deque>
#define NMAX 50005
#define INF 2*1e9
#define pb push_back
#define mp make_pair
using namespace std;
FILE *f = freopen("bellmanford.in", "r", stdin);
FILE *g = freopen("bellmanford.out", "w", stdout);
vector <pair <int, int> > Graph[NMAX];
deque <int> q;
vector <int> cnt_in_queue(NMAX, 0);
long long  int dist[NMAX];
int  n, m;
bool in_queue[NMAX] = {false}, negative_cycle = false;
void read()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i<=m ;i++)
    {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        Graph[x].pb(mp(y, c));
    }
}
void bellman(int start)
{
    q.pb(start);
    in_queue[start] = true;
    for(int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[start] = 0;
    while(!q.empty() && !negative_cycle)
    {
        int top = q.front();
        in_queue[top] = false;
        q.pop_front();
        for(vector <pair <int, int> > ::iterator it= Graph[top].begin(); it != Graph[top].end(); it++)
        {
                if(dist[top] + it->second < dist[it -> first])
                {
                    dist[it -> first] = dist[top] + it -> second;
                    if(!in_queue[it -> first])
                    {
                        if(cnt_in_queue[it->first] > n)
                            negative_cycle = true;
                        else
                        {
                            q.pb(it -> first);
                            in_queue[it -> first] = true;
                            cnt_in_queue[it -> first] ++;
                        }
                    }
                }
        }
    }
}
int main()
{
    read();
    bellman(1);
    if(negative_cycle) printf("Ciclu negativ!\n");
    else {
        for(int i = 2; i<=n; i++)
            printf("%d ", dist[i]);
    }
    return 0;
}
