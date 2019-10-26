#include <cstdio>
#include <vector>
#include <queue>
#define NMAX 2005
using namespace std;

struct vecin{
    int y, cost;
    vecin (int &y, int &cost)
    {
        this -> y = y;
        this -> cost = cost;
    }
};
vector <vecin> G[NMAX];
queue <int> Q;
bool inqueue[NMAX];
