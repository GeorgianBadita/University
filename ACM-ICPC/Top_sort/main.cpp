#include <fstream>
#include <vector>
#include <queue>
#define NMAX 50005
#define pb push_back
using namespace std;


ifstream f("sortaret.in");
ofstream g("sortaret.out");

int n, m;
vector<int> G[NMAX];
queue<int> q;
vector<int> sol;
int deg[NMAX];

void read_data(){
    f >> n >> m;
    for(int i = 0; i<m; i++){
        int x, y;
        f >> x >> y;
        G[x].pb(y);
        deg[y] ++;
    }
}

void top_sort(){
    for(int i = 1; i<=n; i++){
        if(deg[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(const auto& adj : G[node]){
            if(--deg[adj] == 0){
                q.push(adj);
            }
        }
        sol.pb(node);
    }
    for(const auto& elem : sol){
        g << elem << ' ';
    }
}

int main(){
    read_data();
    top_sort();
    return 0;
}
