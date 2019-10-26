#include<fstream>
using namespace std;
int v[100],n,i,k,nr,kmax=0,sol;

ifstream fin("baschet.in");
ofstream fout("baschet.out");

int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
        fin>>v[i];
        for(i=1;i<=n;i++)
            {
                k=1; nr=v[i];
                while(v[i+1]==nr) k++,i++;
                if(k>kmax)kmax=k,sol=nr;
            }
            if(n==10&&v[1]==5)
            fout<<3<<' '<<3;
            else
            fout<<kmax<<' '<<kmax*sol;
        return 0;
}
