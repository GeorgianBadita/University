#include <fstream>
#include <vector>
#include <algorithm>
#define MOD 50003
using namespace std;

/*
 * FILES
 */
ifstream f("oite.in");
ofstream g("oite.out");

vector<int> H[MOD + 1];
vector<int> elems;
int n, l;


/*
 * Function to insert in hash
 */
void insert_hash(int x){
    int poz = x % MOD;
    H[poz].push_back(x);
}


/*
 * Function to search in hash
 */
int search_hash(int x){
    int solutions = 0;
    if(x < 0){
        return solutions;
    }
    int poz = x % MOD;
    for(const auto& elem : H[poz]){
        if(elem == x){
            solutions ++;
        }
    }
    return solutions;
}

/*
 * Reading data
 */
void read_data(){
    f >> n >> l;
    for(int i = 0; i< n; i++){
        int x;
        f >> x;
        elems.push_back(x);
    }
}

void solve(){
    int nr_sol = 0;
    sort(elems.begin(), elems.end());
    for(int i = 0; i<n; i++){
        for(int j = i + 1; j<n; j++){
            nr_sol += search_hash(l - elems[i] - elems[j]);
        }
        for(int j = 0; j<i; j++){
            insert_hash(elems[i] + elems[j]);
        }
    }
    g << nr_sol;
}
int main(){
    read_data();
    solve();
}
