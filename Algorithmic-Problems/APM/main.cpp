#include <cstdio>
#include <algorithm>
#include <queue>
#define N_MAX 200001
#define M_MAX 2*N_MAX
using namespace std;

FILE *f = freopen("apm.in", "r", stdin);
FILE *g = freopen("apm.out", "w", stdout);

class vecin{
    public:
    int capat, cost;

    vecin(int capat, int cost)
    {
        this -> capat = capat;
        this -> cost = cost;
    }
};
class muchie{
public:
    int a, b, cost;
    muchie(int a, int b, int cost)
    {
        this -> a = a;
        this -> b = b;
        this -> cost = cost;
    }
    bool operator < (const muchie &mc) const {
        return this -> cost > mc.cost;
    }
};
vector <vecin> G[N_MAX];
priority_queue<muchie>candidate;
vector <muchie> sol;
int n, m;
bool rez[N_MAX];
void read()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i<=n; i++)
    {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        G[x].push_back(vecin(y, c));
        G[y].push_back(vecin(x, c));
    }
}
void init()
{
    rez[1] = 1;
    for(int i = 0; i<G[1].size(); i++)
        candidate.push(muchie(1, G[1][i].capat, G[1][i].cost));
}
int c_sol;
void solve()
{
    init();
        while(!candidate.empty())
        {
            muchie muc = candidate.top();
            candidate.pop();
            if(!(rez[muc.a] && rez[muc.b]))
            {
                sol.push_back(muc);
                c_sol += muc.cost;
                int nod_nou;
                if(!rez[muc.a]) nod_nou = muc.a;
                else nod_nou = muc.b;
                for(int i = 0; i<G[nod_nou].size(); i++)
                    candidate.push(muchie(nod_nou, G[nod_nou][i].capat, G[nod_nou][i].cost));
                rez[nod_nou] = 1;
            }
        }
}
void write()
{
    printf("%d\n%d\n", c_sol, sol.size());
    for(int i = 0; i<sol.size(); i++)
        printf("%d %d\n", sol[i].a, sol[i].b);
}
int main()
{
    read();
    solve();
    write();
    return 0;
}
