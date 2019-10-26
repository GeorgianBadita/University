#include <fstream>
#include <vector>
#include <deque>
using namespace std;
ifstream f("conex.in");
ofstream g("conex.out");
vector <int> v[1001];
deque <int> q;
bool viz[1001];

void bf(int start)
{
    viz[start] = 1;
    q.push_back(start);
    while(!q.empty())
    {
        int nod = q.front();
        g << nod << ' ';
        for(int i = 0; i<v[nod].size();i++)
                if(!viz[v[nod][i]])
                {
                    viz[v[nod][i]] = 1;
                    q.push_back(v[nod][i]);
                }
                q.pop_front();
    }
}
int main()
{
    int n, m;
    f >> n >> m;
    for(int i = 1; i<=m; i++)
    {
        int x, y;
        f >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bf(1);
    return 0;
}
