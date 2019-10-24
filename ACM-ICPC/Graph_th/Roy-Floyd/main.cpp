/*
 * Supr*
 * Roy-Floyd algorithm O(V^3)
 */
#include <fstream>
#include <climits>
#define NMAX 105 //maximum number of vertices in our graph
#define oo 1e9 //10^9
using std::ifstream;
using std::ofstream;

/*
 * File declaration
 */
ifstream in("royfloyd.in");
ofstream out("royfloyd.out");

/*
 * Variables
 */
int v, graph[NMAX][NMAX];
int rf[NMAX][NMAX]; //solution matrix

/*
 * Function for reading data
 */
void read_data(){
    in >> v;
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            in >> graph[i][j]; //graph[i][j] > 0 if there is an edge between i and j, 0 otherwise
            if(graph[i][j] == 0 && i != j){
                graph[i][j] = oo; //if there is no edge between i and j, the initial distance between them is infinity
            }
        }
    }
}

/*
 * Function to find the minimum distance between all pairs of nodes
 */
void solve_rf(){

    for(int k = 0; k<v; k++){
        for(int i = 0; i<v; i++){
            for(int j = 0; j<v; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

/*
 * Function to print the distance matrix
 */
void print_result(){
    for(int i = 0; i<v; i++){
        for(int j = 0; j<v; j++){
            graph[i][j] == oo ? out << 0 << ' ' : out << graph[i][j] << ' ';
        }
        out << '\n';
    }
}

int main(){
    read_data();
    solve_rf();
    print_result();
    return 0;
}
