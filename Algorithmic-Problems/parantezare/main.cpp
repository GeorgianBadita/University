#include <cstdio>
#include <deque>
using namespace std;

deque <char> deq;

int main()
{
    freopen("par.in", "r", stdin);
    freopen("par.out", "w", stdout);
    int n;
    scanf("%d", &n);
    scanf("\n");
    for(int i = 1; i<=n; i++)
    {
        char c;
        scanf("%c", &c);
        //printf("%c", c);

        if(c == '(') deq.push_back(c);
        else
        {
            char x = deq.back();

            if(!deq.empty() && x == '(')
                deq.pop_back();
            else {printf("NU E CORECT"); return 0;}
        }
    }
    if(deq.empty()) printf("CORECT");
    else printf("NU E CORECT");
    return 0;
}
