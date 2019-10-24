/*
 * Supr*
 * Depth First Search implementation + number of conex components (Undirected Graph)
 * O(V+E)
 * V - Number of vertices
 * E - Number of edges
*/

#include <cstdio>
#include <vector>
#define NMAX 100005
#define pb push_back
#define True true
#define False false
using namespace std;

/* FILES */
FILE *f = freopen("dfs.in", "r", stdin);
FILE *g = freopen("dfs.out", "w", stdout);

/* Data Declaration */
vector <int> G[NMAX];
int n = 0, m = 0;
bool in_queue[NMAX];

/* Read input */

void read_data(int &n, int &m, vector <int> G[NMAX]){
    scanf("%d%d", &n, &m);
    for(int i = 1; i<=m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].pb(y);
        G[y].pb(x);
    }
}

/* DFS */
void dfs(int start, bool in_queue[], vector <int> G[NMAX]){
    //printf("%d ", start);
    in_queue[start] = True;
    for(unsigned i = 0; i<G[start].size(); i++){
        int node = G[start][i];
        if(!in_queue[node]){
            dfs(node, in_queue, G);
        }
    }
}

/* Number of conex components */
int num_conex(int n, bool in_queue[], vector <int> G[NMAX]){
    int num = 0;
    for(int i = 1; i<=n; i++) {
        if(!in_queue[i]){
            num += 1;
            dfs(i, in_queue, G);
        }
    }
    return num;
}

/* main function */
int main() {
    read_data(n, m, G);
    printf("%d", num_conex(n, in_queue, G));
    return 0;
}
