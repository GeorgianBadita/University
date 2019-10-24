/*
 * Supr*
 * Minimum Spanning Tree - Kruskal's  algorithm O(E*logE + V*logV)
 */
#include <fstream>
#include <vector>
#include <algorithm>
#define VMAX 200005
#define pb push_back
using std::ifstream;
using std::ofstream;
using std::vector;
using std::sort;

/*
 * File declaration
 */
ifstream in("apm.in");
ofstream out("apm.out");

/*
 * Variables
 */
int v,e;
vector<int> sol;
int x[VMAX], y[VMAX], cost[VMAX], father[VMAX], ind[VMAX];
int cost_sol; //total cost of our minimum spanning tree

/*
 * Function for reading data
 */
void read_data(){
    in >> v >> e;
    for(int i = 1; i<=e; i++){
        in >> x[i] >> y[i] >> cost[i]; //edge between x[i] and y[i] with cost cost[i]
        ind[i] = i;
    }
}

/*
 * Function to find the father of a given set
 */
int find_(int x){
    if(x == father[x]){
        return x;
    }
    father[x] = find_(father[x]);
    return father[x];
}

/*
 * Function to unite 2 sets
 */
void unite_(int x, int y){
    father[find_(x)] = find_(y);
}

/*
 * Function to compare cost of two "edges" by cost
 */
bool cmp(int x, int y){
    return cost[x] < cost[y];
}

/*
 * Function to initialize Kruskal's algorithm
 */
void init(){
    for(int i =1; i<=v; i++){
        father[i] = i;
    }
    sort(ind + 1, ind + e + 1, cmp);
}

/*
 * Function for Kruskal's algorithm
 */
void kruskal(){

    init();

    for(int i = 1; i<=e; i++){
        if(find_(x[ind[i]]) != find_(y[ind[i]])){
            sol.pb(ind[i]);
            cost_sol += cost[ind[i]];
            unite_(x[ind[i]], y[ind[i]]);
        }
        if(sol.size() == v - 1){
            return;
        }
    }
}

/*
 * Function to display the result
 */
void display_result(){
    out << cost_sol << '\n';
    out << v - 1 << '\n';
    for(const auto& elem : sol){
        out << x[elem] << ' ' << y[elem] << '\n';
    }
}

int main(){
    read_data();
    kruskal();
    display_result();
    return 0;
}
