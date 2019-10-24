#include <fstream>
#include <climits>
#define NMAX 55
#define WMAX 501
#define MIN(A, B) (A <= B ? A : B)
using namespace std;


/*
 * FILES
 */
ifstream in("calatorie.in");
ofstream out("calatorie.out");

struct Planet{
    int slow, fast;
}planet[NMAX];
int n;


/*
 * Reading data
 */
void read_data(){
    in >> n;
    for(int i = 1; i<n; i++){
        in >> planet[i].slow >> planet[i].fast;
    }
}

/*
 * Solve
 */
void dynamic(){
    uint64_t dp[NMAX][WMAX] = {0};
    for(int i = 1; i<n; i++){
        for(int CW = 0; CW < WMAX; CW++){
            dp[i][CW] = dp[i - 1][CW] + planet[i].slow;
            if(planet[i].fast <= CW){
                dp[i][CW] = MIN(dp[i][CW], dp[i - 1][CW - planet[i].fast]);
            }
        }
    }
    uint64_t result = UINT64_MAX;
    for(int i = 0; i<500; i++){
        result = MIN(result, 1ull*dp[n- 1][i] + 1ull*i * i * i * i);
    }
    out<<"Consumul minim = "<<result<<".\n";
}

int main(){
    int T;
    in >> T;
    while(T){
        read_data();
        dynamic();
        T --;
    }
    return 0;
}
