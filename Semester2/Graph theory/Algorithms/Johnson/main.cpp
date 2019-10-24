/*
 * Supr*
 * Johnson's algorithm (calculates the distance between every two nodes of a graph: complexity O(|V|^2log|V| + |E|*|V|))
 */
#include <cstdio>
#include <vector>
#include <queue>
#define pb push_back
#define INF 1e9
#define NMAX 500
 
using namespace std;
 
/* FILE DECLARATION */
FILE *f = freopen("royfloyd.in", "r", stdin);
FILE *g = freopen("royfloyd.out", "w", stdout);
 
/* DATA STRUCTURES DECLARATION */
struct Node{
    int y, cost;
    Node(const int& y, const int& cost){            //Node struct constructor
        this->y = y;
        this->cost = cost;
    }
 
    bool operator <(const Node& other) const {
        return this->cost > other.cost;             //overloading the '>' operator for our priority queue
    }
};
 
vector<Node>G[NMAX];
priority_queue<Node>prior_q;    //priority queue for Dijkstra
queue<int>q;                    //normal queue for bellmanford
int h[NMAX];                    //the distance calculated with bellmanford aka new weights
int interm[NMAX];
int dist[NMAX][NMAX];           //the distance matrix calculated by Dijkstra after we reweight the graph
int n = 0;                      //number of nodes
bool negative = false;          //tells if our graph contains a negative cycle
 
/* READ DATA */                 //Our data set will be given as an adjacency matrix, but we want to use adacency lists
void read_data(int& n, vector<Node>G[]){
    int x;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            scanf("%d", &x);
            if(i != j && x != 0){
                G[i].pb(Node(j, x));
            }
        }
    }
}
 
 
/*
 * Function that applies bellmanford on a graph starting from a given node
 */
void bellman_ford(vector<Node>G[], int start, int dist[], int n, bool negative){
    int cnt_cycle[n + 1];
    for(int i = 0; i<=n; i++){
        dist[i] = INF;
        cnt_cycle[i] = 0;
    }
    dist[start] = 0;
    q.push(start);
    vector<Node>::iterator it;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(it = G[node].begin(); it != G[node].end(); it++){
            if(dist[node] + it -> cost < dist[it -> y]){
                dist[it -> y] = dist[node] + it -> cost;
                if(cnt_cycle[it -> y] > n){
                    negative = true;
                    return;
                }
                else{
                    q.push(it -> y);
                    cnt_cycle[it->y] ++;
                }
            }
        }
    }
 
}
 
/*
 * Function that assures that a priority queue is empty
 */
void empty_q(priority_queue<Node>q){
    while(!q.empty()){
        q.pop();
    }
}
 
 
/*
 * Function that applies Dijkstra's algorithm on  graph, starting from a given node
 */
void dijkstra(vector<Node>G[], int start, int dist[][NMAX], priority_queue<Node>q){
    empty_q(q);
    for(int i = 1; i<=n; i++){
        dist[start][i] = INF;
    }
    dist[start][start] = 0;
    q.push(Node(start, dist[start][start]));
    vector<Node>::iterator it;
    while(!q.empty()){
        Node fr = q.top();
        int node = fr.y;
        int cost = fr.cost;
        q.pop();
        if(dist[start][node] != cost){
            continue;
        }
        for(it = G[node].begin(); it != G[node].end(); it++){
            if(dist[start][node] + it -> cost < dist[start][it -> y]){
                dist[start][it -> y] = dist[start][node] + it -> cost;
                q.push(Node(it->y, dist[start][it->y]));
            }
        }
    }
}
 
/*
 * Function that adds a new node to the graph, with weight 0 to every other node
 */
void add_node_reweight(vector<Node>G[], int n){
    for(int i = 1; i<=n; i++){
        G[0].pb(Node(i, 0));
    }
}
 
 
/*
 * Function that applies Johnson's algorithm on our graph
 */
void johnsons_alg(vector<Node>G[], int n, priority_queue<Node>q, int dist[], bool negative, int dist_matrix[][NMAX]){
    add_node_reweight(G, n);
    bellman_ford(G, 0, dist, n, negative);
    if(negative == true){
        printf("Graful are un circuit negativ!\n");
        return;
    }
    ///WE HAVE THE VECTOR OF DISTANCES BY BELLMAN FORD
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<G[i].size(); j++){
            Node node = G[i][j];
            node.cost = node.cost + h[i] - h[node.y];
            G[i][j] = node;
        }
    }
    for(int i = 1; i<=n; i++){
        dijkstra(G, i, dist_matrix, q);
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(dist_matrix[i][j] != INF){
                dist_matrix[i][j] = dist_matrix[i][j] + h[j] - h[i];
                printf("%d ", dist_matrix[i][j]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}
 
 
int main(){
    read_data(n, G);
    johnsons_alg(G, n, prior_q, h, negative, dist);
    return 0;
}
