#include <cstdio>
#include <vector>
#include <deque>
#include <cstring>
#define INF 2*1e9
#define f first
#define s second
#define pb push_back
using namespace std;

FILE *f = freopen("razboi.in", "r", stdin);
FILE *g = freopen("razboi.out", "w", stdout);

vector <pair <int, int> > v[505];
deque <int> q;
vector <int> sol;
bool inqueue[505];
int n, m, dmin[505], start, ind, mins[505];
void read()
{
    int x, y, z;
    scanf("%d%d", &n, &m);
    for(int i = 1; i<=m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        v[x].push_back(make_pair(y, z));
    }
    scanf("%d", &start);
    ind = start;
}

void belman(int start)
{
   for (int i=1;i<=505;i++) dmin[i]=INF;
    //memset(dmin, INF, sizeof(dmin));
    memset(inqueue, false, sizeof(inqueue));
    inqueue[start]= true;
    q.push_back(start);
    dmin[start]=0;
    while (!q.empty())
    {
        int nod=q.front();
        q.pop_front();
        inqueue[nod] = false;
        for (vector <pair <int, int> >::iterator it=v[nod].begin();it!=v[nod].end();it++)
        {
            if (dmin[nod]+it->second < dmin[it->first])
            {
                dmin[it->first] = dmin[nod] + it->second;
                if (!inqueue[it->first])
                {
                    q.push_back(it->first);
                    inqueue[it->first] = true;
                }
            }
        }
    }

}
void type(int v[], int n)
{
    for(int i = 1; i<=n; i++)
        printf("%d ", v[i]);
    printf("\n");
}
inline int maxim(int a, int v[], int k)
{
    return a > v[k]? a : v[k];
}

int main()
{
    read();
    int tmin = -1, ok = 1;
    for(int i = 1; i<=n; i++)
        {

            belman(i);
            tmin = maxim(tmin, dmin, ind);
            //type(dmin, n);

        //printf("%d", tmin);
            if(i != ind)
                if(dmin[ind] == 0 || dmin[ind] == INF)ok = 0;
            //type(dmin, n);
            for(int j = 1; j<=n; j++)
                if(mins[j] < dmin[j])
                    mins[j] = dmin[j];
        }
        printf("%d\n", (ok != 0 ? tmin : 0));
        int ind1 = -1, minn = INF;
        for(int i = 1; i<=n; i++)
            if(minn > mins[i])
            {
                minn = mins[i];
                ind1 = i;
            }
            if(minn != INF && minn != 0)
        printf("%d %d ", ind1, minn);
        else printf("%d", 0);

    return 0;
}
