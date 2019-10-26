#include<fstream>
using namespace std;
int main()
{
    ifstream f("cuburi.in");
    ofstream g("cuburi.out");
    int n,ok,i,l[10001],c[10001],aux,j,h=0,u,gasit,h1=0;
    f>>n;
    for(i=1;i<=n;i++)
    f>>l[i]>>c[i];
    do
    {
        ok=1;
        for(i=1;i<=n-1;i++)
        if(l[i]<l[i+1])
            {
                aux=l[i];
                l[i]=l[i+1];
                l[i+1]=aux;
                aux=c[i];
                c[i]=c[i+1];
                c[i+1]=aux;
                ok=0;
            }
    }while(ok==0);
    h=l[1]; u=1;
    for(i=2;i<=n;i++)
    if(c[i]!=c[u]&&l[i]<l[u])
    {
        h+=l[i];
        u=i;
    }
    gasit=0;//caut un cub de lautra=l[1](care e max) si de culoare diferita
    for(i=2;i<=n;i++)
        if(l[i]==l[1]&&c[i]!=c[1])
            {
                gasit=1; j=i; break;
            }
        else if(l[i]<l[1]) break;
        if(gasit==1)
        {
            //formeaz un nou turn
            h1=l[j]; u=j;
            for(i=j+1; i<=n;i++)
            if(c[j]!=c[u]&&l[j]<l[u])
    {
        h1+=l[j];
        u=j;
    }
        }
        if(h>h1)
        g<<h;
        else g<<h1;
}
