#include <fstream>
#define NMAX 15001
using namespace std;

ifstream f("datorii.in");
ofstream g("datorii.out");

int arb[4*NMAX + 1];
int start, finish, sum, val, pos, n, m;

void update_tree(int node, int left, int right){
    arb[node] += val;
    if(left == right){
        return;
    }
    int mid = (left + right) / 2;
    if(pos <= mid){
        update_tree(2*node, left, mid);
    }
    else{
        update_tree(2*node + 1, mid + 1, right);
    }
}

void querry_tree(int node, int left, int right){
    if(start <= left && right <= finish){
        sum += arb[node];
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
    for(int i =1; i<=n; i++){
        int x;
        f >> x;
        pos = i; val = x;
        update_tree(1, 1, n);
    }
    while(m){
        int tip, a, b;
        f >> tip >> a >> b;
        if(tip == 0){
            pos = a;
            val = -b;
            update_tree(1, 1, n);
        }
        else{
            sum = 0;
            start = a; finish = b;
            querry_tree(1, 1, n);
            g << sum << '\n';
        }
        m --;
    }
    return 0;
}
