#include <fstream>
#include <deque>
using namespace std;
ifstream f("lee.in");
ofstream g("lee.out");
int a[176][176];
struct pct{
    int x, y;
};
deque <pct> q;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int main()
{
    int n, m, k;
    f >> n >> m;
    f >> k;
    for(int i =  1; i<=k; i++)
    {
        int xx, yy;
        f >> xx >> yy;
        a[xx][yy] = -1;
    }
    pct start, stop;
    f >> start.x >> start.y >> stop.x >> stop.y;
    a[start.x][start.y] = 1;
    q.push_back(start);
    while(!q.empty())
    {
        pct k, p;
        k = p = q.front();
        for(int i = 0; i<4; i++)
        {
            if(a[k.x + dx[i]][k.y + dy[i]] == 0)
            {
                a[k.x + dx[i]][k.y + dy[i]] = a[k.x][k.y] + 1;
                k.x += dx[i]; k.y += dy[i];
                q.push_back(k);
                k = p;
            }
        }
    }
}
