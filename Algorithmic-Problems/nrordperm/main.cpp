#include <cstdio>
using namespace std;
int p[15];

int fact(int n)
{
    if(n == 0) return 1;
    return n * fact(n - 1);
}
int main()
{
    int n;
    freopen("perm.in", "r", stdin);
    freopen("perm.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i<=n; i++)
        scanf("%d", &p[i]);
        int nr = 0;
    for(int i = 1; i<=n; i++)
    {
        nr += (p[i] - 1) * fact(n - i);
        for(int j = i + 1; j<=n; j++)
            if(p[i] < p[j]) p[j] --;
    }
    printf("%d", nr + 1);
}
