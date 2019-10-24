/*
 * Supr*
 * Dijkstra's Algorithm O(E*logV) - priority queue
 */
#include <fstream>
#include <vector>
#include <queue>
#define VMAX 50005 //maximum number of vertices
#define oo 1e9 //10^9
#define pb push_back
using std::ifstream;
using std::ofstream;
using std::vector;
using std::priority_queue;

/*
 * File declaration
 */
ifstream in("dijkstra.in");
ofstream out("dijkstra.out");

/*
 * Variables and data structures
 */
struct Node{
    int adj, cost;
    Node(int adj, int cost): adj{adj}, cost{cost} {} //creating constructor for node

    bool operator<(const Node& ot) const{ //overloading < operator for our priority queue
        return this->cost > ot.cost;
    }
};
vector<Node> G[VMAX]; //our graph
priority_queue<Node> pq;
vector<int> distance(VMAX); //distance vector
int v, e;

/*
 * Function to read data
 */
void read_data(){
    in >> v >> e;
    for(int i = 1; i<=e; i++){
        int from, to, cost;
        in >> from >> to >> cost;
        G[from].push_back({to, cost});
    }
}

/*
 * Function for Dijkstra's algorithm
 */
void dijkstra(int start){
    for(int i = 1; i<=v; i++){
        distance[i] = oo;
    }
    distance[start] = 0;
    pq.push({start, distance[start]});

    while(!pq.empty()){
        Node top = pq.top();
        pq.pop();
        int node = top.adj;
        int dist = top.cost;
        if(distance[node] != dist){
            continue;
        }
        for(const auto& adj : G[node]){
            if(distance[adj.adj] > distance[node] + adj.cost){
                distance[adj.adj] = distance[node] + adj.cost;
                pq.push({adj.adj, distance[adj.adj]});
            }
        }
    }
}

/*
 * Function to print the result
 */
void print_result(){
    dijkstra(1);
    for(int i = 2; i<=v; i++){
        distance[i] == oo ? out << 0 << ' ' : out << distance[i] << ' ';
    }
}

int main(){
    read_data();
    print_result();
    return 0;
}
