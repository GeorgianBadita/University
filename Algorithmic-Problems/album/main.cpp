#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
FILE *f = freopen("album.in", "r", stdin);
FILE *g = freopen("album.out", "w", stdout);
vector <int> V, V1;
int n, nr;
void read()
{
    scanf("%d", &n);
    int x;
    for(int i = 1; i<=n; i++)
    {
        scanf("%d", &x);
        V.push_back(x);
    }
    for(int i = 1; i<=n; i++)
    {
        scanf("%d", &x);
        V1.push_back(x);
    }
}
int verif(vector<int> V, vector <int> V1){
    for(int i = 0; i<V.size(); i++)
        if(V[i] != V1[i]) return 0;
    return 1;
}
int search_for_0(vector <int> v)
{
    for(int i = 0; i<v.size(); i++)
        if(v[i] == 0) return i;
}

void solve()
{
    int pos1, pos = search_for_0(V), savepos;
    bool unsolved = 0;
    while(!unsolved)
    {
        if(verif(V, V1)) break;
        if(V1[pos] == V[pos]) {
            for(int i = 0; i<V.size(); ++i)
            if(V[i] != V1[i]) swap(V[i], V[pos]);
            nr ++;
        }
        for(int i = 0; i<V.size(); i++)
            if(V[i] == V1[pos])
        {
            //unsolved = 0;
             pos1 = i;
            break;
        }
        swap(V[pos], V[pos1]);
        pos = pos1;
        nr ++;
        /*for(int i = 0; i<n; i++)
        printf("%d ", V[i]);
    printf("\n");
    for(int i = 0; i<n; i++)
        printf("%d ", V1[i]);
    printf("\n");
    printf("\n");*/
    }
    printf("%d", nr);

}
int main()
{
    read();
    solve();
    return 0;
}
