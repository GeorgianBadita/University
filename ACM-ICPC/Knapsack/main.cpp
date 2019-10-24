#include <fstream>
#define NMAX 5005
#define WMAX 10001
#define MAX(A, B) (A >= B ? A : B)
using namespace std;

/*
 * FILES
 */
ifstream f("rucsac.in");
ofstream g("rucsac.out");

/*
 * DATA STRUCTURES AND VARS
 */
struct Obj{
    int weight, value;
    Obj(){weight = value = 0;}
    Obj(int w, int v): weight{w}, value{v} {}
};

int n, w;
Obj objects[NMAX];
int dp[2][WMAX];

/*
 * Reading data
 */
void read_data(){
    f >> n >> w;
    for(int i = 1; i<=n; i++){
        int weight, value;
        f >> weight >> value;
        Obj obj{weight, value};
        objects[i] = obj;
    }
}

/*
 * DP function
 */
void dynamic(){
    for(int i = 1; i<=n; i++){
        for(int CW = 0; CW <= w; CW ++){
            dp[i % 2][CW] = dp[(i - 1) % 2][CW];
            if(objects[i].weight <= CW){
                dp[i % 2][CW] = MAX(dp[i % 2][CW], dp[(i - 1) % 2][CW - objects[i].weight] + objects[i].value);
            }
        }
    }
    g << dp[n % 2][w];
}

int main(){
    read_data();
    dynamic();
    return 0;
}
