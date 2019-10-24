/*
 * Supr*
 * Disjoint set 2 types of querries:
 * 1 x y - unite sets of x and y
 * 2 x y - tell if x and y are in the same set
 */

#include <cstdio>
#define NMAX 100005
using namespace std;

/* FILE DECLARATION */
//------------------//
FILE* f = freopen("disjoint.in", "r", stdin);
FILE* g = freopen("disjoint.out", "w", stdout);
//------------------//


/* DATA DECLARATION */
//------------------//
int n, m;
int father[NMAX];
//------------------//

/*
 * Function that for a given node returns the root of its set
 * :param x: integer - node
 */
int find_(int x){
    while(father[x]){
        x = father[x];
    }
    return x;
}

/*
 * Function that unites the set containing x and y
 * :param x: integer - node
 * :param y: integer - node
 */
void unite(int x, int y){
    father[find_(y)] = find_(x);
}


/*
 * Solving function
 */
void solve(){
    int x, y, op;
    scanf("%d%d", &n, &m);

    while(m){
        m --;
        scanf("%d%d%d", &op, &x, &y);
        switch (op){
            case 2:{
                if(find_(x) == find_(y)){
                    printf("DA\n");
                }
                else{
                    printf("NU\n");
                }
                break;
            }
            case 1:{
                unite(x, y);
                break;
            }
        }
    }
}

int main(){
    solve();
    return 0;
}
