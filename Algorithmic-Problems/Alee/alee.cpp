#include <cstdio>
#include <vector>
#include <queue>
#define NMAX 180
using namespace std;

FILE *f = freopen("alee.in", "r", stdin);
FILE *g = freopen("alee.out", "w", stdout);

vector <int> G[NMAX];
bool inqueue[NMAX];
queue <int> Q;

void bfs(int start)
{
    inqueue[start] = true;
    Q.push(start);
    vector <int> ::iterator it;
    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        inqueue[node] = false;
        for(it = G[node].begin(); it != G[node].end(); it++)
            if(!inqueue[*it])
        {
            Q.push(*it);
            inqueue[*it] = true;
        }
    }
}
