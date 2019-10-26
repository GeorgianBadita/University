#include<cstdio>
using namespace std;

FILE *f=freopen("exp_cstdio.in","r",stdin);
FILE *g=freopen("exp_cstdio.out","w",stdout);
int main()
{

    int x;
    float y;
    long long z;

    scanf("%d%f%lld",&x,&y,&z);
    printf("am citit numerele %d , %f si %lld\n",x,y,z);
    printf("%.3f",y);// afisare cu 3 zecimale,atentie la rotunjiri
    char c;
    getchar(); // ca sa trec la linia urmatoare
    c=getchar();
    if (c>='a'&&c<'z')
     printf ("\n%c este litera mica\n",c);
    else
        printf ("\n%c cu este litera mica\n",c);
    getchar(); // ca sa trec la linia urmatoare
    char v[100];
    gets(v);
    puts(v); printf("sirul este %s\n",v);
    scanf("%s",v);//merge asa daca nu are spatii sau tab, altfel ia pana la primul spatiu
    puts(v);
    printf("sirul este %s",v);
    return 0;


}

