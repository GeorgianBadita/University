#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
#define NMAX 100010
#define MAX_NODES 500010
#define pb push_back
using namespace std;

vector <int> G[NMAX];
deque <int> q;
int cycle[MAX_NODES];
int N, M, lg;
FILE *f = freopen("ciclueuler.in", "r", stdin);
FILE *g = freopen("ciclueuler.out", "w", stdout);
void readData() {
    scanf("%d%d", &N, &M);
    for(int i = 1; i<=M; i++) {
            int x, y;
        scanf("%d%d", &x, &y);
        G[x].pb(y);
        G[y].pb(x);
    }
}
bool verif_cycle() {
    for(int i = 1; i<=N; i++)
        if(G[i].size() % 2 == 1) return false;
    return true;
}

void make_cycle() {
    q.pb(1);
    while(!q.empty()) {
        int node = q.back();
        if(!G[node].empty()) {
            int newNode = G[node].back();
            G[node].pop_back();
            G[newNode].erase(find(G[newNode].begin(), G[newNode].end(), node));
            q.pb(newNode);
        }
        else {
            cycle[++lg] = node;
             q.pop_back();
        }
    }
}
int main() {
    readData();
    if(verif_cycle()) {
        make_cycle();
        for(int i = 1; i<lg; i++)
            printf("%d ", cycle[i]);
    }
    else printf("-1");
    return 0;
}
