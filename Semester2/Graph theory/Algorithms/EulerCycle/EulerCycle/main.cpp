/*
 * Suor* Euler Cycle
 */
#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
#define pb push_back
#define NMAX 100005
#define MMAX 500005
using namespace std;


/* FILE DECLARATION */
/* ---------------- */

ifstream f("input.txt");
ofstream g("output.txt");

/* ---------------- */

/* DATA DECLARATION */
/* ---------------- */

int n, m;
vector<int>G[NMAX]; //our graph
vector<int> cycle;
stack<int> st;

/* ---------------- */

/*
 * Function which reads the data from the file
 * :param n: -number of vertices
 * :param m: -number of edges
 * :param G: -our graph
 */
void read_data(int &n, int &m, vector<int>G[]){
    f >> n >> m;
    for(int i = 1; i<=m; i++){
        int x, y;
        f >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }
}


/*
 * Function which for a given graph checks if it has an Eulerian cycle
 * :param G: -graph to be checked
 * :post: if the graph is eulerian it will return 1, if it has an eulerian path it will return the starting node
 * else will return -1
 */
int check_euler(vector<int>G[]){
    int start_node = 1, num_odd = 0;
    for(int i = 1; i<=n; i++){
        if(G[i].size() % 2 == 1){
            start_node = i;
            num_odd ++;
        }
    }
    if(num_odd > 0 && num_odd != 2){
        return -1;
    }
    return start_node;
}

/*
 * Function which for an EULERIAN graph returns it's eulerian cycle or eulerian path
 */
vector<int> make_cycle(vector<int>G[]){
    vector<int>result;
    int start_node = check_euler(G);
    st.push(start_node);
    while(!st.empty()){
        int node = st.top();

        if(!G[node].empty()){           //if the node has any neighbours left we continue with the next one
            int new_node = G[node].back();
            G[node].pop_back();
            G[new_node].erase(find(G[new_node].begin(), G[new_node].end(), node));
            st.push(new_node);
        }
        else{                       //else we add it to our solution
            result.pb(node);
            st.pop();               //we don't need it anymore so we pop the node
        }
    }
    return result;
}


/*
 * Solving function
 */
void solve(vector<int>G[]){
    if(check_euler(G) != -1){
        auto cycle = make_cycle(G);
        for(const auto& elem : cycle){
            g << elem << ' ';
        }
    }
    else{
        g << "The graph doesn't have any eulerian cycle/path";
    }
}

/* MAIN FUNCTION */

int main(){
    read_data(n, m, G);
    solve(G);
    return 0;
}
