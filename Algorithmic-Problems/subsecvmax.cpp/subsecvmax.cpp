# include <fstream>
using namespace std;
int v[100001];
int main()
{
    int nr2=0,n,i,j,pint,ok=0,nr[100],max=0,u,x,maxpint=0,l=1;
    ifstream in("subsecvmax.in");
    ofstream out("subsecvmax.out");
    in>>n;
    for (i=1;i<=n;i++) in>>v[i];
    if (n==1) out<<'1'<<' '<<'1';
    else
    {
    for (i=1;i<=n-1;i++)
    {
        nr[++l]=1;
        pint=i;
        x=i;
        j=i+1;
        while (v[j]>=v[x])
            {
                if (j==n) break;
                x++;
                nr[l]++;
                u=j;
                j++;
            }
            i=x;
        if (nr[l]>max)
            {
                max=nr[l];
                maxpint=pint;
            }

    }
    for(i=1;i<=l;i++)
    {
        if(nr[i]==max) nr2++;
    }
out<<' '<<max<<' '<<nr2;;
            }
return 0;
}
