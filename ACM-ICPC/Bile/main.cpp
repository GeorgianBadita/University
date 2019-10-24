#include <fstream>
using namespace std;
#define NMAX 255

ifstream f("bile.in");
ofstream g("bile.out");

int graph[NMAX][NMAX]; //our graph structure
struct Point{
    int line, col;
}points[NMAX];
int n;
int maximum[NMAX*NMAX];
int father[NMAX*NMAX];

void read_data(){
    f >> n;
    for(int i = 1; i<=n; i++){
        f >> points[i].line >> points[i].col;
    }
}

int main(){
    return 0;
}
