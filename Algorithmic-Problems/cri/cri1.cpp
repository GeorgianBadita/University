#include <cstdio>
using namespace std;
int a[501][501],n,m,nb,mb;
int x,y;

void citire()
{ freopen("cri.in","r",stdin);
  scanf("%d%d%d%d",&n,&m,&x,&y);
  int i,j;
  for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
		  scanf("%d",&a[i][j]);
}

int zona1( int &nr)
{ int i,j,s=0,min=2000000000;
  nb=0;
  for(i=x; i>=1;i--)
  { nb++; mb=0;
	  for(j=y;j>=1;j--)
		  { mb++;
		    s=s+a[i][j];
		    if(((nb+mb)%2!=0)&&(a[i][j]<min))
				   min=a[i][j];
          }
  }
  nr=nb*mb;
  if(mb%2==0 && nb%2==0)
	  { nr=nr-1; s=s-min;}

  return s;
}

int zona2( int &nr)
{ int i,j,s=0,min=2000000000;
  nb=0;
  for(i=x; i>=1;i--)
  { nb++; mb=0;
	  for(j=y;j<=m;j++)
		  { mb++;
		    s=s+a[i][j];
		    if(((nb+mb)%2!=0)&&(a[i][j]<min))
				   min=a[i][j];
          }
  }
  nr=nb*mb;
  if(mb%2==0 && nb%2==0)
	  { nr=nr-1; s=s-min;}
return s;
}

int zona3( int &nr)
{ int i,j,s=0,min=2000000000;
  nb=0;
  for(i=x; i<=n;i++)
  { nb++; mb=0;
	  for(j=y;j>=1;j--)
		  { mb++;
		    s=s+a[i][j];
		    if(((nb+mb)%2!=0)&&(a[i][j]<min))
				   min=a[i][j];
          }
  }
  nr=nb*mb;
  if(mb%2==0 && nb%2==0)
	  { nr=nr-1; s=s-min;}
return s;
}

int zona4( int &nr)
{ int i,j,s=0,min=2000000000;nb=0;
  for(i=x; i<=n;i++)
  { nb++; mb=0;
	  for(j=y;j<=m;j++)
		  { mb++;
		    s=s+a[i][j];
		    if(((nb+mb)%2!=0)&&(a[i][j]<min))
				   min=a[i][j];
          }
  }
  nr=nb*mb;
  if((mb%2==0) && (nb%2==0))
	  { nr--; s=s-min;}
return s;
}
int main()
{ int nr,s,k=0,smax=0,ies;
  citire();
  smax=zona1(k);ies=1;
  s=zona2(nr);
  if(s>smax){ smax=s; k=nr;ies=2;}
  else
	  if(s==smax)
		  if(nr<k){k=nr;ies=2;}
  s=zona3(nr);
  if(s>smax){ smax=s; k=nr;ies=3;}
  else
	  if(s==smax)
		  if(nr<k){k=nr;ies=3;}

  s=zona4(nr);
  if(s>smax){ smax=s; k=nr;ies=4;}
  else
	  if(s==smax)
		  if(nr<k){k=nr;ies=4;}
  freopen("cri.out","w",stdout);

  printf("%d %d %d",ies,smax,k);
  return 0;
}

