#include<cstdio>
#include<algorithm>
using namespace std;

int a[105],b[105],n,i,j;
float d,e,max;
int main()
{
  freopen ("petrol.in" , "r" , stdin);
  freopen ("petrol.out" , "w" , stdout);
  scanf ("%d",&n);
  scanf ("%f %f",&e,&d);
  for(i=1;i<=n;i++)
   {
	scanf ("%d",&a[i]);
	scanf ("%d",&b[i]);
	}
 float max=0.0;
  if (n==1)
	{
		if (a[1]>b[1]) printf("%.3f\n",float(e/a[1]));
     			  else printf("%.3f\n",float(d/b[1]));
    }
   else
{
	for (i=1;i<n;i++)
		for (j=1;j<=n;j++)
			if (( ( float(e/a[i]) + float(d/b[j]) ) > max) && (i!=j))
				max=(float(e/a[i])+float(d/b[j]));
}

  printf("%.3f\n",max);
  return 0;
}
