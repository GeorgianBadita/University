#include <cstdio>
#include <cstring>
using namespace std;
int a[100], b[100];
char c[101];
void addhuge(int a[], int b[])
{
    //a -> a + b
    int T = 0;
    if(a[0] < b[0]) a[0] = b[0];
    else b[0] = a[0];
    for(int i = 1; i<= a[0]; i++)
    {
        a[i] += b[i] + T;
        T = a[i] / 10;
        a[i] %= 10;
    }
    if(T) a[++a[0]] = T;
}
int main()
{
    freopen("nmari.in", "r", stdin);
    freopen("nmari.out", "w", stdout);
    scanf("%s", &c);
    //printf("%s", c);
    a[0] = strlen(c);
   // printf("%d", a[0]);
    int p = 0;
    for(int i = strlen(c) - 1; i>=0; i--)
        a[++p] = c[i] - '0';

    scanf("%s", c);
    b[0] = strlen(c);
    p = 0;
    for(int i = strlen(c) - 1; i>=0; i--)
        b[++p] = c[i] - '0';
    addhuge(a, b);
    for(int i = a[0]; i>= 1; i--)
        printf("%d", a[i]);
    return 0;
}
