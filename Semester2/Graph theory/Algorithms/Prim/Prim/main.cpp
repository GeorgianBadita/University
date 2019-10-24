/*
 * Supr*
 * Prim's algorithm for finding the minimum spanning tree
 * Time Complexity: O(|E|*log|V|
 */

#include <cstdio>
#include <vector>
#include <queue>
#define NMAX 200001
#define MMAX 400001
#define pb push_back
using namespace std;

/* FILE DECLARATION */
/* ---------------- */

FILE *f = freopen("apm.in", "r", stdin);
FILE *g = freopen("apm.out", "w", stdout);

/* ---------------- */

/* DATA DECLARATION */
/* ---------------- */

/*
 * Class to represent a node
 */
class Node{
public:
    int y, cost;

    Node(int y, int cost){
        this->y = y;
        this->cost = cost;
    }
};

/*
 * Class to represent an edge
 */
class Edge{
public:
    int a, b, cost;
    Edge(int a, int b, int cost){
        this->a = a;
        this->b = b;
        this->cost = cost;
    }

    bool operator<(const Edge& ot) const{
        return this->cost > ot.cost;
    }
};

vector<Node> G[NMAX]; //our graph
bool in_queue[NMAX];
int n, m;
priority_queue<Edge> candidate;
vector<Edge>answer;
int cost_sol = 0;

/* ---------------- */


/*
 * Function which reads the input
 * :param n: integer - number of vertices
 * :param m: integer - number of edges
 * :param G: vector of edges - our graph
 */
void read_data(int& n, int& m, vector<Node> G[NMAX]){
    scanf("%d%d", &n, &m);
    for(int i = 0; i<m; i++){
        int x, y, cost;
        scanf("%d %d %d", &x, &y, &cost);
        G[y].pb(Node(x, cost));
        G[x].pb(Node(y, cost));
    }
}

/*
 * Function which initializes the start node of the spanning tree
 * :param start: integer - the start node
 */
void init(int start){
    in_queue[start] = true; //visited
    for(unsigned i = 0; i<G[start].size(); i++){
        candidate.push(Edge(start, G[start][i].y, G[start][i].cost));
    }
}

/*
 * Function which extracts the unvisited node
 * :param a: integer - node
 * :param b: integer - node
 */
int extract_visited(int a, int b){
    if(!in_queue[a]){
        return a;
    }
    else{
        return b;
    }
    return -1;
}

/*
 * Function which finds the minimum spanning tree using Prim's algorithm
 * :param cost_sol: integer - the tree sum
 * :param answer: vector of edges, the edges which form the minimum spanning tree
 */
void solve(int& cost_sol, vector<Edge>& answer){
    init(1);
    while(!candidate.empty()){
        Edge edg = candidate.top();
        candidate.pop();
        if(!(in_queue[edg.a] && in_queue[edg.b])){
            answer.pb(edg);
            cost_sol += edg.cost;
            int new_node;
            if(!in_queue[edg.a]){
                new_node = edg.a;
            }
            else {
                new_node = edg.b;
            }
            for(unsigned i = 0; i<G[new_node].size(); i++){
                candidate.push(Edge(new_node, G[new_node][i].y, G[new_node][i].cost));
            }
            in_queue[new_node] = true;
        }
    }
}

/*
 * Function which prints the result to the file
 * :param cost_sol: integer the total cost of the spanning tree
 * :param answer: the edges of the spanning tree
 */
void write(int cost_sol, const vector<Edge>& answer){
    printf("%d\n", cost_sol);
    printf("%lu\n", answer.size());
    for(unsigned i = 0; i<answer.size(); i++){
        printf("%d %d\n", answer[i].b, answer[i].a);
    }
}

/*
 * main function
 */
int main(){
    read_data(n, m, G);
    solve(cost_sol, answer);
    write(cost_sol, answer);
    return 0;
}
