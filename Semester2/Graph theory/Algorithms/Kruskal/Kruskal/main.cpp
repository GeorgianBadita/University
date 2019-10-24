/*
 * Supr*
 * Kruskal's algorithm for minimum spanning tree
 * Complexity O(|E|*log|V| + |V|*log|E|)
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#define NMAX 200005
#define pb push_back
using namespace std;

/* FILE DECLARATION */
/* ---------------- */

FILE *f = freopen("apm.in", "r", stdin);
FILE *g = freopen("apm.out", "w", stdout);
/* ---------------- */


/* DATA DECLARATION */
/* ---------------- */
vector<int> answer;
int x[NMAX], y[NMAX], father[NMAX], cost[NMAX], ind[NMAX];
int n, m;
int cost_sol = 0;
/* ---------------- */

/* Disjoint set functions */

/*
 * Function that returns the root of the set containing x
 * :param x: integer - node
 */
int find_(int x){
    if(father[x] == x) return x;
    father[x] = find_(father[x]);
    return father[x];
}

/*
 * Function which makes the union between the set containing x and the set containing y
 * :param x: integer - node
 * :param y: integer - node
 */
void unite(int x, int y){
    father[find_(y)] = find_(x);
}
/* ---------------- */


/*
 * Function which reads the input
 * :param n: integer -number of vertices
 * :param m: integer -number of edges
 * :param x: array containing one extremity of the edge i
 * :param y: array containing the other extremity of the edge i
 * :param cost: array containing the weight of the edge i
 */
void read_data(int& n, int& m, int x[], int y[], int cost[], int ind[]){
        scanf("%d%d", &n, &m);
        for(int i = 1; i<=m; i++){
            scanf("%d%d%d", &x[i], &y[i], &cost[i]);
            ind[i] = i;
        }
}

/*
 * Function which finds the minimum spanning tree of  a graph using Kruska's algorithm
 * :param cost_sol: integer containing the tree sum
 * :param answer: vector where we'll store the edges of the tree
 */
void solve(int& cost_sol, vector<int>& answer){
    sort(ind + 1, ind + m + 1, [&](int i, int j){
        return cost[i] < cost[j];
    });

    for(int i = 1; i<=n; i++){
        father[i] = i;
    }
    for(int i = 1; i<=m; i++){
        if(find_(x[ind[i]]) != find_(y[ind[i]])){
            cost_sol += cost[ind[i]];
            answer.pb(ind[i]);
            unite(x[ind[i]], y[ind[i]]);
        }
    }
}

/*
 * Function which prints the output to the file
 * :param cost_sol: integer the cost of the spanning tree
 * :param answer: vector containing the edges of the spanning tree
 */
void write(int cost_sol, vector<int> answer){
      printf("%d\n", cost_sol);
      printf("%lu\n", answer.size());
      for(unsigned i = 0; i<answer.size(); i++){
          printf("%d %d\n", x[answer[i]], y[answer[i]]);
      }
}
/* ---------------- */

/*
 * main function
 */
int main(){
    read_data(n, m, x, y, cost, ind);
    solve(cost_sol, answer);
    write(cost_sol, answer);
    return 0;
}
