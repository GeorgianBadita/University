#include <cstdio>
#include <deque>
#include <climits>
#include <vector>
#define pb push_back
#define pf pop_front
#define sz size
#define NMAX 50001
#define INF INT_MAX

using namespace std;

FILE *f = freopen("bellmanford.in", "r", stdin);
FILE *g = freopen("bellmanford.out", "w", stdout);

class node{
public:
    int y, cost;
    node(int y, int cost) {
        this -> y = y;
        this -> cost = cost;
    }
};

vector <node> G[NMAX];
deque <int> Q;
bool negative = false;
int n = 0, m = 0, dist[NMAX];

void read_data(int &n, int &m) {
    scanf("%d%d", &n, &m);
    for(int i = 1; i<=m; i++) {
        int x, y, cost;
        scanf("%d%d%d", &x, &y, &cost);
        G[x].pb(node(y, cost));
    }
}


void bellman(int n, int start, deque <int> Q, vector<node> G[NMAX], int dist[], bool &negative) {
    int cnt_cycle[n + 1];

    for(int i =1 ; i<=n; i++) {
        dist[i] = INF;
        cnt_cycle[i] = 0;
    }
    Q.pb(start);
    vector<node> ::iterator it;
    dist[start] = 0;
    while(!Q.empty()) {
        int node = Q.front();
        Q.pf();
        for(it = G[node].begin(); it != G[node].end(); it++) {
            if(dist[node] + it->cost < dist[it->y]) {
                dist[it->y] = dist[node] + it->cost;
                   if(cnt_cycle[it->y] > n) {
                       negative = true;
                       return;
                   }
                   else {
                        Q.pb(it->y);
                        cnt_cycle[it->y] ++;
                   } 
            }
        }
    }
}


int main() {
    read_data(n, m);
    bellman(n, 1, Q, G, dist, negative);
    if(negative == true) {
        printf("Ciclu negativ!");
    }else {
        for(int i = 2; i<=n; i++) {
            printf("%d ", (dist[i] < INF ? dist[i]:0));
        }
    }
    return 0;
}
