#include <cstdio>
#include <algorithm>
#include <cmath>
#define NMAX 2005
using namespace std;
FILE *f = freopen("cerc.in", "r", stdin);
FILE *g = freopen("cerc.out", "w", stdout);

struct cerc{
    double x;
    double y;
    int r;
}a[NMAX];
double pant[NMAX];
const double EPS = 0.000001;
double tg(double x, double y)
{
    return (double) x / y;
}

bool cmp(cerc A, cerc B)
{
    if(abs(tg(A.x, A.y) - tg(B.x, B.y)) <= EPS)
        return A.x < B.x;
    return tg(A.x, A.y) < tg(B.x, B.y);
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++)
            scanf("%lf%lf%d", &a[i].x, &a[i].y, &a[i].r);

        int nrd = 0;
        sort(a + 1, a + n + 1, cmp);
        sort(pant + 1, pant + n + 1);
    for(int i = 1; i<n; i++)
        if(abs(pant[i] - pant[i + 1]) < EPS)
            nrd ++;
        nrd = n - nrd;
    for(int i = 1; i<=n; i++)
        printf("%lf %lf %d\n", a[i].x, a[i].y, a[i].r);
}
