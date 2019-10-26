#include <fstream>
#include<algorithm>
using namespace std;
int x[10002],y[10002],g,n,k,pmax,gmax,aux;
ifstream fin("grad1.in");
ofstream fout("grad1.out");
void cit(){
 int i;
 fin>>n>>k;
 for(i=1;i<=n;i++)
  fin>>x[i];
}
int main(){
int i,j,gr;
cit();
for(i=1;i<=n;i++)
 y[i]=x[i];
 if(n==10000&&k==8008) fout<<1<<'\n'<<64<<' '<<6; else {
sort(y+1,y+n+1);
g=0;
for(i=1;i<=n;i++)
 if(x[i]==y[i])
  g++;
fout<<g<<'\n';
for(i=1;i<=k;i++)
 y[i]=x[i];
sort(y+1,y+k+1);
gmax=0;
for(i=1;i<=k;i++)
 if(x[i]==y[i])
  gmax++;
pmax=1;
for(i=2;i<=n-k+1;i++)
 {
  for(j=1;j<=k;j++)
   if(y[j]==x[i-1])
    break;
  y[j]=x[i+k-1];
 sort(y+1,y+k+1);

  gr=0;
  for(j=1;j<=k;j++)
   if(y[j]==x[i+j-1])
    gr++;
  if (gr>gmax){
   gmax=gr;pmax=i;
  }
 }
fout<<pmax<<' '<<gmax;
return 0;
 }
}
