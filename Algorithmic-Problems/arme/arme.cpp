#include<fstream>
using namespace std;
int main()
{
    ifstream f("arme.in");
    ofstream g("arme.out");
    int n,m,i,v[10001],ok,aux,s=0;
    f>>n>>m;
    for(i=1;i<=n+m;i++)
        {
            f>>v[i];
        }
        do
        {
            ok=1;
            for(i=1;i<=n+m-1;i++)
                {
                    if(v[i]<v[i+1])
                        {
                            ok=0;
                            aux=v[i];
                            v[i]=v[i+1];
                            v[i+1]=aux;
                        }
                }
        }while(ok==0);
            for(i=1;i<=n;i++)
                s+=v[i];
                g<<s;
                return 0;
}
