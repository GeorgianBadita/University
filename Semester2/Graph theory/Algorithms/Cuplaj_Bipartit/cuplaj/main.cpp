/*
 * Supr* Bipartite Matching
 */
#include <fstream>
#include <cstring>
#include <vector>
#define NMAX 10005
#define pb push_back
using namespace std;

ifstream f("cuplaj.in");
ofstream g("cuplaj.out");

vector<int> G[NMAX];
int left_m[NMAX], right_m[NMAX];
bool viz[NMAX];
int n, m, edg;


/*
 * Function to find a match for a node
 */
bool find_match(int node){
    if(viz[node]){
        return false;
    }
    viz[node] = true;
    for(const auto& adj: G[node]){
        if(!right_m[adj]){
            left_m[node] = adj;
            right_m[adj] = node;
            return true;
        }
    }

    for(const auto& adj: G[node]){
        if(find_match(right_m[adj])){
            left_m[node] = adj;
            right_m[adj] = node;
            return true;
        }
    }
    return false;

}

/*
 * Function to read data
 */
void read_data(int &n, int&m, int &edg){
    f >> n >> m >> edg;
    for(int i = 1; i<=edg; i++){
        int x, y;
        f >> x >> y;
        G[x].pb(y);
    }
}


/*
 * Solve function
 */
void solve(){
    int changed = 1;
    while(changed){
        memset(viz, false, sizeof(viz));
        changed = 0;
        for(int i = 1; i<=n; i++){
            if(!left_m[i]){
                changed |= find_match(i);
            }
        }
    }

    int nodes_in_match = 0;
    for(int i = 1; i<=n; i++){
        if(left_m[i] > 0){
            nodes_in_match ++;
        }
    }
    g << nodes_in_match << '\n';
    for(int i = 1; i<=n; i++){
        if(left_m[i] > 0){
            g << i << ' ' << left_m[i] << '\n';
        }
    }
}


int main(){
    read_data(n, m, edg);
    solve();
    return 0;
}
