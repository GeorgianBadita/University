#include <cstdio>
#include <algorithm>
#define N_MAX 120005
#define EPS = 1e-12;
#define x first
#define y second
using namespace std;

typedef pair <double, double> point;
FILE *f = freopen("infasuratoare.in", "r", stdin);
FILE *g = freopen("infasuratoare.out", "w", stdout);

int n;
point Puncte[N_MAX];
bool viz[N_MAX];
int stack_[N_MAX], head;

void read()
{
    scanf("%d ", &n);
    for(int i = 1; i<=n; i++)
        scanf("%d%d", &Puncte[i].x, &Puncte[i].y);
}

double cr_product(point O, point A, point B) {
    return (A.x - O.x) * (B.y - O.y) - (B.x - O.x) * (A.y - O.y);
}

void convex_hull()
{
    sort(Puncte + 1, Puncte + n + 1);
    stack_[1] = 1; stack_[2] = 2; head = 2;
    for(int i = 1, p = 1; i>0; i+= (p = (i == n ? -p : p))){
        if(viz[i]) continue;
        while(head >= 2 && cr_product(Puncte[stack_[head - 1]], Puncte[stack_[head]], Puncte[i]) < EPS)
            vis[stack_[head --]] = false;
        stack_[++head] = i;
        viz[i] = true;
    }

}
