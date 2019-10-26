# include <fstream>
# include <vector>
# include <deque>
# include <cstring>
using namespace std;
FILE *f=freopen("dijkstra.in","r",stdin);
FILE *g=freopen("dijkstra.out","w",stdout);
vector < pair <int, int> > v[50001];
bool inqueue[50001];
deque <int> q;
int dmin[50001];
int n,m;
int INF = 2000000000;
void citire()
{
    int i,x,y,z;
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        v[x].push_back(make_pair(y,z));
    }
}

void dijkstra()
{
    for (int i=1;i<=50000;i++) dmin[i]=INF;
    //memset(dmin, INF, sizeof(dmin));
    memset(inqueue, false, sizeof(inqueue));
    inqueue[1]= true;
    q.push_back(1);
    dmin[1]=0;
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
int main()
{
    citire();
    dijkstra();
    for (int i = 2; i <= n; ++i)
        printf("%d ",( dmin[i] < INF ? dmin[i] :0));
    return 0;
}
