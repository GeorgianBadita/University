#include <cstdio>
#include <algorithm>
#define NMAX 16005
#define MMAX 100005
using namespace std;
FILE *f = freopen("zoo.in", "r", stdin);
FILE *g = freopen("zoo.out", "w", stdout);
struct pct{
    int x, y;
}a[NMAX];
struct dreptunghi{
    int sx, sy, dx, dy;
}rec[MMAX];
inline bool cmp(const pct a, const pct b)
{
    if(a.x == b.x) return a.y < b.y;
     return a.x < b.x;
}
int main()
{
    int n, m;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++)
        scanf("%d%d", &a[i].x, &a[i].y);
    scanf("%d", &m);
    for(int i = 1; i<=m; i++)
        scanf("%d%d", &rec[i].sx, &rec[i].sy, &rec[i].dx, &rec[i].dy);
        //sort(a + 1, a + n + 1, cmp);
        for(int i = 1; i<=m; i++)
        {   int nr = 0;
            for(int j = 1; j<=n; j++)
                if(a[j].x >= rec[i].sx && a[j].x <= rec[i].dx && a[j].y >= rec[i].sy && a[j].y <= rec[i].dy)
                    nr ++;
            printf("%d\n", nr);
        }
    return 0;
}
