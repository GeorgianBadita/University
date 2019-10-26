# include <cstdio>
# include <cstring>
# define NMax 5003
# define Nmax 1003
using namespace std;

int a[NMax], ap[Nmax];
int n, Max, nr;

void cool()
{
    int i, j, k, min, max;
    for (i=1; i < n; ++i)
    {
        min = a[i]; max = a[i];
        ap[a[i]] = 1;
        for (j=i+1; j<=n; ++j)
        {
            if (ap[a[j]]) break;
            ap[a[j]] = 1;
            if(a[j] < min) min = a[j];
            if(a[j] > max) max = a[j];
            k = j - i + 1;
            if(max - min == k - 1)
            {
                if (k > Max) Max = k, nr = 1;
                        else if (k == Max) ++nr;
            }
        }
        memset(ap, 0, sizeof(ap));
    }
}
int main()
{
    int i, k, p, Min = 1001, nr_dist = 0;

    freopen ("cool.in", "r", stdin);
    freopen ("cool.out","w", stdout);

    scanf("%d", &p);
    scanf("%d %d", &n, &k);
    for (i=1; i<=n; ++i)
        scanf("%d", &a[i]);

    if (p == 1)
    {   //a
        for (i=1; i<=k; ++i)
        {
            ap[a[i]]++;
            if (a[i] < Min) Min = a[i];
            if (a[i] > Max) Max = a[i];
        }
        for (i=Min; i<=Max; ++i)
            if (ap[i] == 1) ++nr_dist;
        if (nr_dist == k) printf("%d\n", Max);
                     else printf("%d\n", nr_dist);
    }
    else
    {   //b
        cool();
        printf("%d\n%d\n", Max, nr);
    }
    return 0;
}
