/*
 * Catun - Supr*
 * O(n*m)
 */
#include<fstream>
#include <vector>
#include <queue>
#define NMAX 36005
#define MMAX 2*NMAX
#define pb push_back
#define INF 1e9
using namespace std;

/*
 * FILES
 */
ifstream in("catun.in");
ofstream out("catun.out");

/*
 * DATA STRUCTURES AND VARIABLES
 */
struct Node{
    int y;
    int cost;
    Node(int y, int cost):y{y}, cost{cost} {}

};

int n, m, k;
vector<int> dist(NMAX, INF);
vector<Node>G[NMAX]; //our graph
queue<int> q;
int hold[NMAX];
bool is_hold[NMAX];

/*
 * Read data
 */
void read_data(){
    in >> n >> m >> k;
    for(int i = 0; i<k; i++){
        int x;
        in >> x;
        hold[x] = x;
        dist[x] = 0;
        q.push(x);
        is_hold[x] = true;
    }
    for(int i = 0; i<m; i++){
        int x, y, c;
        in >> x >> y >> c;
        G[x].pb({y, c});
        G[y].pb({x, c});
    }
}

/*
 * Bellman Ford
 */
void bellman_ford(){

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(const auto& elem : G[node]){
            int curr = elem.y;
            int cost = elem.cost;
            if(dist[curr] > dist[node] + elem.cost || (dist[curr] == dist[node] + elem.cost && hold[curr] > hold[node])){
                dist[curr] = dist[node] + elem.cost;
                hold[curr] = hold[node];
                q.push(curr);
            }
        }
    }
    for(int i = 1; i<=n; i++){
        is_hold[i] == true ? out << 0 << ' ' : out << hold[i] << ' ';
    }
}

int main(){
    read_data();
    bellman_ford();
    return 0;
}
