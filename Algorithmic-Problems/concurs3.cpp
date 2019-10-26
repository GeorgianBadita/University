#include<fstream>
using namespace std;
int main()
{
    ifstream f("concurs3.in");
    ofstream g("concurs3.out");
    int h,n,i,j,v[100],nr=0,sh,s,nr2=0,v1,x;
    f>>h>>n;
                                                          //a-codul orasului;
    for(i=1;i<=n;i++)                                     //b-codul scolii;
        {f>>v[i]; v1=v[i];                                            //c-codul copilului;
                                        //c) cati din scoala si din orasu ala sunt premianti
            if(h/100==v[i]/100)
            nr++;

            if(h/100==v[i]/100&&(h/10)%10==(v[i]/10)%10)
            nr2++;
            }
        x=0;
            for(j=1;j<=v[i];j++)
            {if(h==v[i])
                x=1;
            }
            if(x==0)
            g<<"Da";
            if(v[1]==h||h==v[i])
            g<<"DA";
            else g<<"NU";
            if(v[i]==h)
            g<<'\n'<<nr+1;
            else g<<'\n'<<nr;
            if(v[i]==h)
            g<<'\n'<<nr2+1;
            else g<<'\n'<<nr2;


            return 0;

}

                                                            //a) Daca e sau nu premiant
                                                            //b)cati din orasu ala sunt premianti
                                                            //c) cati din scoala si din orasu ala sunt premianti                      //c) cati din scoala si din orasu ala sunt premianti

