#include <cstdio>
#include <algorithm>
using namespace std;
FILE *f = freopen("ben.in", "r", stdin);
FILE *g = freopen("ben.out", "w", stdout);
struct timee{
    int start, stop;
}v[30005];

bool cmp(timee a, timee b)
{
    if(a.start == b.start)
        return a.stop < b.stop;
    return a.start < b.start;
}
int a[30005], cate[30005];
int main()
{
    int n, nrc = 0, maxim = -1;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++)
        {
            scanf("%d%d", &v[i]. start, &v[i].stop);
            if(v[i].stop > maxim) maxim = v[i].stop;
            cate[v[i].start] ++;
        }


    sort(v + 1, v + n + 1, cmp);
    last = 1;
    for(int i = 1; i<=n; i++){

        if(v[i].start >= v[last].stop)
        {
            nrc ++;
            last = i;
        }
    }

    printf("%d", n - nrc);
    return 0;
}
