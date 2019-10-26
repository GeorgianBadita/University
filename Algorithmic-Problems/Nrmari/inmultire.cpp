#include <cstdio>
#include <cstring>
using namespace std;
int a[100], b[100], c[100];
char stringg[100];
void mult_huge(int a[], int b[], int c[])
{
    int T = 0;
    c[0] = a[0] + b[0] - 1;
    for(int i = 1; i<=a[0]; i++)
        for(int j = 1; j<=b[0]; j++)
        c[i + j - 1] += a[i] * b[j];
    for(int i = 1; i<=c[0]; i++)
    {
        T = (c[i] += T)/ 10;
        c[i] %= 10;
    }
    if(T) c[++c[0]] = T;
}
void print(int a[])
{
    for(int i = a[0]; i>=1; i--)
        printf("%d", a[i]);
}
int main()
{
    freopen("nmari.in", "r", stdin);
    freopen("nmari.out", "w", stdout);
    scanf("%s", &stringg);
    int p = 0;
    a[0] = strlen(stringg);
    for(int i = strlen(stringg) - 1; i>=0; i--)
        a[++p] = stringg[i] - '0';

    scanf("%s", &stringg);
    p = 0;
    b[0] = strlen(stringg);
    for(int i = strlen(stringg) - 1; i>=0; i--)
        b[++p] = stringg[i] - '0';
    //print(b);
        mult_huge(a, b, c);
        for(int i = c[0]; i>=1; i--)
        printf("%d", c[i]);
        return 0;
}
