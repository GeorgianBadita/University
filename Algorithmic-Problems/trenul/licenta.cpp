# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;
FILE *f=freopen("licenta.in","r",stdin);
FILE *g=freopen("licenta.out","w",stdout);

/*****************************************************/

struct interval{
    int start;
    int finish;
};

const int N_MAX = 100001;
const int M_MAX = 100001;

int k,n,m,raspuns;
bool ok=false;

interval mihaela[N_MAX];

/*****************************************************/

bool cmp(interval a, interval b)
{
    if (a.start < b.start) return 1;
    if (a.start==b.start)
        if (a.finish < b.finish) return 1;
    return 0;
}

void read()
{
    scanf("%d",&k);
    scanf("%d",&n);
    for (int i=1; i<=n ; i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        mihaela[i]=interval{x,y};
    }

    sort(mihaela+1, mihaela+n+1, cmp);

    //for (int i=1; i<=n ; i++) printf("%d %d\n",mihaela[i].start, mihaela[i].finish);
    scanf("%d",&m);
    for (int i=1 ; i<=m ; i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if (y-x<k) continue;

        for (int i=1; i<=n ; i++)
        {
            if (x > mihaela[i].finish) break;

            int maxim = max(x , mihaela[i].start);
            int minim = min(y , mihaela[i].finish);

            if (minim - maxim >=k)
            {
                if (maxim<raspuns || !raspuns) raspuns=maxim;
            }
        }
    }
}

int main()
{
    read();
    printf("%d %d\n",raspuns, raspuns+k);
    return 0;
}
