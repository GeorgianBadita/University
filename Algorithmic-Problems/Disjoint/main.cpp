#include <cstdio>
#define NMAX 100005
using namespace std;

FILE *f = freopen("disjoint.in", "r", stdin);
FILE *g = freopen("disjoint.out", "w", stdout);

int N, M;
int Father[NMAX];

int find_(int x)
{
    while(Father[x])
        x = Father[x];
    return x;
}

int main()
{
    scanf("%d%d", &N, &M);
    int op, x, y;
    while(M)
    {
        M--;
        scanf("%d%d%d", &op, &x, &y);
        if(op == 2) {
            if(find_(x) == find_(y)) printf("DA\n");
            else printf("NU\n");
        }
        else {
            Father[find_(y)] = find_(x);
        }
    }
    return 0;
}
