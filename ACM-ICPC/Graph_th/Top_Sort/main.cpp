/*
 * Supr*
 * Topological sort O(V+E)
 */
#include <fstream>
#include <queue>
#define VMAX 50005 //maximum number of vertices
#define pb push_back
using std::ifstream;
using std::ofstream;
using std::queue;
using std::vector;

/*
 * File declaration
 */
ifstream in("sortaret.in");
ofstream out("sortaret.out");

/*
 * Variables
 */
queue<int> q;
int deg[VMAX]; //array to store the inner degree of a vertex
vector<int> G[VMAX]; //vector to store our graph
vector<int> top_sort; //vector which contains the vertices sorted in ropological order
int v,e;

/*
 * Function to read data
 */
void read_data(){
    in >> v >> e;
    for(int i = 0; i<e; i++){
        int x, y;
        in >> x >> y;
        G[x].pb(y);
        deg[y] ++;
    }
}

/*
 * Function for topological sort
 */
void t_sort(){
    for(int i = 1; i<=v; i++){
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
        top_sort.pb(node);
    }
}

/*
 * Function to print the result
 */
void print_result(){
    for(const auto& elem : top_sort){
        out << elem << ' ';
    }
    out << '\n';
}

int main(){
    read_data();
    t_sort();
    print_result();
   return 0;
}
