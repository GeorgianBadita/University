/*
 * Badita Marin-Georgian 211/1
 * Supr*
 * Ford Fulkerson's algorithm O(|E|*MF), where MF = MaxFlow
 */

#include <fstream>
#include <climits>
#include <cstring>
#include <queue>
#define NMAX 1024
using namespace std;

ifstream f("maxflow.in");
ofstream g("maxflow.out");

int graph[NMAX][NMAX];
int parent[NMAX], n, m;

void read_data(){
    f >> n >> m;
    for(int i = 1; i<=m; i++){
        int x, y, c;
        f >> x >> y >> c;
        graph[x][y] = c;
    }
}


bool bfs(int r_graph[NMAX][NMAX], int s, int t, int parent[]){
    bool visited[NMAX];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i = 1; i<=n; i++){
            if(!visited[i] && r_graph[node][i] > 0){
                q.push(i);
                parent[i] = node;
                visited[i] = true;
            }
        }
    }
    return (visited[t] == true);
}

int ford_fulkerson(int graph[NMAX][NMAX], int s, int t){

    int r_graph[NMAX][NMAX];

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            r_graph[i][j] = graph[i][j];
        }
    }

    int parent[NMAX];
    int max_flow = 0;
    while(bfs(r_graph, s, t, parent)){
        int path_flow = INT_MAX;
        for(int i = t; i != s; i = parent[i]){
            int u = parent[i];
            path_flow = min(path_flow, r_graph[u][i]);
        }

        for(int i = t; i != s; i = parent[i]){
            int u = parent[i];
            r_graph[u][i] -= path_flow;
            r_graph[i][u] += path_flow;
        }

        max_flow += path_flow;
    }
    return max_flow;
}



int main(){
    read_data();
    g << ford_fulkerson(graph, 1, n);
    return 0;
}
