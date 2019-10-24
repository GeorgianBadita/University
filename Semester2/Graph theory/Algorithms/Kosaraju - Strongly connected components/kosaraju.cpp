/*
	Kosaraju's algorithm for finding strongly connected components
	Complexity:  Θ(V+E)
	V - number of vertices
	E - number of edges
*/

#include <fstream>
#include <stack>
#include <vector>
#define NMAX 100005
#define pb push_back
using namespace std;
 
 
ifstream f("ctc.in");
ofstream g("ctc.out");
 
vector<int>G[NMAX];		//our graph
vector<int>G_minus[NMAX];	//inverse graph
vector<int>comp[NMAX];		//vector for connected components
bool viz[NMAX], in_comp[NMAX];	
stack<int> st;
int nr_cmp = 0;
int n, m;
 
void read_data(){
    f >> n >> m;
    for(int i = 1; i<=m; i++){
        int x, y;
        f >> x >> y;
        G[x].pb(y);
        G_minus[y].pb(x);
    }
}
 
void dfs(int src){	//first dfs
    viz[src] = true;
    for(int i = 0; i < G[src].size(); i++){
        if(!viz[G[src][i]]){
            dfs(G[src][i]);
        }
    }
    st.push(src);
}
 
void dfs_minus(int src){	//second dfs
    in_comp[src] = true;
    for(int i = 0; i<G_minus[src].size(); i++){
        if(!in_comp[G_minus[src][i]]){
            dfs_minus(G_minus[src][i]);
        }
    }
    comp[nr_cmp].pb(src);
}
 
void solve(){
    for(int i = 1; i<=n; i++){
        if(!viz[i]){
            dfs(i);
        }
    }
    while(!st.empty()){
        int node = st.top();
 
        if(!in_comp[node]){
            ++nr_cmp;
            dfs_minus(node);
        }
        st.pop();
    }
    g << nr_cmp << '\n';
    for(int i = 1; i<=nr_cmp; i++){
        for(int j = 0; j<comp[i].size(); j++){
            g << comp[i][j] << ' ';
        }
        g << '\n';
    }
}
 
int main(){
    read_data();
    solve();
    return 0;
}
