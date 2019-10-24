#include <cstdio>
#include <vector>
#include <deque>
#include <climits>
#define NMAX 50001
#define pb push_back
#define INF INT_MAX

using namespace std;


/* FILES */

FILE *f = freopen("dijkstra.in", "r", stdin);
FILE *g = freopen("dijkstra.out", "w", stdout);

/* Data structures */

struct node{
    int y, cost;
public:
    node(int y, int cost) {
        this -> y = y;
        this -> cost = cost;
    }
};

/* Declarations */

vector <node> G[NMAX];
bool used[NMAX];
int n = 0, m = 0;
int dist[NMAX];

/* Read data */

void read_data(int &n, int &m) {
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
     * Considering the start node is 1, we skip it
     */
    for(int i = 2; i<=n; i++) {
        a[i] != INF ? printf("%d ", a[i]) : printf("0 ");
    }
}


/* Dijkstra's algorithm */


int min_dist(int n, int dist[], bool used[]) {
    int minim = INF, pos = 0;
    for(int i = 1; i<n;i++) {
        if(used[i] == false && dist[i] < minim) {
            minim = dist[i];
            pos = i;
        }
    }
    return pos;
}

bool check_values(int a) {
    return a == INF;
}

void dijkstra(int n, vector <node> G[NMAX], int start, int dist[], bool used[]) {
    for(int i = 1; i<=n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    vector<node> ::iterator it;
    for(int i = 1; i< n; i++) {
        int nod = min_dist(n, dist, used);
        used[nod] = true;
        for(it = G[nod].begin(); it != G[nod].end(); it++) {
            if(!used[it->y] && dist[nod] + it->cost < dist[it->y] && !check_values(dist[nod])) {
                dist[it->y] = dist[nod] + it->cost;
            }
        }
    }
}


int main() {
    read_data(n, m);
    dijkstra(n, G, 1, dist, used);
    print_res(n, dist);

    return 0;
}
