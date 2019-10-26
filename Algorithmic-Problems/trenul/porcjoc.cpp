#include <cstdio>
#define NMAX 100005
using namespace std;

FILE *f = freopen("porcjoc.in", "r", stdin);
FILE *g = freopen("porcjoc.out", "w", stdout);

struct bilet{
    int x, y;
};
bilet bilete[NMAX];
int N;
void read()
{
    scanf("%d", &N);
    for(int i = 1; i<=N; i++)
    {
        int val, dim;
        scanf("%d%d", &val, &dim);
        bilete[i] = bilet{val, dim};
    }
    ///printf("%d %d", bilete[N].x, bilete[N].y);
}
void solve()
{

}
int main()
{
    read();
    return 0;
}
