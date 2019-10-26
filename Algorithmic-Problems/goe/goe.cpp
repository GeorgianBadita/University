#include<fstream>
#include<cmath>
using namespace std;
ifstream f("goe.in");
ofstream g("goe.out");
long v[121];
int s[121],j;
int RIGHT(int n)
{   int k;
    while(n) {k=n%10; if(k==2||k==4||k==5||k==7) return 0; n/=10;}
    return 1;
}
int main()
{
    int n,p,k,nr,ok,i;
    f>>k>>p>>n;
    nr=0;
    for(i=1;i<=k;i++)
    {
        int aux=i-1; ok=1;
        if(RIGHT(aux)==0) ok=0;
        if(ok) nr+=5;
    }
    g<<nr<<'\n';
    int nrc,d;   nrc=1; d=3; //d reprezinta cate numere palindroame de nrc cifre exista
    while(p>d){p=p-d;nrc++;if(nrc%2) d=d*4;}
    v[1]=1; v[nrc]=1; d=d/3;  p--;
    for(i=2;i<nrc;i++) v[i]=0;
    i=1;
    while(d>0){v[i]=v[nrc-i+1]=v[i]+p/d;p=p%d;d/=4;i++;}
    for(i=1;i<=nrc;i++) {
        if(v[i]==2) v[i]=3;
        else if(v[i]==3) v[i]=8;
    }
    for(i=1;i<=nrc;i++) g<<v[i];
	g<<'\n';
    nrc=log10((double)n)+1;i=nrc;
	while(n>0){s[i]=n%10;n=n/10;i--;}
	i=1;
	if(s[1]==1)
	{
	  i++;
	  while(i<=nrc && s[i]==0)i++;
	}
	if(i==nrc+1)
	{
	   for(j=1;j<=nrc;j++)g<<'9';
	   g<<'\n';
	}
	else
	{
	  g<<'9';
	  if(s[i]>1 && i<nrc && s[i+1]<6 || s[i]==1 && s[i+1]<6 || s[i]!=9)
	  {
	    s[i]--;
	    if(s[i]==2 || s[i]==4 || s[i]==5 || s[i]==7) s[i]--;
	    if(s[i]==4) s[i]=3;
	  }
	  i++;
	  for(;i<=nrc;i++) s[i]=9;
	  for(i=nrc;i>=1;i--)
	  {
	    if(s[i]==6) s[i]=9;
	    g<<s[i];
	  }
	  g<<'\n';
	}
}

