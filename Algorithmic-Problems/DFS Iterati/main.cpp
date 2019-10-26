#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

vector <int> v[1001];
stack <int> stiva;
int sol[1001], n;
void DFS(int start)
{
    stiva.push(start);
    int cnt = 0;
    while(!stiva.empty())
    {
        int node = stiva.top();
        stiva.pop();
        sol[++cnt]=node;
        for(vector<int>::iterator it=v[node].begin() ;it!= v[node].end(); it++)
        {
            stiva.push(*it);
        }
    }
}
int main()
{
    freopen("DFS.in", "r", stdin);
    freopen("DFS.out", "w", stdout);
    int  m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i<=m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
    }
    DFS(1);
    for(int i = 1; i<=n; i++)
        printf("%d ", sol[i]);
    return 0;
}
