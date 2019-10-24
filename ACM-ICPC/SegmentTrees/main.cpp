#include <fstream>
#define NMAX 100005
#define MAX(A, B) (A >= B ? A : B)
#define INF 1e9
using namespace std;

/*
 * FILES
 */
ifstream in("arbint.in");
ofstream out("arbint.out");

int arb[4*NMAX + 1];
int n, m, maxim;

void update_tree(int node, int left, int right, int pos, int val){
    if(left == right){
        arb[node] = val;
        return;
    }
    int mid = (left + right) /  2;
    if(pos <= mid) {
        update_tree(2*node, left, mid, pos, val);
    }
    else{
        update_tree(2*node + 1, mid + 1, right, pos, val);
    }
    arb[node] = MAX(arb[2*node], arb[2*node + 1]);
}

void querry_tree(int node, int left, int right, int start, int finish){
    if(start <= left && right <= finish){
        if(maxim < arb[node]){
            maxim = arb[node];
        }
        return;
    }
    int mid = (left + right) / 2;
    if(start <= mid){
         querry_tree(2*node, left, mid, start, finish);
    }
    if(finish > mid){
         querry_tree(2*node + 1, mid + 1, right, start, finish);
    }
}

int main(){
    in >> n >> m;
    for(int i = 1; i<=n; i++){
        int x;
        in >> x;
        update_tree(1, 1, n, i, x);
    }
    for(int i = 1; i<=m; i++){
        int type, a, b;
        in >> type >> a >> b;
        switch (type) {
        case 0:
            maxim = -1;
            querry_tree(1, 1, n, a, b);
            out << maxim << '\n';
            break;
        case 1:
            update_tree(1, 1, n, a, b);
            break;
        default:
            break;
        }
    }
}
