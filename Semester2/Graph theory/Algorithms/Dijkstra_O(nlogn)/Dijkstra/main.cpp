/*
 * Supr*
*/

#include <cstdio>
#include <vector>
#include <queue>
#define pb push_back
#define INF 1e9
#define NMAX 50005

using namespace std;

/* FILES */
FILE *f = freopen("dijkstra.in", "r", stdin);
FILE *g = freopen("dijkstra.out", "w", stdout);

/* Data structures */
struct node{
    int y, cost;
    bool operator < (const node& other) const {
        return cost > other.cost;
    }
    node(int y, int cost) {
        this -> y = y;
        this -> cost = cost;
    }
};

/* Declarations */
int dist[NMAX], n = 0, m = 0;
vector <node> G[NMAX];
priority_queue <node> Q;

/* Dijkstra's Algorithm */

void dijkstra(int n, vector <node> G[NMAX], priority_queue <node> Q, int start, int dist[]) {
    for(int i = 1; i<=n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    Q.push(node(start, dist[start]));
    while(!Q.empty()) {
        int nod = Q.top().y;
        int cost = Q.top().cost;
        Q.pop();
        if(dist[nod] != cost) {
            continue;
        }
        vector <node> ::iterator it;
        for(it = G[nod].begin(); it != G[nod].end(); it++) {
            if(dist[nod] + it->cost < dist[it->y]) {
                dist[it -> y] = dist[nod] + it->cost;
                Q.push(node(it->y, dist[it->y]));
            }
        }
    }
}

/* Read Data */

void read_data(int &n, int &m, vector <node> G[NMAX]) {
    scanf("%d%d", &n, &m);
    for(int i = 1; i<=m; i++) {
        int x, y, cost;
        scanf("%d%d%d", &x, &y, &cost);
        G[x].pb(node(y, cost));
    }
}

/* Print result */

void print_res(int n, int a[]) {
    /*
     * Will print from index 2, assuming we start in node 1
    */
    for(int i = 2; i<=n; i++) {
        a[i] != INF ? printf("%d ", a[i]) : printf("0 ");
    }
}

int main() {
    read_data(n, m, G);
    dijkstra(n, G, Q, 1, dist);
    print_res(n, dist);
    return 0;
}
