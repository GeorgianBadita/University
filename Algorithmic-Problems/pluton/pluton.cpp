#include<fstream>
using namespace std;
long nr[4001];
long nrsort[4001];
long n,nrp,nrmax,pmax;
long sortarecifre(long x)
{
 long aux,c,y;

 aux=x;
 y=0;
 for(c=9;c>=0;c--)
 {
  while(x)
  {
   if(x%10==c) y=y*10+x%10;
   x=x/10;
  }
  x=aux;
 }
 return y;
}
int main()
{
    ifstream f("pluton.in");
    ofstream g("pluton.out");
    long i,j,p,aux,max=0;
    f>>n;
                //se citesc din fisierul pluton.in numarul n si
 for(i=1;i<=n;i++)   //elementele vectorului Nr si se completeaza valorile
 {                   //corespunzatoare in vectorul NrSort
  f>>nr[i];
  nrsort[i]=sortarecifre(nr[i]);
 }
    i=1; nrp=nrmax=max=0;
 while(i<=n)
 {
  p=i;
  j=i+1;
  while(j<=n)
  {
   if(nrsort[i]==nrsort[j])
   {
    i++;
    aux=nr[i]; nr[i]=nr[j]; nr[j]=aux;
    aux=nrsort[i]; nrsort[i]=nrsort[j]; nrsort[j]=aux;
   }
   j++;
  }
  i++;
  nrp++;

  if(i-p>max)
  {
   max=i-p;
   nrmax=1;
   pmax=p;
  }
  else
   if(i-p==max) nrmax++;
 }

 g<<nrp<<'\n'<<max<<'\n'<<nrmax<<'\n';
 for(i=pmax;i<pmax+max;i++) g<<nr[i]<<' ';

}
