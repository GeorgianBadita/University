#include <cstdio>
using namespace std;

FILE *f = freopen("bile.in", "r", stdin);
FILE *g = freopen("bile.out", "w", stdout);

int Father[255];

int find_(int x)
{
    while(Father[x])
        x = Father[x];
    return x;
}
int main()
{

}
