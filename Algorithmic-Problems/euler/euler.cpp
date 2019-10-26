#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#define pb push_back
#define NMAX 100010
#define MAX_NODES 500010
using namespace std;
FILE *f= freopen("ciclueuler.in", "r", stdin);
FILE *g= freopen("ciclueuler.out", "w", stdout);
vector <int> l[NMAX];
vector <int> q;
int cycle[MAX_NODES];
int n, m, lg;
void read()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i<=m; i++)
    {
        int x ,y;
        scanf("%d%d", &x, &y);
        l[x].pb(y);
        l[y].pb(x);
    }
}
int verif_cycle(int n, vector <int> l[])
{
    for(int i = 1; i<=n; i++)
        if(l[i].size() % 2 == 1) return 0;
    return 1;
}
void make_cycle()
{
    q.pb(1);
    while(!q.empty())
    {
        int node = q.back();
        if(!l[node].empty())
        {
            int new_node = l[node].back();
            l[node].pop_back();
            l[new_node].erase(find(l[new_node].begin(), l[new_node].end(), node));
            q.push_back(new_node);
        }
        else
        {
            cycle[++lg] = node;
            q.pop_back();
        }
    }
}
void write()
{
    if(verif_cycle(n, l)) {
            make_cycle();
    for(int i = 1; i<lg; i++)
        printf("%d ", cycle[i]);
    }
    else printf("%d", - 1);

}
int main()
{
    read();
    write();
    return 0;
}
