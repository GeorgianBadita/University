/*
 * Supr* Flow
 */
#include <fstream>
#include <vector>
#include <climits>
#include <memory>
#include <cstring>
#include <queue>
#define NMAX 1005
#define INF INT_MAX
using namespace std;


ifstream f("maxflow.in");
ofstream g("maxflow.out");

vector<int> G[NMAX];
int r_graph[NMAX][NMAX];
int parent[NMAX];
bool visited[NMAX];
int n, m;

void read_data(){
    f >> n >> m;
    for(int i = 1; i<=m; i++){
        int x, y, c;
        f >> x >> y >> c;
        G[x].push_back(y);
        G[y].push_back(x);
        r_graph[x][y] += c;
    }
}

bool BFS(int s, int t){

    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node == t){
            continue;
        }

        for(const auto& adj : G[node]){
            if(!visited[adj] && r_graph[node][adj] > 0){
                visited[adj] = true;
                q.push(adj);
                parent[adj] = node;
            }
        }
    }

    return visited[t];
}

int get_max_flow(int s, int t){
    int max_flow = 0, min_cap;
    while(BFS(s, t)){
        //cout << BFS(s, t) << ' ';
        for(const auto& node : G[t]){
            if(!visited[node] || r_graph[node][t] <= 0){
                continue;
            }
            parent[t] = node;
            min_cap = INF;
            for(int adj = t; adj != s; adj = parent[adj]){
                min_cap = min(min_cap, r_graph[parent[adj]][adj]);
            }

            for(int adj = t; adj != s; adj = parent[adj]){
                r_graph[adj][parent[adj]] += min_cap;
                r_graph[parent[adj]][adj] -= min_cap;
            }

            max_flow += min_cap;
        }
    }
    return max_flow;
}

int main(){
    read_data();
    g << get_max_flow(1, n);
    return 0;
}
