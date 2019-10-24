#include <fstream>
#define MIN(A, B) (A <= B ? A : B)
#define NMAX 100000
#define INF 1e9
using namespace std;

ifstream f("rmq.in");
ofstream g("rmq.out");

int arb[4*NMAX + 1];
int pos, val, minim, start, finish, n, m;

void update_tree(int node, int left, int right){
    if(left == right){
        arb[node] = val;
        return;
    }
    int mid = (left + right) / 2;
    if(pos <= mid) {
        update_tree(2*node, left, mid);
    }
    else{
        update_tree(2*node + 1, mid + 1, right);
    }
    arb[node] = MIN(arb[2*node], arb[2*node + 1]);
}

void querry_tree(int node, int left, int right){
    if(start <= left && right <= finish){
        if(minim > arb[node]){
            minim = arb[node];
        }
        return;
    }

    int mid = (left + right) / 2;
    if(start <= mid){
        querry_tree(2*node, left, mid);
    }
    if(finish > mid){
        querry_tree(2*node + 1, mid + 1, right);
    }
}

int main(){
    f >> n >> m;
    for(int i = 1; i<=n; i++){
        int x;
        f >> x;
        pos = i; val = x;
        update_tree(1, 1, n);
    }
    while(m){
        int x, y;
        f >> x >> y;
        minim = 1e9;
        start = x; finish = y;
        querry_tree(1, 1, n);
        g << minim << '\n';
        m --;
    }
    return 0;
}
