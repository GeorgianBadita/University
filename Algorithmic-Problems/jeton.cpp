#include<fstream>
using namespace std;
int main()
{
    ifstream f("jeton.in");
    ofstream g("jeton.out");
    int long long z,c,d,b,y,k,ok,aux,n,m,i,j,min,v[28000],x[28000],max=0,nr1,nr2,a[28000];
      f>>n>>m;
            nr1=n; nr2=m;


      for(i=1;i<=n+m;i++)
      {
          f>>v[i];     x[i]=a[i]=v[i];
      }
      do
      {
          ok=1;
          for(i=1;i<=n+m-1;i++)
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

      for(i=1;i<=n+m;i++)
        {
            if(v[i]==v[i+1])
                {min=v[i];
                  break;
                }
        }

            for(k=n+m;k>=1;k--)
                {
                if(v[k]==v[k-1])
                    {
                        max=v[k];
                        break;
                    }
                }



        g<<min<<' '<<max<<' ';

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
                         g<<1;
                         if(nr2>nr1)
                            g<<2;
                            if(nr1==nr2)
                             g<<0;

                        return 0;
}
