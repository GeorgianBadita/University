#include <cstdio>
#include <iostream>
#include <vector>
#include <deque>
#define NMAX 1000005
#define mp make_pair
#define pb push_back
using namespace std;

FILE *f = freopen("trmv.in", "r", stdin);
FILE *g = freopen("trmv.out", "w", stdout);
vector <pair <int, int > > v[NMAX];
deque <int> q;
vector <pair <int, int > > :: iterator it;
bool inqueue[NMAX];
int father[NMAX];

void bfs(int start)
{
    inqueue[start] = 1;
    q.push_back(start);
    while(!q.empty())
    {
        int node = q.front();
        q.pop_front();
        for(it = v[node].begin(); it!= v[node].end(); ++it)
            if(!inqueue[v[node][it->first])

    }
}
int main()
{
}
