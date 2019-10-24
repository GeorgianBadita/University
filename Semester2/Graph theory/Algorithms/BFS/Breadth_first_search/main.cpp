/*
 * Supr*
 * Breadth first search + shortest distance from a source vertex to all other vertex (Directed graph)
 * O(V +E)
 * V - number of vertices
 * E - number of edges
 */
#include <cstdio>
#include <vector>
#include <deque>
#define pb push_back
#define NMAX 100005
#define INF 1e9
#define True true
#define False false
using namespace std;

/* FILES */
FILE *f = freopen("bfs.in", "r", stdin);
FILE *g = freopen("bfs.out", "w", stdout);

/* Data declaration */
int dist[NMAX]; //our distance vector
int prec[NMAX]; //to construct our path
vector <int> G[NMAX];
bool in_queue[NMAX];
int n = 0, m = 0, source = 0;
deque <int> Q;

/* Read data */
void read_data(int &n, int &m, int &source, vector<int> G[NMAX]){
    scanf("%d%d%d", &n, &m, &source);
    for(int i = 1; i<=m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].pb(y);
    }
}

/* BFS */
void bfs(int source, int n, bool in_queue[], int dist[], vector<int>G[NMAX]){
    for(int i = 1; i<=n; i++){
        dist[i] = INF;
    }
    dist[source] = 0;
    in_queue[source] = True;
    Q.pb(source);
    vector<int> ::iterator it;
    while(!Q.empty()){
        int node = Q.front();
        Q.pop_front();
        for(it = G[node].begin(); it != G[node].end(); it++){
            if(!in_queue[*it]){
                Q.push_back(*it);
                in_queue[*it] = True;
                dist[*it] = 1 + dist[node];
            }
        }
    }
    for(int i = 1; i<=n; i++){
        dist[i] >= INF ? printf("-1 ") : printf("%d ", dist[i]);
    }
}

/* Main function */

int main() {

    read_data(n, m, source, G);
    bfs(source, n, in_queue, dist, G);
    return 0;
}
