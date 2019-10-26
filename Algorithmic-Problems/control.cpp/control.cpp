#include<fstream>
using namespace std;
int x[100];
int main()
{
    ifstream f("control.in");
    ofstream g("control.out");
    int ok,aux,i,n,v[101],ap=0,s=0;
    f>>n;
    for(i=1;i<=n;i++)
        {
            f>>v[i];
        }
        do
        {
          ok=1;
            for(i=1;i<=n-1;i++)
                {
                    if(v[i]>v[i+1])
                        {
                            ok=0;
                            aux=v[i];
                            v[i]=v[i+1];
                            v[i+1]=aux;
                        }
                }
        }while(ok==0);

             for(i=1;i<=n;i++)
                {
                }
}
