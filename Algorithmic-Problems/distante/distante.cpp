#include <cstdio>
#include <vector>
#include <deque>
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
FILE *f = freopen("distante.in", "r", stdin);
FILE *g = freopen("distante.out", "w", stdout);
vector < pair<int,int> > v[50005];
int dist[50005];
 long long int D[50005];
bool in_queue[50005];
deque <int> q;
int n, m, T, start;
void write();
void clear_()
{
    for(int i = 1; i<=n; i++)
        v[i].clear();
}
void solve(int start)
{
    q.pb(start);
    in_queue[start] = 1;
    for(int i = 1; i<=n; i++)
        D[i] = INF;
    D[start] = 0;
    while(!q.empty())
    {
        int nod = q.front();
        q.pop_front();
        in_queue[nod] = false;
        for(vector <pair <int, int> >::iterator it=v[nod].begin();it!=v[nod].end();it++)
        {
                if(D[nod] + it -> second < D[it -> first])
                {
                    D[it -> first] = D[nod] + it -> second;
                    if(!in_queue[it -> first])
                    {
                        in_queue[it -> first] = true;
                        q.pb(it->first);
                    }
                }
        }
    }
}

void write()
{
    int ok = 1;
    for(int i = 1; i<=n; i++)
        if(dist[i] != D[i])
    {
        ok = 0;
        break;
    }
    if(!ok) printf("NU\n");
    else printf("DA\n");
}
int main()
{
    scanf("%d", &T);
    while(T)
    {
        T --;
        clear_;
        scanf("%d%d%d", &n, &m, &start);
        for(int i = 1; i<=n; i++)
            scanf("%d", &dist[i]);
        for(int i = 1; i<=m; i++)
        {
            int x, y, c;
            scanf("%d%d%d", &x, &y, &c);
            v[x].pb(mp(y, c));
            v[y].pb(mp(x, c));
        }
        solve(start);
        write();
    }
        return 0;
}
