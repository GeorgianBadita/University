# include <cstdio>
# include <vector>
using namespace std;
//FILE *f=freopen("random.in","r",stdin);
//FILE *g=freopen("random.out","w",stdout);



struct pereche_2{
    int x;
    int y;
};

struct pereche_3{
    int x;
    int y;
    int z;
};

const int N_MAX = 100001;
const int M_MAX = 100001;

int n,m;

int nr_1;
int nr_2;
int nr_3;

vector <int> ordine_comenzi;
vector <int> v1;
vector <pereche_2> v2;
vector <pereche_3> v3;


void read()
{
    scanf("%d %d",&n,&m);

    for (int i=1; i<=m ; i++)
    {
        int x;
        scanf("%d ",&x);
        if (x==1) nr_1++;
        else
        if (x==2) nr_2++;
        else
        if (x==3) nr_3++;
        ordine_comenzi.push_back(x);
    }
}


void solve()
{
    int nr=0;
    for (int i=1 ; i<=nr_3 ; i++)
    {
        v3.push_back(pereche_3{++nr, ++nr, ++nr});
    }

    if (nr_3%2==1)
    {
        nr_1--;
        v1.push_back(++nr);
    }

    for (int i=1; i<=nr_2 ; i++)
    {
        v2.push_back(pereche_2{++nr, ++nr});
    }

    for (int i=1; i<=nr_1 ; i++)
    {
        v1.push_back(++nr);
    }
}

void write()
{
    for (int i=0; i<ordine_comenzi.size() ; i++)
    {
        if (ordine_comenzi[i]==1)
        {
            printf("%d\n", v1.back());
            v1.pop_back();
        }
        else
        if (ordine_comenzi[i]==2)
        {
            printf("%d %d\n", v2.back().x, v2.back().y);
            v2.pop_back();
        }
        else
        if (ordine_comenzi[i]==3)
        {
            printf("%d %d %d\n", v3.back().x, v3.back().y, v3.back().z);
            v3.pop_back();
        }
    }
}
int min()
{
    read();
    solve();
    write();
    return 0;
}
