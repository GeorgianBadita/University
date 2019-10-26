#include<fstream>
using namespace std;
int main()
{
    freopen("jeton.in","r",stdin);
	freopen("jeton.out","w",stdout);
    int long long z,c,d,b,y,k,ok,aux,n,m,i,j,min=214700000,v[28000],x[28000],max=0,nr1,nr2,a[28000];
      scanf("%d %d",&a,&b);
            nr1=n; nr2=m;


      for(i=1;i<=n+m;i++)
      {
          f>>v[i];     x[i]=a[i]=v[i];
      }
     sort(v+1,v+n+m);

      for(i=1;i<=n+m;i++)
        {
            if(min>v[i]&&v[i]==v[i+1])
                min=v[i];
                if(max<v[i]&&v[i]==v[i+1])
                    max=v[i];
        }
        printf("%d ",min);
		printf("%d ",max);

                      for(z=1;z<=n;z++)
                        {
                            if(a[z]>=min&&a[z]<=max)
                            nr1--;

                        }

                        for(z=n;z<=m+n;z++)
                        {
                            if(a[z]>=min&&a[z]<=max)
                                nr2--;
                        }
                        if(nr1>nr2)
                         printf("%d" ,1);
                         if(nr2>nr1)
                            printf("%d",2)
                            if(nr1==nr2)
                             printf("%d",0)

                        return 0;
}

