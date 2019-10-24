#include <fstream>
#define NMAX 100005
#define MMAX 20
#define MIN(A,B) (A <= B ? A : B)
using namespace std;

int pre_calc[NMAX][MMAX];
int elems[NMAX];
int lg[NMAX], n, m;

ifstream in("rmq.in");
ofstream out("rmq.out");

void calculate_log(){
    lg[1] = 0;
    for(int i = 2; i<=n; i++){
        lg[i] = lg[i/2] + 1;
    }
}

void pre_calc_func(){
    for(int i = 0; i<n; i++){
        pre_calc[i][0] = elems[i];
    }
    for(int j = 1; j<=lg[n]; j++){
        for(int i = 0; i<n - (1 << j) + 1; i++){
            pre_calc[i][j] = MIN(pre_calc[i][j - 1], pre_calc[i + (1 << (j-1))][j - 1]);
        }
    }

}

void solve(){
    in >> n >> m;
    for(int i = 0; i<n; i++){
        in >> elems[i];
    }
    calculate_log();
    pre_calc_func();

    for(int i = 0; i<m; i++){
        int x, y, k;
        in >> x >> y;
        x --;
        y --;
        k = lg[y - x + 1];

        int first_half = pre_calc[y - (1 <<k) + 1][k];
        int second_half = pre_calc[x][k];

        out << MIN(first_half, second_half) << '\n';
    }

}

int main(){
    solve();
    return 0;
}
